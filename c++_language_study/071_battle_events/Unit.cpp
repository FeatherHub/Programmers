#include <iostream>

#include "Unit.h"
#include "UnitLogger.h"
#include "UnitStatus.h"
#include "Event.h"

using namespace std;

int Unit::unitId = 0;

Unit::Unit(string name, int hp, int atk)
	: _name(name), _hp(hp), _atk(atk), _id(unitId){
	unitId++;
}

void Unit::attack(Unit * other) {
	UnitLogger::log(LogEvent::beforeAttack, UnitStatus::pack(this, other));

	other->_hp -= this->_atk;

	UnitLogger::log(LogEvent::afterAttack, UnitStatus::pack(other));
}

bool Unit::isAlive() {
	return this->_hp > 0 ? true : false;
}