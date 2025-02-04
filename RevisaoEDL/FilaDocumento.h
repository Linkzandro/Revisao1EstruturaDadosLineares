#pragma once
#include <iostream>
#include "fila.h"
#include "documento.h"
#include "No.h"
using namespace std;
class FilaDocumento:public Fila<Documento>
{

public:
	using Fila<Documento>::Fila;

	void InsertDocument(Documento objeto) {
		if (this->top() == nullptr || objeto.getPriority() == "normal") {
			this->Insert(objeto);
			return;
		}

		if (objeto.getPriority() == "urgente") {
			No<Documento>* noNovo = new No<Documento>(objeto);

			if (this->top()->getObject().getPriority()=="normal") {
				noNovo->setNext(this->top());
				this->setHead(noNovo);
			}
			
			No<Documento>* atual = this->top();
			while (atual->getNext() != nullptr) {
				
				if (atual->getObject().getPriority()=="urgente" &&(atual->getNext()==nullptr || atual->getNext()->getObject().getPriority() =="normal")) {
					noNovo->setNext(atual->getNext());
					atual->setNext(noNovo);
					return;
				}
			}
		}
	}

	void displayFila() {
		No<Documento>* atual=this->top();

		while (atual != nullptr) {
			cout << "Nome: " << atual->getObject().getName() << " Prioridade: " << atual->getObject().getPriority() << endl;
			atual = atual->getNext();
		}
	}
};

