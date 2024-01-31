#pragma once
#include<iostream>
#include "IList.h"
#include"SearchType.h"
#include "Literator.h"
using namespace std;
template<class T>
class singly_Linked_list :public  Ilist<T> {
public:
	singly_Linked_list();

	singly_Linked_list(node<T>* newNode);

	void push_front(T val);

	void Push_back(T val);

	void push_at(size_t  index, T val);

	void pop_by_index(long long  index);

	void pop(T val);

	void pop_front();

	T* Search();

	void pop_back();

	void sortasc(string val);

	void sortdesc(string attributeName);

	void reverse();

	void print();

	size_t getSize();

    bool isEmpty(); 

    void clear();

	T first()const;

	T& last()const;

	node<T>& firstNode() const;

	node<T>& lastNode()const;

	Iterator<T> begin();

	Iterator<T> end();

	~singly_Linked_list();

private:

	node<T>& BeforeindexOf(T val);

	node<T>& indexOf(T val);

	node<T>& at(long long  index) const;

	long long search(T val);

	node<T>* head;
	size_t size;
};
