#include <iostream>

#include "GameManager.h"
#include "Unit.h"
#include "Event.h"

using namespace std;

void GameManager::addUnit(Unit* u)
{
	m_units.push_back(u);
}

void GameManager::processEvent()
{
	if (m_gameEventQueue.empty()) {
		return;
	}

	GameEvent* ge = m_gameEventQueue.front();
	m_gameEventQueue.pop();

	switch (ge->type)
	{
	case GameEventType::attack: 
	{
		Unit* subjectUnit = findUnitById(ge->subjectUnitId);
		Unit* objectUnit = findUnitById(ge->objectUnitId);

		if (subjectUnit != nullptr && objectUnit != nullptr) {
			subjectUnit->attack(objectUnit);
		}

		break;
	}
	default: break;
	}

}

void GameManager::getEvent()
{
	string msg;
	cout << "type of event: ";
	cin >> msg;

	GameEventType type;
	int subjectUnitId = 0;
	int objectUnitId = 0;

	if (msg == "attack") {
		type = GameEventType::attack;
		cout << "subject unit id: ";
		cin >> subjectUnitId;
		cout << "object unit id: ";
		cin >> objectUnitId;
		GameEvent* gameEvent = new GameEvent{type, subjectUnitId, objectUnitId};
		m_gameEventQueue.push(gameEvent);
	}
}

Unit* GameManager::findUnitById(int unitId)
{
	vector<Unit*>::iterator it;
	
	it = find_if(m_units.begin(), m_units.end(), [unitId](Unit* u) {
			return u->getUnitStatus().id == unitId;
		});

	return it != m_units.end() ? *it : nullptr;
}
