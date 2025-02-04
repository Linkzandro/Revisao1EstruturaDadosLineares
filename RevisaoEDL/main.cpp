#include <iostream>
#include "ListaSimples.h"
#include "ListaDupla.h"

using namespace std;


void VerificarListaSimples() {
	ListaDupla<string>* lista = new ListaDupla<string>();
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
int main(int argc, char* argv[]) {
	VerificarListaDupla();
	

	return 0;
}