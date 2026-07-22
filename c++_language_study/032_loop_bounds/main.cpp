#include <iostream>
#include <cmath>

// [a, b]	<=> (a-1, b]
//			<=> [a, b+1)
//			<=> (a-1, b+1)
//
// , a-2, a-1, { a, a+1, ..., b-1, b, } b+1, b+2, 
int num_inin(int a, int b)
{
	return abs(a - b) + 1;

	// |a-b|	= a-b	if a-b>0
	//			= b-a	if a-b<0
	//			= 0		if a-b=0

	if (a > b)			return a - (b - 1); //  a - b + 1
	else if (a < b)		return b - (a - 1); // -a + b + 1
	else				return 1;

	int diff = abs(a - b);
	int num = diff + 1;
	return num;
}

// [a, b)	<=> (a-1, b)
//			<=> [a, b-1]
//			<=> (a-1, b-1]
//
// , a-2, a-1, { a, a+1, ..., b-2, b-1, } b, b+1, 
int num_inex(int a, int b)
{
	return abs(b - 1 - a) + 1;

}

// (a, b]	<=> [a+1, b]
//			<=> (a, b+1)
//			<=> [a+1, b+1)
//
// , a-1, a, { a+1, a+2, ..., b-2, b-1, b, } b+1, b+2, 
int num_exin(int a, int b)
{
	return abs(a + 1 - b) + 1;
}

// (a, b)	<=> [a+1, b)    
//			<=> (a, b-1]
//			<=> [a+1, b-1]
// 
// , a-1, a { a+1, a+2, ..., b-2, b-1, } b, b+1,
int num_exex(int a, int b)
{
	return abs((a+1) - (b-1)) + 1;

	// (a+1) - (b-1)
	// (b-1) - (a+1)
}

//incrementing						i++
//to exclusive arbitrary limit		i<b
//from arbitrary initial point		i=a
void for1(int a, int b)
{
	for (int i = a; i < b; i++);
	//[a, b)
	// incrementing, ascending
	//a-2, a-1, {a, a+1, ..., b-2, b-1,} b, b+1,
	//i after loop : b
}

//decrementing					i--
//to exclusive arbirary limit	i>b
//from arbitrary initial point	i=a
void for2(int a, int b)
{
	for (int i = a; i > b; i--);
	//[a, b) 
	// decrementing, descending, 
	//a+2, a+1, {a, a-1, a-2, ..., b+2, b+1,} b, b-1
	//i after loop : b
}

//incrementing						i++
//upto exclusive arbitrary limit	i<b 
//from zero initial point			i=0
void for3(int b)
{
	for (int i = 0; i < b; i++);
	//[0, b)
	// -2, -1, {0, 1, 2, ..., b-2, b-1,} b, b+1
	// (b-1)-0+1
	// i after loop : b
}

//decrementing								i--
//from inclusive arbitrary initial point	i=b
//to exclusive zero limit					i>0
void for4(int b)
{
	for (int i = b; i > 0; i--);
	// b+2, b+1, {b, b-1, b-2, ..., 3, 2, 1,} 0, -1, -2
	// |1 - b| + 1
	// i after loop : 0
}

void for5(int b)
{
	for (int i = b; i >= 0; i--);
	// .., b+2, b+1, {b, b-1, b-2, .., 2, 1, 0}, -1, -2,..
}

// A smallest/biggest number which makes the condition false
//  when the condition consists of >, the biggest number matters
//  when the condition consists of <, the smallest number matters

// The number consists the part of condition > b / < b
//  a number adjacent to b : {b-1, b+1}
//  an initial number : a
//  [a, b-1], [a, b], [a, b+1]

// < b : increasing access
// > b : decreasing access

// 반복문의 조건식을 참으로 만드는 수의 범위
// 반복문의 조건식을 거짓으로 만드는 수의 범위

// 반복문의 조건식을 참으로 만드는 가장 작은 수
// 반복문의 조건식을 참으로 만드는 가장 큰 수

// 반복문의 조건식을 거짓으로 만드는 가장 작은 수
// 반복문의 조건식을 거짓으로 만드는 가장 큰 수

// {N N N N N N ......  N N N N N N }
// {T T T {INIT, ....., LAST}, F F F}

