#pragma once
#include "No.h"

using namespace std;
template<class T>
class ListaCircular {
private:
	No<T>* head;
	No<T>* tail;

public:
	ListaCircular() {
		head = nullptr;
		tail = nullptr;
	}

	void insertHead(T objeto) {
		No<T>* no = new No<T>(objeto);
		if (head == nullptr) {
			head = no;
			tail = no;
		}
		else {
            //mudando a cabeça atual
			no->setNext(head);
			head = no;
        //alterando ponteiro da cauda
            tail->setNext(head);
		}
	}

	void insertTail(T objeto) {
		No<T>* no = new No<T>(objeto);
		if (head == nullptr) {
			head = no;
			tail = no;
		}
		else {
            //cauda atual muda seu next para o novo no
			tail->setNext(no);
			//novo no passa a ser a cauda
			tail = no;
            //novo no.next passa a ser a cabeça
			tail.setNext(head);
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

		if(atual==nullptr) return;

		No<T>* anterior = head;
		do {
			if (x == i) {
				anterior->setNext(atual->getNext());
				delete atual;
				return;
			}
			anterior = atual;
			atual = atual->getNext();
			x += 1;
		}while (atual!=head);
		cout << "item fora do escopo da lista!"<<endl;
	}

void Josephus(int steps) {
    if (head == nullptr || steps <= 0) {
        cout << "Lista vazia ou passos inválidos!" << endl;
        return;
    }

    No<T>* atual = head;
    No<T>* anterior = nullptr;
    while (head != tail) {
        for (int i = 1; i < steps; ++i) {
            anterior = atual;
            atual = atual->getNext();
        }

        // Remover o nó atual
        No<T>* temp = atual;

        if (atual == head) {
            head = head->getNext();
            tail->setNext(head);
        } else if (atual == tail) {
            tail = anterior;
            tail->setNext(head);
        } else {
            anterior->setNext(atual->getNext());
        }

        delete temp;

        // Mover para o próximo nó
        atual = anterior->getNext();
    }

}



	void displayAll() {
		No<T>* atual = head;
		if(atual==nullptr) return;

		 do{
			cout << atual->getObject()<<endl;
			atual = atual->getNext();
		}while (atual != head);

		cout << "" << endl;
	}

	bool find(T obj) {
		No<T>* atual = head;
		if(atual==nullptr) return false;

		do{
			if (atual->getObject() == obj) {
				return true;
			}
			atual = atual->getNext();
		}while(atual != head);
		return false;
	}
};
