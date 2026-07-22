#pragma once

#include <vector>
#include <queue>

struct GameEvent;
class Unit;

class GameManager {
public:
	void addUnit(Unit* u);
	void processEvent();
	void getEvent();
private:
	Unit* findUnitById(int unitId);

private:
	std::queue<GameEvent*> m_gameEventQueue;
	std::vector<Unit*> m_units;
};