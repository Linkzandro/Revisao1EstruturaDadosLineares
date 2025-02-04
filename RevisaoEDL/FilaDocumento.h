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
	    No<Documento>* no=new No<Documento>(objeto);
		if (this->top() == nullptr) {
			head=no;
			tail=no;
			return;
		}

        if(no->getObject().getPriority() == "normal"){
            tail->setNext(no);
            tail=no;
            return;

        }
		if (no->getObject().getPriority() == "urgente") {
			if (this->top()->getObject().getPriority()=="normal") {
				no->setNext(this->top());
				head=no;
				return;
			}
			No<Documento>* atual = head;
			while (atual!= nullptr) {
				if (atual->getObject().getPriority()=="urgente" && atual->getNext()->getObject().getPriority() =="normal") {
					no->setNext(atual->getNext());
					atual->setNext(no);
					return;
				}
				atual=atual->getNext();
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

