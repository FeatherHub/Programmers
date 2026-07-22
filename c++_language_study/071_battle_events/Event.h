#pragma once

enum class GameEventType {
	attack
};

struct GameEvent {
	GameEventType type;
	int subjectUnitId;
	int objectUnitId;
	GameEvent(GameEventType type, int sId, int oId)
		: type(type), subjectUnitId(sId), objectUnitId(oId) {
	}
};

enum class LogEvent {
	beforeAttack, 
	afterAttack
};