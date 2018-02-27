#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>

#include "WorkerThread.h"
#include "ImmSocketClient.h"
#include "Utils.h"
#include "PacketHandler.h"
#include "Message.h"
#include "SvrMessageHandler.h"

 
using namespace std;
using namespace ImmSocket;
using namespace ImmSocketService;


int main (void)
{ 
//TODO
	sigset_t sigset;
	sigemptyset (&sigset);
	sigaddset (&sigset, SIGPIPE);
	sigprocmask (SIG_BLOCK, &sigset, NULL);


	CSvrMessageHandler *pMessageHandler = new CSvrMessageHandler();

#ifndef _DEBUG_TCP
	CImmSocketServer server ((char*)"/tmp/imm_socket_sample", pMessageHandler);
#else
	CImmSocketServer server (65000, pMessageHandler);
//	CImmSocketServer server (65000); // debug echo server
//	CImmSocketServer server (65000, pMessageHandler, false); // debug single client

#endif
	server.start();


	sleep (1);
	if (server.isAlive()) {
		while (1) {
			char buf[1024] = {0};
			memset (buf, 0x00, sizeof(buf));
			fgets (buf, sizeof(buf)-1, stdin);
			CUtils::deleteLF (buf);

			if ((strlen(buf) == 1) && (strncmp(buf, "q", strlen(buf)) == 0)) {
				// quit
				break;

			} else if (strlen(buf) > 0) {
				// notify test
				ST_CLIENT_REF ref = server.getClientRef();
				CUtils::CScopedMutex scopedMutex (ref.pMutex);
				CLIENT_TABLE::iterator iter = ref.pTable->begin();
				while (iter != ref.pTable->end()) {
					CImmSocketClient *pClient = iter->second.pInstance;
					if (pClient) {
						_UTL_LOG_I ("send notify fd:[%d] [%s]\n", pClient->getFd(), buf);
						CMessage *pMsg = new CMessage (pClient);
						pMsg->sendNotify (0xee, (uint8_t*)buf, strlen(buf));
						delete pMsg;
						pMsg = NULL;
					}
					iter ++;
				}
			}
		}
	}

	server.syncStop();

	if (pMessageHandler) {
		delete pMessageHandler;
		pMessageHandler = NULL;
	}

	exit (EXIT_SUCCESS);
}