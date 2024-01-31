#include "Literator.h"

template class Iterator< Book>;
template<class T>
Iterator<T>::Iterator(node<T>* start) : current(start) {}

template<class T>
T& Iterator<T>::operator*() {
	return current->key;
}

template<class T>
Iterator<T>& Iterator<T>::operator++() {
	current = current->next;
	return *this;
}

template<class T>
bool Iterator<T>::operator!=(const Iterator& other) const {
	return current != other.current;
}
