#include "Messages.h"

int Messages::GetDestinationID()
{
	return m_destinationID;
}

void Messages::SetDestintionID(int value)
{
	m_destinationID = value;
}

EMessagesType Messages::GetMessageType()
{
	return m_messagesId;
}

void Messages::SetMessageType(EMessagesType msg)
{
}
