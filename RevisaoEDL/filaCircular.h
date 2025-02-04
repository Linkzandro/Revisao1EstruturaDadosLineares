#pragma once
#include "No.h"

using namespace std;
template<class T>
class FilaCircular {
private:
	No<T>* head;
	No<T>* tail;
    int maxSize,filaSize;

    void BufferOverwrite(No<T>* no ){
        no->setNext(head->getNext());
        head=no;
        tail->setNext(head);

    }
    void insertTail(No<T>* no) {
		if (head == nullptr) {
			head = no;
			tail = no;

		}
		else {
            //cauda atual muda seu next para o novo no
			tail->setNext(no);
			//novo no passa a ser a cauda
			tail = no;
            //novo no.next passa a ser a cabe�a
			tail->setNext(head);
		}
        filaSize+=1;
	}

public:
	FilaCircular(int MaxSizeEntry) {
		head = nullptr;
		tail = nullptr;
        filaSize=0;
        maxSize=MaxSizeEntry;
	}


    void Inserir(T objeto){
        No<T>* no=new No<T>(objeto);
        if(filaSize<maxSize){
            insertTail(no);
        }else{
            BufferOverwrite(no);
        }
    }


	T pop() {
		T objeto= head->getObject();
		head = head->getNext();
        tail->setNext(head);
        filaSize-=1;
		return objeto;
	}

	No<T>* top() {
		return head;
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
