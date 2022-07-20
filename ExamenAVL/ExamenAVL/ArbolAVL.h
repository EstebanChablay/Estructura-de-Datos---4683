#pragma once
#define SPACE 10
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "Nodo.h"

using namespace std;

class ArbolAVL
{
public:
	Nodo* raiz;
	ArbolAVL() {
		raiz = NULL;
	}

	bool arbolVacio() {
		if (raiz == NULL) {
			return true;
		}
		else {
			return false;
		}
	}

	//obtener altura
	int altura(Nodo* r) {
		if (r == NULL)
			return -1;
		else {
			int lheight = altura(r->izq);
			int rheight = altura(r->der);

			if (lheight > rheight)
				return (lheight + 1);
			else return (rheight + 1);
		}
	}

	//obtener el factor de balance del nodo
	int obtenerBalance(Nodo* n) {
		if (n == NULL) {
			return -1;
		}
		return altura(n->izq) - altura(n->der);
	}

	//Rotaciones
	Nodo* rotacionDer(Nodo* y) {
		Nodo* x = y->izq;
		Nodo* T2 = x->der;

		// Perform rotation  
		x->der = y;
		y->izq = T2;

		return x;
	}

	Nodo* rotacionIzq(Nodo* x) {
		Nodo* y = x->der;
		Nodo* T2 = y->izq;

		// Perform rotation  
		y->izq = x;
		x->der = T2;

		return y;
	}

	Nodo* insertar(Nodo* r, Nodo* newNodo) {
		if (r == NULL) {
			r = newNodo;
			cout << "Valor insertado." << endl;
			//cant++;
			return r;
		}

		if (newNodo->valor < r->valor) {
			r->izq = insertar(r->izq, newNodo);
			//cant++;
		}
		else if ((newNodo->valor > r->valor) || (newNodo->valor == r->valor)) {
			r->der = insertar(r->der, newNodo);
			//cant++;
		}

		int bf = obtenerBalance(r);
		if (bf > 1 && newNodo->valor < r->izq->valor)
			return rotacionDer(r);
  
		if (bf < -1 && newNodo->valor > r->der->valor)
			return rotacionIzq(r);

		if (bf > 1 && newNodo->valor > r->izq->valor) {
			r->izq = rotacionIzq(r->izq);
			return rotacionDer(r);
		}
 
		if (bf < -1 && newNodo->valor < r->der->valor) {
			r->der = rotacionDer(r->der);
			return rotacionIzq(r);
		}

		return r;
	}

	Nodo* minValueNode(Nodo* nodo) {
		Nodo* current = nodo;
		while (current->izq != NULL) {
			current = current->izq;
		}
		return current;
	}

	Nodo* borrarNodo(Nodo* r, int v) {
		if (r == NULL) {
			return NULL;
		}
		else if (v < r->valor) {
			r->izq = borrarNodo(r->izq, v);
		} 
		else if (v > r->valor) {
			r->der = borrarNodo(r->der, v);
		}
		else {
			if (r->izq == NULL) {
				Nodo* temp = r->der;
				delete r;
				return temp;
			}
			else if (r->der == NULL) {
				Nodo* temp = r->izq;
				delete r;
				return temp;
			}
			else {
				Nodo* temp = minValueNode(r->der);
				r->valor = temp->valor;
				r->der = borrarNodo(r->der, temp->valor);
			}
		}

		int bf = obtenerBalance(r);
		if (bf == 2 && obtenerBalance(r->izq) >= 0)
			return rotacionDer(r);
		else if (bf == 2 && obtenerBalance(r->izq) == -1) {
			r->izq = rotacionIzq(r->izq);
			return rotacionDer(r);
		}
		else if (bf == -2 && obtenerBalance(r->der) <= -0)
			return rotacionIzq(r);
		else if (bf == -2 && obtenerBalance(r->der) == 1) {
			r->der = rotacionDer(r->der);
			return rotacionIzq(r);
		}

		return r;
	}

