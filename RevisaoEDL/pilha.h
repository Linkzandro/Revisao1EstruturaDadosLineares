#pragma once
#include "No.h"

template <class T>
class Pilha {
private:
	No<T>* head;

public:
	Pilha() {
		head = nullptr;
	}

	void insert(T objeto) {
		No<T>* no = new No<T>(objeto);

		if (head == nullptr) {
			head = no;
			return;
		}

		no->setNext(head);
		head = no;
	}

	T top() {
		return *head->getObject();
	}

	T pop() {
		T popObj = head->getObject();
		No<T>* temp = head;
		head = temp->getNext();
		delete temp;
		return popObj;
	}

	bool isEmpty() {
		if (head == nullptr) {
			return true;
		}
		return false;
	}
};