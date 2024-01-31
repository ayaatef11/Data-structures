#pragma once
#include"BooK.h"
template<class T>
struct node {
	T key;
	node* next;
	node(const T& value, node* nextNode = nullptr) : key(value), next(nextNode) {}
	node() :key(0), next(0) {}
};
template<class T>
class Iterator {
public:
	Iterator(node<T>* start);

	T& operator*();

	Iterator& operator++();

	bool operator!=(const Iterator& other) const;
private:
	node<T>* current;
};