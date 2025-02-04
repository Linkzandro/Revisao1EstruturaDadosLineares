#pragma once
#include "No.h"

using namespace std;
template<class T>
class ListaSimples {
private:
	No<T>* head;
	No<T>* tail;

public:
	ListaSimples() {
		head = nullptr;
		tail = nullptr;
	}

	void insertHead(T objeto) {
		No<T>* no = new No<T>(objeto);
		if (head == nullptr) {
			head = no;
			tail = nullptr;
		}
		else {
			no->setNext(head);
			head = no;
		}
	}

	void insertTail(T objeto) {
		No<T>* no = new No<T>(objeto);
		if (head == nullptr) {
			head = no;
			tail = nullptr;
		}
		else {
			tail->setNext(no);
			tail = no;
		}
	}

	void removeAt(int i) {
		
		if (i == 0) {
			No<T>* temp = head;
			head = temp->getNext();
			delete temp;
			return;
		}
		int x = 0;
		No<T>* atual = head;
		No<T>* anterior = head;
		while (atual != nullptr) {
			if (x == i) {
				anterior->setNext(atual->getNext());
				delete atual;
				return;
			}
			anterior = atual;
			atual = atual->getNext();
			x += 1;
		}
		cout << "item fora do escopo da lista!"<<endl;
	}

	void removeDuplicate() {
		No<T>* atual = head;

		//dois whiles, o segundo pega o ponto atual do primeiro e verifica os itens que vem depois dele, verificando se 
		//tem algum igual
		while (atual != nullptr && atual->getNext()!=nullptr) {
			No<T>* anterior = atual;
			No<T>* proximo = atual->getNext();
			while (proximo != nullptr) {
				if (atual->getObject() == proximo->getObject()) {
					anterior->setNext(proximo->getNext());
					delete proximo;
					proximo = anterior->getNext();
				}
				else {
					anterior = proximo;
					proximo = proximo->getNext();
				}
			}
			atual = atual->getNext();
		}
		
	}
	void displayAll() {
		No<T>* atual = head;
		while (atual != nullptr) {
			cout << atual->getObject();
			atual = atual->getNext();
		}
		cout << "" << endl;
	}

	bool find(T obj) {
		No<T>* atual = head;

		while (atual != nullptr) {
			if (atual->getObject() == obj) {
				return true;
			}
			atual = atual->getNext();
		}
		return false;
	}
};