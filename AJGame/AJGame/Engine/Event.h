#ifndef EVENT_H_
#define EVENT_H_
#include <string>
#define EVENTID std::string

class Event
{
public:
	Event(EVENTID eventId, void* parameter = 0) {
		this->eventId = eventId;
		this->parameter = parameter;
	}
	~Event() {}

	EVENTID GetEvent() { return eventId; }
	void* GetParameter() { return parameter; }

private:
	EVENTID eventId;
	void* parameter;
};

#endif // EVENT_H_

