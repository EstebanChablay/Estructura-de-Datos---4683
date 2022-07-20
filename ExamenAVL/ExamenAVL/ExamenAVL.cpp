#include "Nodo.h"
#include "ArbolAVL.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
    ArbolAVL obj;
    int opcion, val, contador=0;
    int* sum = new int[100];
    int* cifrado = new int[100];
    int cant=0;
    do {
        cout << "\t\t ||--|| ARBOL AVL ||--||" << endl <<" Seleccione la opcion:" << endl;
        cout << "1. Insertar Nodo" << endl;
        cout << "2. Buscar Nodo" << endl;
        cout << "3. Borrar Nodo" << endl;
        cout << "4. Imprimir Arbol" << endl;
        cout << "5. Altura del Arbol" << endl;
        cout << "6. Limpiar pantalla" << endl;
        cout << "0. Salir" << endl;

        cin >> opcion;
        Nodo* new_node = new Nodo();
        Nodo* cif_node = new Nodo();

        switch (opcion) {
        case 0:
            break;
        case 1:
            cout << "INSERTAR" << endl;
            cout << "Ingrese el valor a insertar en el arbol AVL:  ";
            cin >> val;
            new_node->valor = val;
            obj.raiz = obj.insertar(obj.raiz, new_node);
            cout << endl;
            break;
        case 2:
            cout << "BUSQUEDA" << endl;
            cout << "Ingrese el valor a buscar en el arbol AVL: ";
            cin >> val;
            new_node = obj.recursiveSearch(obj.raiz, val);
            if (new_node != NULL) {
                cout << "Valor encontrado." << endl;
            }
            else {
                cout << "Valor no encontrado." << endl;
            }
            break;
        case 3:
            cout << "BORRAR" << endl;
            cout << "Ingrese el valor a borrar: ";
            cin >> val;
            new_node = obj.recursiveSearch(obj.raiz, val);
            if (new_node != NULL) {
                obj.raiz = obj.borrarNodo(obj.raiz, val);
                cout << "Nodo borrado." << endl;
            }
            else {
                cout << "Valor NO encontrado." << endl;
            }
            break;
        case 4: {
            cout << "\t\t**ARBOL AVL**" << endl;
            obj.print2D(obj.raiz, 2);
            //Suma de Niveles
            /*for (int i = 0; i < 10; i++) {
                sum[i] = 0;
            }
            obj.sumaNiveles(obj.raiz, contador, sum);
            for (int j = 0; j <= obj.altura(obj.raiz); j++) {
                cout << "Total del nivel [" << j << "] : " << sum[j] << endl;
            }*/
            //Cifrar Valores

            auto f = [&]() {
                ArbolAVL cif;
                cif_node->valor = obj.sumaCifras(obj.raiz->valor);
                cif.raiz = cif.insertar(cif.raiz, new_node);
                obj.cifrarValores(obj.raiz, contador, cifrado, &cif);
                cout << "\t\t**ARBOL CIFRADO**" << endl;
                cif.print2D(cif.raiz, 2);
            };
            f();

            cout << endl;
            break;
        }
        case 5:
            cout << "ALTURA DEL ARBOL AVL" << endl;
            cout << "Altura : " << obj.altura(obj.raiz) << endl;
            break;
        case 6:
            system("cls");
            break;
        default:
            cout << "Enter Proper Option number " << endl;
        }

    } while (opcion != 0);
}