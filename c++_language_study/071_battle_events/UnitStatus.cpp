#include "UnitStatus.h"
#include "Unit.h"
#include <cstdarg>

UnitStatus::UnitStatus(std::string name, int hp, int atk, int id)
	: name(name), hp(hp), atk(atk), id(id) {
}

UnitStatus* UnitStatus::pack(Unit* u1, Unit* u2) {
	return new UnitStatus[2]{ u1->getUnitStatus(), u2->getUnitStatus() };
}

UnitStatus* UnitStatus::pack(Unit* u)
{
	return new UnitStatus[1]{ u->getUnitStatus() };
}
