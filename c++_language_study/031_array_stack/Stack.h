#pragma once
#include <stdio.h>

template <typename T>
class Stack
{
public:
	Stack(int = 10);
	~Stack();
	T pop();
	T push(T);
	bool empty();
private:
	void increase(int = 2);
	void copy(T*, const T*, int);
	bool full();
private:
	static const int EMPTY_STACK_VALUE;
	int cap;
	int sp;
	T* buffer;
};

template <typename T>
const int Stack<T>::EMPTY_STACK_VALUE = 0;

template <typename T>
Stack<T>::Stack(int cap)
{
	sp = EMPTY_STACK_VALUE;
	buffer = new T[this->cap];
}

template <typename T>
Stack<T>::~Stack()
{
	if (buffer == nullptr)
		return;

	delete[] buffer;
	buffer = nullptr;
}

template <typename T>
T Stack<T>::pop()
{
	return buffer[--sp];
}

template <typename T>
T Stack<T>::push(T v)
{
	if (full())
		increase();

	buffer[sp++] = v;

	return v;
}

template <typename T>
bool Stack<T>::empty()
{
	return sp == EMPTY_STACK_VALUE ? true : false;
}

template <typename T>
bool Stack<T>::full()
{
	return sp == cap ? true : false;
}

template <typename T>
void Stack<T>::increase(int ratio)
{
	static int callcnt = 0;

	printf("increase (%d) \n", ++callcnt);

	ratio = ratio <= 2 ? 2 : ratio;

	T* newBuffer = new T[cap * ratio];
	copy(newBuffer, buffer, cap);

	delete[] buffer;
	buffer = newBuffer;
	cap *= ratio;
}

template <typename T>
void Stack<T>::copy(T* dst, const T* src, int n)
{
	for (; n > 0; n--)
		*dst++ = *src++;
}
