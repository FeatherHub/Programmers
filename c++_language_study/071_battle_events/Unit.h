#pragma once

#include <string>
#include "UnitStatus.h"

class Unit {
public:
	Unit(std::string name, int hp, int atk);

	void attack(Unit* other);
	
	bool isAlive();

	UnitStatus getUnitStatus() { return UnitStatus(this->_name, this->_hp, this->_atk, this->_id); }

private:
	static int unitId;
	std::string _name;
	int _id;
	int _hp;
	int _atk;
};