	void print2D(Nodo* r, int space) {
		if (r == NULL) {
			return;
		}
		space += SPACE;
		print2D(r->der, space);
		cout << endl;
		for (int i = SPACE; i < space; i++) {
			cout << " ";
		}
		cout << r->valor << "\n";
		print2D(r->izq, space);
	}

	void mostrarArbol(Nodo* raiz, int cont) {
		if (raiz == NULL) {
			return;
		}
		else {
			mostrarArbol(raiz->der, cont + 1);
			for (int i = 0; i < cont; i++) {
				cout << "  ";
			}
			cout << raiz->valor << endl;
			mostrarArbol(raiz->izq, cont + 1);
		}
	}

	void sumaNiveles(Nodo* arbol, int cont, int* sum) {
		int aux = 0;
		int niv = 0;
		int i;
		if (arbol == NULL) {
			return;
		}
		else {
			sumaNiveles(arbol->der, cont + 1, sum);
			for (int i = 0; i < cont; i++) {
				niv++;
			}
			//cout << arbol->valor << "(" << niv << ")" << endl;
			aux = sum[niv];
			sum[niv] = arbol->valor + aux;
			sumaNiveles(arbol->izq, cont + 1, sum);
		}
	}

	void cantNodos(Nodo* arbol, int cont, int& cant) {
		if (raiz == NULL) {
			return;
		}
		else {
			mostrarArbol(raiz->der, cont + 1);
			for (int i = 0; i < cont; i++) {
				//cout << "  ";
			}
			cant=cant+1;
			mostrarArbol(raiz->izq, cont + 1);
		}
	}

	int sumaCifras(int v) {
		if (v > 0) {
			return (v % 10) + sumaCifras(v/10);
		}
		else {
			return 0;
		}
	}

	void cifrarValores(Nodo* arbol, int cont, int* cifrados, ArbolAVL* cif) {
		int aux = 0;
		int niv = 0;
		int i;
		Nodo* cif_node = new Nodo();
		if (arbol == NULL) {
			return;
		}
		else {
			cifrarValores(arbol->der, cont + 1, cifrados, cif);
			for (int i = 0; i < cont; i++) {
				niv++;
			}
			cif_node->valor = sumaCifras(arbol->valor);
			cif->raiz = cif->insertar(cif->raiz, cif_node);
			cifrarValores(arbol->izq, cont + 1, cifrados, cif);
		}
	}

	void printPreorder(Nodo* r) { //R,I,D
		if (r == NULL) {
			return;
		}
		cout << r->valor << " ";
		printPreorder(r->izq);
		printPreorder(r->der);
	}

	void printInorder(Nodo *r) { //I,R,D
		if (r == NULL)
			return;
		printInorder(r->izq);
		cout << r->valor << " ";
		printInorder(r->der);
	}

	void printPostorder(Nodo* r) {
		if (r == NULL)
			return;
		printPostorder(r->izq);
		printPostorder(r->der);
		cout << r->valor << " ";
	}

	void printGivenLevel(Nodo* r, int level) {
		if (r == NULL) {
			return;
		}
		else if (level == 0) {
			cout << r->valor << " ";
		}
		else {
			printGivenLevel(r->izq, level - 1);
			printGivenLevel(r->der, level - 1);
		}
	}

	Nodo* busqueda(int v) {
		if (raiz == NULL) {
			return raiz;
		}
		else {
			Nodo* temp = raiz;
			while (temp != NULL) {
				if (v == temp->valor) {
					return temp;
				}
				else if (v < temp->valor) {
					temp = temp->izq;
				}
				else {
					temp = temp->der;
				}
			}
			return NULL;
		}
	}

	Nodo* recursiveSearch(Nodo* r, int val) {
		if (r == NULL || r->valor == val)
			return r;

		else if (val < r->valor)
			return recursiveSearch(r->izq, val);

		else
			return recursiveSearch(r->der, val);
	}



};

