#include "documento.h"


Documento::Documento(string nomeC, string prioridadeC):nome(nomeC),
	prioridade(prioridadeC) {
}

string Documento::getName() {
	return nome;
}
string Documento::getPriority() {
	return prioridade;
}
