#pragma once
#include <iostream>


class Nodo
{
public:
	int valor;
	Nodo* izq;
	Nodo* der;

	Nodo() {
		valor = 0;
		izq = NULL;
		der = NULL;
	}

	Nodo(int v) {
		valor = v;
		izq = NULL;
		der = NULL;
	}
};

