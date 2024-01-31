#include"Container.h"

template class Container<Ilist<Book>>;  

template <typename T>
Container<Ilist<T>>::Container(string s ) {
	if (s == "DynamicArray")
		container = new DynamicArray<T>();

	else if(s=="Linked_list") container = new singly_Linked_list<T>();
}

template <typename T>
void Container<Ilist<T>>::push_front(T val) {
	container->push_front(val);
}

template <typename T>
void Container<Ilist<T>>::Push_back(T val) {
	container->Push_back(val);
}

template <typename T>
void Container<Ilist<T>>::push_at(size_t index, T val) {
	container->push_at(index, val);
}

template <typename T>
void Container<Ilist<T>>::pop_by_index(long long  index) {
	container->pop_by_index(index);
}

template <typename T>
void Container<Ilist<T>>::pop(T val) {
	container->pop(val);
}

template <typename T>
void Container<Ilist<T>>::sortasc(string val) {//turn into quick sort
	container->sortasc(val);
}

template <typename T>
void Container<Ilist<T>>::sortdesc(string attributeName) {
	container->sortdesc( attributeName);
}


template <typename T>
void Container<Ilist<T>>::reverse() {
	container->reverse();
}


template <typename T>
T* Container<Ilist<T>>::search() {
	return container->Search();
}

template <typename T>
void Container<Ilist<T>>::print() {
	container->print();
}

template<typename T>
T Container<Ilist<T>>::first() const {
	return container->first();
}


template <typename T>
T& Container<Ilist<T>>::last() const{
	return container->last();
}
