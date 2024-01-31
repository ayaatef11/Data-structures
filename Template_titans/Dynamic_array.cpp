#include "Dynamic_array.h"

template class DynamicArray<Book>;

template<typename T>
DynamicArray<T>::DynamicArray() {
	size = 0;
	capacity = 0;
	arr = new T[capacity];
}

template<typename T>
DynamicArray<T>::~DynamicArray() {
	delete[]arr;
}

template<typename T>
DynamicArray<T>::DynamicArray(T* data, size_t size) : arr(data), size(size) {}


template<typename T>
void DynamicArray<T>::push_front(T val) {
	if (size == capacity) {
		reserve(capacity == 0 ? 1 : capacity * 2);
	}
	for (long long i = size; i > 0; --i) {
		arr[i] = arr[i - 1];//shifting to the right
	}
	size++;
}

template<typename T>
void DynamicArray<T>::Push_back(T val) {
	if (size == capacity) {
		reserve(capacity == 0 ? 1 : capacity * 2);
	}
	arr[size++] = val;
}

template<typename T>
void DynamicArray<T>::push_at(size_t index, T val) {
	if (index >= size) {
		throw std::out_of_range("Invalid index.");
	}
	if (size == capacity) {
		reserve(capacity == 0 ? 1 : capacity * 2);
	}
	for (long long i = size; i > index; --i) {
		arr[i] = arr[i - 1];
	}
	arr[index] = val;
	size++;
}

template<typename T>
size_t DynamicArray<T>::getSize() {
	return size;
}

template<typename T>
void DynamicArray<T>::pop_by_index(long long  index) {
	assert(size > 0);
	copy(arr + index + 1, arr + size, arr + index);
	size--;
}

   template<typename T>
	void DynamicArray<T>::removeBegin() {
		assert(size > 0);
		copy(arr + 1, arr + size, arr);
		size--;
	}

	template<typename T>
	void DynamicArray<T>::removeEnd() {
		assert(size > 0);
		arr[size - 1] = 0;
		size--;

	}

template<typename T>
void DynamicArray<T>::pop(T val) {
	for (long long i = 0; i < size; ++i) {
		if (arr[i] == val) {
			pop_by_index(i);
			break;
		}

	}

}


template<typename T>
T* DynamicArray<T>::Search() {
	string value, attributeName;
	cout << "Enter Attribute name: ";
	cin >> attributeName;
	cout << "\nEnter Attribute value:\n ";
	cin >> value;
	for(MyIterator<T> it = begin(); it != end(); ++it) {
		if (SearchType::checkFound(*it, attributeName, value)) {
			return &(*it);
		}
	}
	return nullptr;
}



template<typename T>
void DynamicArray<T>::sortasc(string attributeName) {
	for (long long i = 0; i < size - 1; ++i) {
		for (long long j = 0; j < size - i - 1; ++j) {
			if (SearchType::getObject(arr[j], attributeName) > SearchType::getObject(arr[j + 1], attributeName)) {
				std::swap(arr[j], arr[j + 1]);
			}
		}
	}
}

template<typename T>
void DynamicArray<T>::sortdesc(string attributeName) {
	for (long long i = 0; i < size - 1; ++i) {
		for (long long j = 0; j < size - i - 1; ++j) {
			if (SearchType::getObject(arr[j], attributeName) < SearchType::getObject(arr[j + 1], attributeName)) {
				std::swap(arr[j], arr[j + 1]);
			}
		}
	}
}
	
         template<typename T>
		void DynamicArray<T>::reserve(long long newCapacity) {
			if (newCapacity > capacity) {
				T* newArr = new T[newCapacity];
				std::copy(arr, arr + size, newArr);
				//delete[] arr;
				arr = newArr;
				capacity = newCapacity;
			}
		}
	
		template<typename T>
		void DynamicArray<T>::reverse() {
			for (long long i = 0; i <= size / 2; ++i) {
				swap(arr[i], arr[size - i - 1]);
			}
		}

		template<typename T>
		void DynamicArray<T>::merge(T* a, long long s) {
			T* merged = new T[size + s];
			for (long long i = 0; i < size; ++i)merged[i] = arr[i];
			long long j = 0;
			for (long long i = size; i < size + s; ++i)merged[i] = a[j++];
			delete[] arr;
			arr = merged;
			size += s;
		}

		template<typename T>
		void DynamicArray<T>::print() {

			for (long long i = 0; i < size; i++) {
				cout << arr[i] << " ";
			}
		}
		template<typename T>
		T DynamicArray<T>::first() const {
			return arr[0];
		}

		template<typename T>
		T& DynamicArray<T>::last() const {
			return arr[size - 1];
		}

		template<typename T>
		MyIterator<T> DynamicArray<T>::begin() { return MyIterator<T>(arr); }

		template<typename T>
		MyIterator<T> DynamicArray<T>::end() { return MyIterator<T>(arr + size); }
