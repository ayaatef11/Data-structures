#pragma once
#include<iostream>
using namespace std;
template<class T>
class Ilist {
public:
	virtual size_t getSize() = 0;
	virtual void push_front(T val) = 0;
	virtual void Push_back(T val) = 0;
	virtual void push_at(size_t  index, T val) = 0;
	virtual void pop_by_index(long long   index) = 0;
	virtual void pop(T val) = 0;
	virtual T* Search() = 0;
	virtual void sortasc(string val) = 0;
	virtual void sortdesc(string attributeName) = 0;
	virtual void reverse() = 0;
	virtual void print() = 0;
	virtual T first()const = 0;
	virtual T& last()const = 0;
};
