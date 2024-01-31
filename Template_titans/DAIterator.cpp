#include "DAIterator.h"

   template class MyIterator<Book>;
   template<class T>
   MyIterator<T>::MyIterator(T* ptr) : ptr_(ptr) {}

   template<class T>
	T& MyIterator<T>::operator*() { return *ptr_; }

	template<class T>
	MyIterator<T>& MyIterator<T>::operator++() { ++ptr_; return *this; }

	template<class T>
	MyIterator<T>  MyIterator<T>:: operator++(int) { MyIterator temp = *this; ++ptr_; return temp; }

	template<class T>
	bool MyIterator<T>::operator==(const MyIterator& other) const { return ptr_ == other.ptr_; }

	template<class T>
	bool MyIterator<T>::operator!=(const MyIterator& other) const { return ptr_ != other.ptr_; }

