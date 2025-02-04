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

	//função que recebe um nó referencia e um nó para inserir, faz o trabalho de incluir  o nó inserir entre o referencia e o referencia.next
	void insertBetween(NoDuplo<T>* noReferencia, NoDuplo<T>* noInsercao) {


		//ligando no de inserção
		noInsercao->setNext(noReferencia->getNext());
		noInsercao->setPrevious(noReferencia);

		//pegando o próximo no de "noReferencia" e ajustando seu ponteiro anterior para o no inserido
		if (noReferencia->getNext() != nullptr) {
			noReferencia->getNext()->setPrevious(noInsercao);
		}

		//mudando o next do noReferencia
		noReferencia->setNext(noInsercao);
	}

	void insertTail(T objeto) {
		NoDuplo<T>* no = new NoDuplo<T>(objeto);
		if (head == nullptr) {
			head = no;
			tail = no;
		}
		else {
			tail->setNext(no);
			tail = no;
		}
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

public:


	ListaDupla() {
		head = nullptr;
		tail = nullptr;
	}

	void InserCrescente(T objeto) {
		NoDuplo<T>* no = new NoDuplo<T>(objeto);
		if (head == nullptr || head->getObject()>objeto) {

			head = no;
			tail = nullptr;
			return;
		}

		
		NoDuplo<T>* atual =head;

		while (atual != nullptr) {
			if (atual->getObject() < objeto && (atual->getNext() == nullptr || atual->getNext()->getObject() > objeto )) {
					insertBetween(atual, no);
					return;
			}
			atual = atual->getNext();
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

