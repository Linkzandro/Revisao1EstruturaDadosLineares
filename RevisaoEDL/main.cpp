#include <iostream>
#include "ListaSimples.h"
#include "ListaDupla.h"
#include "pilha.h"

using namespace std;


void VerificarListaSimples() {
	ListaSimples<string>* lista = new ListaSimples<string>();
	lista->insertHead("l");
	lista->insertHead("o");
	lista->insertTail("a");
	lista->insertTail("!");
	lista->insertTail("!");
	lista->insertTail("!");
	lista->insertTail("a");
	lista->displayAll();
	cout << lista->find("!") << endl;
	lista->removeAt(3);
	lista->displayAll();
	lista->removeDuplicate();
	lista->displayAll();
}
void VerificarListaDupla() {
	ListaDupla<int>* lista = new ListaDupla<int>();
	lista->InserCrescente(1);
	lista->InserCrescente(3);
	lista->InserCrescente(2);
	lista->InserCrescente(9);
	lista->InserCrescente(4);
	lista->displayAll();
}

void ReverterFrase() {
	Pilha<char>* p = new Pilha<char>();
	cout << "indique uma frase para ser invertida ";
	string frase;
	cin >> frase;

	for (char letra : frase) {
		p->insert(letra);
	}
	while (p->isEmpty() != true) {
		cout << p->pop();
	}
}
void BalancearEquacao() {
	Pilha<char> p = Pilha<char>();

	cout << "entre com uma equação matematica ";
	string frase;
	cin >> frase;
	 
	for(char letra : frase){
		if (letra == '(') {
			p.insert(letra);
		}

		if (letra == ')') {
			if (p.isEmpty() || p.pop() != '(') {
				cout << "equação desbalanceada " << endl;
				return;
			}
		}

	}
	if (p.isEmpty() != true) {
		cout << "equação desbalanceada " << endl;
		return;
	}

	cout << "equação balanceada " << endl;
}
int main(int argc, char* argv[]) {
	
	BalancearEquacao();

	return 0;
}