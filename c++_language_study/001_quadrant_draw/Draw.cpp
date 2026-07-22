#include "Draw.h"
#include <stdio.h>

const char MY_IMAGE = '*';
const char BLANK_IMAGE = ' ';

// range syntax = [a,b)
void Draw(int** buffer, int sideLen, int quadrant, bool leftAligned, bool ascending)
{
	int beginX, beginY, endX, endY;
	beginX = beginY = endX = endY = 0;

	if (quadrant == 1) {
		beginX = sideLen / 2;
		endX = sideLen;
		beginY = 0;
		endY = sideLen / 2;
	}
	else if (quadrant == 2) {
		beginX = 0;
		endX = sideLen / 2;
		beginY = 0;
		endY = sideLen / 2;
	}
	else if (quadrant == 3) {
		beginX = 0;
		endX = sideLen / 2;
		beginY = sideLen / 2;
		endY = sideLen;
	} 
	else if (quadrant == 4) {
		beginX = sideLen / 2;
		endX = sideLen;
		beginY = sideLen / 2;
		endY = sideLen;
	}
	else {
		printf("quadrant param error \n");
		return;
	}

	if (leftAligned && ascending) {
		DrawLeftAlignedAscending(buffer, beginX, beginY, endX, endY);
	} 
	else if (leftAligned && !ascending) {
		DrawLeftAlignedDescending(buffer, beginX, beginY, endX, endY);
	} 
	else if (!leftAligned && ascending) {
		DrawRightAlignedAscending(buffer, beginX, beginY, endX, endY);
	}
	else if (!leftAligned && !ascending) {
		DrawRightAlignedDescending(buffer, beginX, beginY, endX, endY);
	}
	else {

	}
}

void DrawLeftAlignedAscending(int** buffer, int beginX, int beginY, int endX, int endY)
{
	int imageCnt = 0;

	for (int y = 0; y < endY - beginY; y++)
	{
		for (int x = 0; x < imageCnt; x++)
		{
	//		if (beginX + x >= endX) break;

			buffer[beginY + y][beginX + x] = MY_IMAGE;
		}
		imageCnt++;
	}

	//for (int row = beginY; row < endY; row++)
	//{
	//	for (int col = beginX; col < endX && col < beginX + imageCnt; col++)
	//	{
	//		buffer[row][col] = MY_IMAGE;
	//	}
	//	imageCnt++;
	//}
}

void DrawLeftAlignedDescending(int** buffer, int beginX, int beginY, int endX, int endY)
{
	int imageCnt = endX - beginX;

	for (int y = 0; y < endY - beginY; y++)
	{
		for (int x = 0; x < imageCnt; x++)
		{
	//		if (beginX + x >= endX) break;

			buffer[beginY+y][beginX+x] = MY_IMAGE;
		}
		imageCnt--;
	}

	//for (int row = beginY; row < endY; row++)
	//{
	//	for (int col = beginX; col < endX && col < beginX + imageCnt; col++)
	//	{
	//		buffer[row][col] = MY_IMAGE;
	//	}
	//	imageCnt--;
	//}
}

void DrawRightAlignedAscending(int** buffer, int beginX, int beginY, int endX, int endY)
{
	int blankCnt = endX - beginX;

	for (int y = 0; y < endY - beginY; y++)
	{
		for (int x = 0; x < blankCnt; x++)
		{
			buffer[beginY+y][beginX+x] = BLANK_IMAGE;
		}
		for (int x = 0; x < endX - beginX - blankCnt; x++)
		{
			buffer[beginY + y][blankCnt + beginX + x] = MY_IMAGE;
		}
		//for (int x = blankCnt; x < endX - beginX; x++)
		//{
		//	buffer[beginY+y][beginX+x] = MY_IMAGE;
		//}
		blankCnt--;
	}

	//for (int row = beginY; row < endY; row++)
	//{
	//	for (int col = beginX; col < endX && col < beginX + blankCnt; col++)
	//	{
	//		buffer[row][col] = BLANK_IMAGE;
	//	}
	//	for (int col = beginX + blankCnt; col < endX; col++)
	//	{
	//		buffer[row][col] = MY_IMAGE;
	//	}
	//	blankCnt--;
	//}
}

void DrawRightAlignedDescending(int** buffer, int beginX, int beginY, int endX, int endY)
{
	int blankCnt = 0;
	for (int y = 0; y < endY - beginY; y++)
	{
		for (int x = 0; x < blankCnt; x++)
		{
			buffer[beginY+y][beginX+x] = BLANK_IMAGE;
		}
		for (int x = blankCnt; x < endX - beginX; x++)
		{
			buffer[beginY+y][beginX+x] = MY_IMAGE;
		}
		blankCnt++;
	}

	//for (int row = beginY; row < endY; row++)
	//{
	//	for (int col = beginX; col < endX && col < beginX + blankCnt; col++)
	//	{
	//		buffer[row][col] = BLANK_IMAGE;
	//	}
	//	for (int col = beginX + blankCnt; col < endX; col++)
	//	{
	//		buffer[row][col] = MY_IMAGE;
	//	}
	//	blankCnt++;
	//}
}