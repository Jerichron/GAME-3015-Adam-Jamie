#include "EventSystem.h"

EventSystem * EventSystem::Instance()
{
	static EventSystem instance;
	return &instance;
}

bool EventSystem::AlreadyRegisterEvent(EVENTID eventId, Listener * listener)
{
	bool alreadyRegisterEvent = false;

	std::pair<std::multimap<EVENTID, Listener*>::iterator,std::multimap<EVENTID, Listener*>::iterator> range;

	range = data.equal_range(eventId);

	for (std::multimap<EVENTID, Listener*>::iterator it = range.first; it != range.second; it++) {
		if ((*it).second == listener) {

			alreadyRegisterEvent = true;
			break;
		}
	}
	return alreadyRegisterEvent;
}

void EventSystem::DispatchEvent(Event * event)
{
	std::pair<std::multimap<EVENTID, Listener*>::iterator, std::multimap<EVENTID, Listener*>::iterator> range;

	range = data.equal_range(event->GetEvent());

	for (std::multimap<EVENTID, Listener*>::iterator it = range.first; it != range.second; it++) {
		{
			(*it).second->HandleEvent(event);
		}
	}

}



void EventSystem::RegisterEvent(EVENTID eventId, Listener * listener)
{
	if (!listener || AlreadyRegisterEvent(eventId, listener))
	{
		return;
	}
	data.insert(std::make_pair(eventId, listener));
}

void EventSystem::UnregisterEvent(EVENTID eventId, Listener * listener)
{
	std::pair<std::multimap<EVENTID, Listener*>::iterator, std::multimap<EVENTID, Listener*>::iterator> range;

	range = data.equal_range(eventId);

	for (std::multimap<EVENTID, Listener*>::iterator it = range.first; it != range.second; it++) {
		it = data.erase(it);
		break;
	}
		

}

void EventSystem::UnregisterAllEvents(Listener * listener)
{
	std::multimap<EVENTID, Listener*>::iterator it = data.begin();

	while (it != data.end()) {
		if ((*it).second == listener) {
			it = data.erase(it);
		}
		else
		{
			it++;
		}
	}
}

void EventSystem::SendEvent(EVENTID eventId, void * data)
{
	Event newEvent(eventId, data);
	Events.push_back(newEvent);
}

void EventSystem::ProcessEvent(EVENTID eventId, Listener * listener)
{
	while (Events.size()) {
		DispatchEvent(&Events.front());
		Events.pop_front();
	}
}

void EventSystem::ClearEvents()
{
	Events.clear();
}

void EventSystem::Shutdown()
{
	data.clear();
	Events.clear();
}
