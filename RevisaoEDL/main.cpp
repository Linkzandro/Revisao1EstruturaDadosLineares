#include <iostream>
#include "ListaSimples.h"
#include "ListaDupla.h"

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
int main(int argc, char* argv[]) {
	VerificarListaDupla();
	

	return 0;
}