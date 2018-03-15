#pragma once
#ifndef Messages_h
#define Messages_h

#include <stdio.h>

enum EMessagesType
{
	GetPosition,
	SetPosition,
};
class Messages
{

public:
	int GetDestinationID()
	{
		return m_destinationID;
	}

	void SetDestintionID(int value)
	{
		m_destinationID = value;
	}

	EMessagesType GetMessageType()
	{
		return m_messagesId;
	}

	void SetMessageType(EMessagesType msg)
	{
		m_messagesId = msg;
	}

protected:
	Messages(int destinationID, EMessagesType messagesId)
		:m_destinationID(destinationID),
		m_messagesId(messagesId)
	{}

private:
	int m_destinationID;
	EMessagesType m_messagesId;

};
#endif // !
