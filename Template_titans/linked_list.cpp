#pragma once
#include "linked_list.h"
template class singly_Linked_list<Book>;
  template<class T>
	singly_Linked_list<T> ::singly_Linked_list() {
		head = nullptr;
		size = 0;
	}

	template<class T>
	singly_Linked_list<T>::singly_Linked_list(node<T>* newNode) {
		head = newNode;
		newNode->next = 0;
		size++;
	}

	template<class T>
	void singly_Linked_list<T>::push_front(T val) {
		node<T>* newNode = new node<T>();//there is another node in heap
		newNode->key = val;
		newNode->next = head;
		head = newNode;
		size++;
	}

	template<class T>
	void singly_Linked_list<T>::Push_back(T val) {
		//create a node
		node<T>* newNode = new node<T>();
		newNode->key = val;
		newNode->next = nullptr;
		//loop over elements
		if (head != nullptr) {
			node<T>* pointer = head;
			while (pointer->next) {
				pointer = pointer->next;
			}
			pointer->next = newNode;
		}
		else head = newNode;
		size++;
	}

	template<class T>
	void singly_Linked_list<T>::push_at(size_t  index, T val) {
		node<T>* newNode = new node <T>();
		newNode->key = val;
		node<T>* curr1 = &at(index - 1);
		newNode->next = &at(index);
		curr1->next = newNode;
		size++;

	}

	template<class T>
	void singly_Linked_list<T>::pop_by_index(long long  index) {
		node <T>* curr1 = &at(index - 1);
		node<T>* curr2 = &at(index);
		curr1->next = curr1->next->next;
		delete curr2;
		size--;
	}

	template<class T>
	void singly_Linked_list<T>::pop(T val) {
		node <T>* curr1 = &BeforeindexOf(val);
		node<T>* curr2 = &indexOf(val);
		curr1->next = curr1->next->next;
		delete curr2;
		size--;
	}

	template<class T>
	void singly_Linked_list<T>::pop_front() {
		node<T>* curr = head;
		head = head->next;
		delete curr;
		size--;
	}

	template<class T>
	void singly_Linked_list<T>::pop_back() {
		node<T>* curr = head;
		while (curr->next->next)
			curr = curr->next;
		delete curr->next;
		curr->next = nullptr;
		size--;
	}
	
	template<class T>
	long long singly_Linked_list<T>::search(T val) {
		node<T>* curr = head;
		long long  counter = 0;
		while (curr) {
			if (curr->key == val)
				return counter;
			counter++;
			curr = curr->next;
		}
		return -1;
	}
	

	template<class T>
	void singly_Linked_list<T>::sortasc(string attributeName) {
		node<T>* curr1 = head;
		node<T>* curr2 = head->next;
		while (curr1->next) {
			curr2 = curr1->next;
			while (curr2) {
				if (SearchType::getObject(curr1->key,attributeName) > SearchType::getObject(curr2->key,attributeName))swap(curr1->key, curr2->key);
				curr2 = curr2->next;
			}
			curr1 = curr1->next;
		}
	}

	template<class T>
	void singly_Linked_list<T>::sortdesc(string attributeName) {
		node<T>* curr1 = head;
		node<T>* curr2 = head->next;
		while (curr1->next) {
			curr2 = curr1->next;
			while (curr2) {
				if (SearchType::getObject(curr1->key, attributeName) < SearchType::getObject(curr2->key, attributeName))swap(curr1->key, curr2->key);
				curr2 = curr2->next;
			}
			curr1 = curr1->next;
		}
	}

	template<class T>
	void singly_Linked_list<T>::reverse() {
		node<T>* curr1 = head;
		node<T>* curr2 = head->next;
		head->next = 0;
		while (curr2) {
			curr1 = curr2;
			curr2 = curr2->next;
			curr1->next = head;
			head = curr1;

		}
	}


	template<class T>
	void singly_Linked_list<T>::print() {
		node<T>* curr = head;
		while (curr) {
			cout << curr->key << " ";
			curr = curr->next;
		}
	}

	template<class T>
	size_t singly_Linked_list<T>::getSize() {
		return size;
	}

	template<class T>
	bool singly_Linked_list<T>::isEmpty() {
		return head == nullptr;
	}

	template<class T>
	void singly_Linked_list<T>::clear() {

		while (head) {
			node<T>* curr = head;
			head = head->next;
			delete curr;
		}
		size = 0;
	}

	template<class T>
	node<T>& singly_Linked_list<T>::BeforeindexOf(T val) {
		long long c = search(val);
		c -= 1;
		node <T>* curr = head;
		while (c--) {
			curr = curr->next;
		}
		return *curr;
	}

	template<class T>
	node<T>& singly_Linked_list<T>::indexOf(T val) {
		long long  c = search(val);
		//if (c != -1) {
		node <T>* curr = head;
		while (c--) {
			curr = curr->next;
		}
		return *curr;
		//}
		//return nullptr;
	}

	template<class T>
	node<T>& singly_Linked_list<T>::at(long long  index) const {
		node<T>* curr = head;
		while (index--) {
			curr = curr->next;

		}return *curr;
	}

	template<class T>
	T singly_Linked_list<T>::first()const {
		return head->key;
	}

	template<class T>
	T& singly_Linked_list<T>::last()const {
		node<T> curr = at(size - 1);
		return curr.key;
	}

	template<class T>
	node<T>& singly_Linked_list<T>::firstNode() const {
		return *head;
	}

	template<class T>
	node<T>& singly_Linked_list<T>::lastNode()const {
		node<T>* curr = head;
		while (curr->next)curr = curr->next;
		return *curr;
	}

	template<class T>
	singly_Linked_list<T> ::~singly_Linked_list() {
		clear();
	}

	template<class T>
	T* singly_Linked_list<T>::Search() {
		string value, attributeName;
		cout << "Enter Attribute name: ";
		cin >> attributeName;
		cout << "\nEnter Attribute value:\n ";
		cin >> value;
		for (Iterator<T> it = begin(); it != end(); ++it) {
			if (SearchType::checkFound(*it, attributeName, value)) {
				return &(*it);

			}
			
		}
		return nullptr;
	}
	
	template<class T>
	Iterator<T> singly_Linked_list<T>::begin() {
		return Iterator<T>(head);
	}

	template<class T>
	Iterator<T> singly_Linked_list<T>::end() {
		return Iterator<T>(nullptr);
	}