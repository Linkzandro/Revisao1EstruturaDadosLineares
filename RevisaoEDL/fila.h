#pragma once
#include "No.h"
#include <iostream>

using namespace std;
template<class T>
class Fila {
protected:
	No<T>* head;
	No<T>* tail;

public:
	Fila() {
		head = nullptr;
		tail = nullptr;
	}

	void Insert(T objeto) {
		No<T>* no = new No<T>(objeto);
		if (head == nullptr) {
			head = no;
			tail = no;
			return;
		}

		tail->setNext(no);
		tail = no;
	}

	T pop() {
		T objeto= head->getObject();
		head = head->getNext();
		return objeto;
	}

	No<T>* top() {
		return head;
	}

	void displayall() {
		No<T>* atual = head;
		while (atual != nullptr) {
			cout << atual->getObject()<<endl;
			atual = atual->getNext();
		}

	}

protected:
	void setHead(No<T>* h) {
		h->setNext(head);
		head = h;
	}
};
