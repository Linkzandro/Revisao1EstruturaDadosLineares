#pragma once
#include <iostream>
#include "documento.h"
#include "No.h"
using namespace std;
class FilaDocumento
{
private:
    No<Documento>* head;
    No<Documento>* tail;
public:
	FilaDocumento(){
        head=nullptr;
        tail=nullptr;
	}

	void InsertDocument(Documento objeto) {
	    No<Documento>* no=new No<Documento>(objeto);
		if (head == nullptr) {
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
			if (head->getObject().getPriority()=="normal") {
				no->setNext(head);
				head=no;
				return;
			}
			No<Documento>* atual = head;
			while (atual!= nullptr) {
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
		No<Documento>* atual=head;

		while (atual != nullptr) {
			cout << "Nome: " << atual->getObject().getName() << " Prioridade: " << atual->getObject().getPriority() << endl;
			atual = atual->getNext();
		}
	}
};

