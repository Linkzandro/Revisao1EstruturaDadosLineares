#pragma once
#include <iostream>
using namespace std;
class Documento
{
private:
	string nome;
	string prioridade;

public:
	Documento(string nomeC, string prioridadeC);
	string getName();
	string getPriority();
};



