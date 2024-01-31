#pragma once
#include "BooK.h"
template<class T>
class MyIterator {
public:
	MyIterator(T* ptr);

	T& operator*();

	MyIterator<T>& operator++();

	MyIterator<T>   operator++(int);

	bool operator==(const MyIterator& other) const;

	bool operator!=(const MyIterator& other) const;
private:
	T* ptr_;
};
