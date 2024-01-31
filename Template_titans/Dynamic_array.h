//create iterator for the linked list
#pragma once
#include<iostream>
#include <cassert>
#include <stdexcept>
#include<algorithm>
#include "IList.h"
#include "DAIterator.h"
#include "SearchType.h"
using namespace std;
template<class T>
class DynamicArray :public Ilist<T> {
public:
	DynamicArray();

	~DynamicArray();

	DynamicArray(T* data, size_t size);

	void push_front(T val);

	void Push_back(T val);

	void push_at(size_t index, T val);

	size_t getSize();

	void pop_by_index(long long index);

	void pop(T val);

	T* Search();

	void sortasc(string attributeName);

	void removeBegin();

	void removeEnd();

	void sortdesc(string attributeName);

	private:

		void reserve(long long newCapacity);
	public:
		void reverse();

		void merge(T* a, long long s);

		void print();

		T first() const;

		T& last() const;

		MyIterator<T> begin();

		MyIterator<T> end();
private:

	T* arr;
	size_t  size;
	size_t  capacity;
};

