#pragma once

#include <string>
class Unit;

struct UnitStatus {
	UnitStatus(std::string name, int hp, int atk, int id);

	static UnitStatus* pack(Unit* u);
	static UnitStatus* pack(Unit* u1, Unit* u2);
	std::string name;
	int hp;
	int atk;
	int id;
};