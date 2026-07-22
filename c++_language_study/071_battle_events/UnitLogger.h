#pragma once

#include <string>
#include "Event.h"

class UnitStatus;

class UnitLogger {
public:
	static void log(LogEvent e, UnitStatus* usVec);

private:
	static std::string logBeforeAttack(UnitStatus* usVec);
	static std::string logAfterAttack(UnitStatus* usVec);

	static std::string buildString(UnitStatus* u);
};