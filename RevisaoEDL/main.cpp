#include <iostream>
#include "ListaSimples.h"
#include "ListaDupla.h"
#include "pilha.h"
#include "fila.h"
#include "documento.cpp"
#include "FilaDocumento.h"
#include "listaCircular.h"

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
void AtenderCliente() {
	Fila<string> f =Fila<string>();
	f.Insert("josé");
	f.Insert("Maria");
	f.Insert("Antonia");
	f.Insert("Pedro");
	f.displayall();

	cout << "atendendo cliente " << f.pop() << endl;

	cout << "clientes não atendidos:" << endl;
	f.displayall();
}

void FilaDoc() {
	FilaDocumento fila = FilaDocumento();
	Documento doc("Joao","normal");
	fila.InsertDocument(doc);
	doc=Documento("Pedro","urgente");
	fila.InsertDocument(doc);
	doc=Documento("Jose","normal");
	fila.InsertDocument(doc);
	doc=Documento("Josias","urgente");
	fila.InsertDocument(doc);
    doc=Documento("zefa","urgente");
    fila.InsertDocument(doc);
	fila.displayFila();
}

void ListaCircularJosephus(){
    ListaCircular<string> lista=ListaCircular<string>();

    lista.insertHead("jose");
    lista.insertHead("maria");
    lista.insertHead("Joao");
    lista.insertHead("robs");
    lista.insertHead("pedro");
    lista.Josephus(2);
    lista.displayAll();


}
int main(int argc, char* argv[]) {

    ListaCircularJosephus();
	return 0;
}
