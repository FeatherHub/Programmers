#include "UnitLogger.h"
#include "UnitStatus.h"

#include <iostream>

using namespace std;

void UnitLogger::log(LogEvent e, UnitStatus* usVec) {
	string msg;
	
	switch (e)
	{
	case LogEvent::beforeAttack:	msg = logBeforeAttack(usVec) + "\t"; break;
	case LogEvent::afterAttack:	msg = logAfterAttack(usVec) + "\n"; break;
	default: break;
	}
	
	cout << msg;

	delete[] usVec;
}

string UnitLogger::logBeforeAttack(UnitStatus* usVec) {
	return buildString(&usVec[0]) + " attacks " + buildString(&usVec[1]);
}

string UnitLogger::logAfterAttack(UnitStatus* usVec) {
	return "After attack: " + buildString(&usVec[0]);
}

string UnitLogger::buildString(UnitStatus* u) {
	return u->name + to_string(u->id) + "(HP:" + to_string(u->hp) + " ATK:" + to_string(u->atk) + ")";
}
