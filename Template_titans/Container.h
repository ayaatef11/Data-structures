#pragma once
#include "Dynamic_array.h"
#include "linked_list.h"
#include "BooK.h"
#include <iostream>
using namespace std;
template <typename T>
class Container;
template <typename T>
class Container<Ilist<T>> {
public:
	Container(string s = "DynamicArray");
	void push_front(T val);

	void Push_back(T val);

	void push_at(size_t index, T val);

	void pop_by_index(long long  index);

	void pop(T val);

	void sortasc(string val);

	void sortdesc(string attributeName);

	void reverse();

	T* search();

	void print();

	T first()const;

	T& last()const;
private:
	Ilist<T>* container;
};


