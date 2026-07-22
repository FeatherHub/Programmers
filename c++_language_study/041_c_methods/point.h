#pragma once

typedef struct point {
	int x;
	int y;

	struct point(*add)(struct point);
	void(*print)(void);
} point;

point make_point(int x, int y);

void* this;