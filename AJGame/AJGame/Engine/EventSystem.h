#ifndef EVENTSYSTEM_H_
#define EVENTSYSTEM_H_
#include "Listener.h"
#include "Event.h"

#include <map>
#include <list>

class EventSystem
{
private:
	std::multimap<EVENTID, Listener*> data;
	std::list<Event> Events;

	EventSystem() {}
	~EventSystem() {}
	EventSystem(const EventSystem& rhs) {};


public:
	static EventSystem* Instance();
	bool AlreadyRegisterEvent(EVENTID eventId, Listener* listener);
	void DispatchEvent(Event* event);

	void RegisterEvent(EVENTID eventId, Listener* listener);
	void UnregisterEvent(EVENTID eventId, Listener* listener);
	void UnregisterAllEvents(Listener* listener);
	void SendEvent(EVENTID eventId, void* data = 0);
	void ProcessEvent();
	void ClearEvents();
	void Shutdown();
};


#endif // EVENTSYSTEM_H_

