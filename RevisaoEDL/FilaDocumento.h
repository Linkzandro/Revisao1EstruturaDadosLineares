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
            cout<<no->getObject().getPriority()<<"1";
			head=no;
			tail=no;
			return;
		}

        if(no->getObject().getPriority() == "normal"){
            cout<<no->getObject().getPriority()<<"2";
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
			cout<<*(atual);
			while (atual!= nullptr) {
                cout<<no->getObject().getPriority()<<objeto.getName()<<"4";

				if (atual->getObject().getPriority()=="urgente" && atual->getNext()->getObject().getPriority() =="normal") {
                    cout<<no->getObject().getPriority()<<"5";
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

