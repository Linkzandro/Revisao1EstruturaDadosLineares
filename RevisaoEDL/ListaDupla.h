#pragma once
#include "NoDuplo.h"
template<class T>
class ListaDupla
{
private:
	NoDuplo<T>* head;
	NoDuplo<T>* tail;

	void removeNo(NoDuplo<T>* no) {
		if (no->getPrevious() != nullptr) {
			no->getPrevious()->setNext(no->getNext());
		}
		else {
			head = no->getNext();
		}
		if (no->getNext() != nullptr) {
			no->getNext()->setPrevious(no->getPrevious());
		}
		else {
			head = no->getPrevious();
		}
		delete no;
	}

public:
	ListaDupla() {
		head = nullptr;
		tail = nullptr;
	}

	void insertHead(T objeto) {
		NoDuplo<T>* no = new NoDuplo<T>(objeto);
		if (head == nullptr) {
			head = no;
			tail = no;
		}
		else {
			no->setNext(head);
			head = no;
		}
	}

	void insertTail(T objeto) {
		NoDuplo<T>* no = new NoDuplo<T>(objeto);
		if (head == nullptr) {
			head = no;
			tail = no;
		}
		else {
			tail->setPrevious(no);
			tail = no;
		}
	}

	void removeAt(int i) {

		if (i == 0) {
			removeNo(head);
			return;
		}

		int x = 0;
		NoDuplo<T>* atual = head;
		while (atual != nullptr) {
			if (x == i) {
				removeNo(atual);
				return;
			}
			atual = atual->getNext();
			x += 1;
		}
		cout << "item fora do escopo da lista!" << endl;
	}

	void removeDuplicate() {
		NoDuplo<T>* atual = head;

		//dois whiles, o segundo pega o ponto atual do primeiro e verifica os itens que vem depois dele, verificando se 
		//tem algum igual
		while (atual != nullptr && atual->getNext() != nullptr) {
			NoDuplo<T>* proximo = atual->getNext();
			while (proximo != nullptr) {
				if (atual->getObject() == proximo->getObject()) {
					NoDuplo<T>* temp = proximo;
					proximo = proximo->getNext();
					removeNo(temp);
				}
				else {
					proximo = proximo->getNext();
				}
			}
			atual = atual->getNext();
		}

	}
	void displayAll() {
		NoDuplo<T>* atual = head;
		while (atual != nullptr) {
			cout << atual->getObject();
			atual = atual->getNext();
		}
		cout << "" << endl;
	}

	bool find(T obj) {
		NoDuplo<T>* atual = head;

		while (atual != nullptr) {
			if (atual->getObject() == obj) {
				return true;
			}
			atual = atual->getNext();
		}
		return false;
	}
};

