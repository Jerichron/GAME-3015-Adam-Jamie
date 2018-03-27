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
	int GetDestinationID();


	void SetDestintionID(int value);


	EMessagesType GetMessageType();


	void SetMessageType(EMessagesType msg);


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
