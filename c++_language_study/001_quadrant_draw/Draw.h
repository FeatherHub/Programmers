#pragma once

void Draw(int** buffer, int sideLen, int quadrant, bool leftAligned, bool ascending);

void DrawLeftAlignedDescending(int** buffer, int beginX, int beginY, int endX, int endY);
void DrawRightAlignedDescending(int** buffer, int beginX, int beginY, int endX, int endY);
void DrawLeftAlignedAscending(int** buffer, int beginX, int beginY, int endX, int endY);
void DrawRightAlignedAscending(int** buffer, int beginX, int beginY, int endX, int endY);
