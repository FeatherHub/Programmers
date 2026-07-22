#pragma once

template <typename T>
class Vector
{
	T* _elem;
	size_t _size;

public:
	Vector();
	~Vector();
	T& operator[](int idx);
	size_t size();
};

template <typename T>
inline Vector<T>::Vector() : _size(10), _elem(new T[10])
{
}

template<typename T>
inline Vector<T>::~Vector()
{
	delete[] _elem;
}

template<typename T>
inline T& Vector<T>::operator[](int idx)
{
	return _elem[idx];
}

template<typename T>
inline size_t Vector<T>::size()
{
	return _size;
}

