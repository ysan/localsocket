#ifndef _SVR_MESSAGE_HANDLER_H_
#define _SVR_MESSAGE_HANDLER_H_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>

#include "ImmSocketService.h"

using namespace std;
using namespace ImmSocketService;


class CSvrMessageHandler : public CPacketHandler
{
public:
	explicit CSvrMessageHandler (int threadPoolNum);
	virtual ~CSvrMessageHandler (void);

private:
	void onHandleRequest (CRequestMessage *pRequestMsg);
	void onHandleReply (CReplyMessage *pReplyMsg);
	void onHandleNotify (CNotifyMessage *pNotifyMsg);


};

#endif
