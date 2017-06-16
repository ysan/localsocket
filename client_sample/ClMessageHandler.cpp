#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#include "Utils.h"
#include "PacketHandler.h"
#include "Message.h"
#include "ClMessageHandler.h"


CClMessageHandler::CClMessageHandler (void)
{
}

CClMessageHandler::~CClMessageHandler (void)
{
}

void CClMessageHandler::onHandleRequest (CMessage *pMsg)
{
	_UTL_LOG_I ("%s\n", __PRETTY_FUNCTION__);


	_UTL_LOG_I ("id[%d] command[%d]\n", (int)pMsg->getId(), (int)pMsg->getCommand());

	if (pMsg->getDataSize() > 0) {
		_UTL_LOG_I ("requestData [%s]\n", (char*)(pMsg->getData()));
	}

}

void CClMessageHandler::onHandleReply (CMessage *pMsg)
{
	_UTL_LOG_I ("%s\n", __PRETTY_FUNCTION__);


	_UTL_LOG_I ("id[%d] command[%d] %s\n", (int)pMsg->getId(), (int)pMsg->getCommand(), pMsg->isReplyResultOK() ? "reply_ok" : "reply_ng");

	if (pMsg->getDataSize() > 0) {
		_UTL_LOG_I ("replyData [%s]\n", (char*)(pMsg->getData()));
	}


}

void CClMessageHandler::onHandleNotify (CMessage *pMsg)
{
	_UTL_LOG_I ("%s\n", __PRETTY_FUNCTION__);


	_UTL_LOG_I ("id[%d] command[%d]\n", (int)pMsg->getId(), (int)pMsg->getCommand());

	if (pMsg->getDataSize() > 0) {
		_UTL_LOG_I ("notifyData [%s]\n", (char*)(pMsg->getData()));
	}


}
