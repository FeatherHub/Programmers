#pragma once

template <typename T>
class Array
{
public:
	Array(int = DEFAULT_CAP);
	~Array();
	T& operator[](int);
	int size();
	T& at(int);

private:
	void increase(int);
	void copy(T*, const T*, int);
	void dealloc(T*);

private:
	T* _buffer;
	unsigned int _cap;

private:
	const static int DEFAULT_CAP = 10;
};

template<typename T>
inline Array<T>::Array(int cap)
{
	_cap = cap;
	_buffer = new T[_cap];
}

template<typename T>
inline Array<T>::~Array()
{
	dealloc(_buffer);
}

template<typename T>
inline T& Array<T>::operator[](int i)
{
	return at(i);
}

template<typename T>
inline int Array<T>::size()
{
	return _cap * sizeof(T);
}

template<typename T>
inline T& Array<T>::at(int i)
{
	if (i > _cap - 1)
		increase(i / _cap + 1);

	return _buffer[i];
}

template<typename T>
inline void Array<T>::increase(int rat)
{
	T* newBuffer = new T[_cap * rat];
	copy(newBuffer, _buffer, _cap);
	dealloc(_buffer);
	_buffer = newBuffer;
	_cap *= rat;
}

template<typename T>
inline void Array<T>::copy(T* dst, const T* src, int n)
{
	for (; n > 0; n--)
		*dst++ = *src++;
}

template<typename T>
inline void Array<T>::dealloc(T* t)
{
	if (t != nullptr)
		delete[] t;
}
