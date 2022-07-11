#pragma warning(disable : 4996)
#include "Ordenamientos.h"
#include <string>

void Ordenamientos::metodoBurbuja(Arreglo<int> arreglo) {
    int aux = 0;

    //cout << "\t\t**Se ordeno mediante el metodo burbuja con enteros**" << endl;
    for (int i = 0; i < arreglo.get_tamano() - 1; i++) {
        for (int j = 0; j < arreglo.get_tamano() - 1 - i; j++) {
            if (arreglo.obtener(j) > arreglo.obtener(j + 1)) {
                aux = arreglo.obtener(j + 1);
                arreglo.agregarIndice(j + 1, arreglo.obtener(j));
                arreglo.agregarIndice(j, aux);
            }
        }
    }
}

void Ordenamientos::metodoBurbujaLetras(Arreglo<string> arreglo, int n) {
    string temp;
    //cout << "\t\t**Se ordeno mediante el metodo burbuja con string**" << endl;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (strcmp(arreglo.obtener(j).c_str(), arreglo.obtener(j + 1).c_str()) > 0) {
                temp = arreglo.obtener(j);
                arreglo.agregarIndice(j, arreglo.obtener(j + 1));
                arreglo.agregarIndice(j + 1, temp);
            }
        }
    }
}

void Ordenamientos::metodoQuickSort(Arreglo<int> arreglo, int izq, int der) {
    int i, j, x, aux = 0;
    i = izq;
    j = der;
    x = arreglo.obtener((izq + der) / 2);
   
    //cout << "Ordenamiento por el metodo QuickSort" << endl;

    do {
        while ((arreglo.obtener(i) < x) && (j <= der)) {
            i++;
        }

        while ((x < arreglo.obtener(j)) && (j > izq)) {
            j--;
        }
        
        if (i <= j) {
            aux = arreglo.obtener(i);
            arreglo.agregarIndice(i, arreglo.obtener(j));
            arreglo.agregarIndice(j, aux);
            i++;
            j--;
        }
    } while (i <= j);

    if (izq < j) {
        metodoQuickSort(arreglo, izq, j);
    }
    if (i < der) {
        metodoQuickSort(arreglo, i, der);
    }

}

void Ordenamientos::metodoShellSort(Arreglo<int> arreglo, int n) {
    int i, j, inc, temp;

    for (inc = 1; inc < n; inc = inc * 3 + 1);
    while (inc > 0) {
        for (i = inc; i < n; i++) {
            j = i;
            temp = arreglo.obtener(i);
            while ((j >= inc) && (arreglo.obtener(j - inc) > temp)) {
                arreglo.agregarIndice(j, arreglo.obtener(j - inc));
                j = j - inc;
            }
            arreglo.agregarIndice(j, temp);
        }
        inc /= 2;
    }
}

void Ordenamientos::ordenarGRuposShell_Chablay_Esteban(Arreglo<int> arreglo, int n, int cubos) {
    int i, j, contador=0, restantes=0; 
    Arreglo<int> aux;
    Arreglo<int> fin;
    restantes = arreglo.get_tamano() / cubos;
    for (i = 0; i < cubos; i++) {
        aux.agregar(0);
    }
    for (i = 0; i < arreglo.get_tamano()/cubos; i++) {
        for (j = 0; j < cubos; j++) {
            aux.agregarIndice(j, arreglo.obtener(contador));
            contador++;
        }     
        cout << "\nDividido en Cubos #" << i+1 << endl;
        aux.imprimir();
        metodoShellSort(aux, aux.get_tamano());
        cout << "Ordenado" << endl;
        aux.imprimir();
    }
    for (i = 0; i < arreglo.get_tamano() - contador; i++){
        fin.agregar(0);
    }
    if (restantes != 0) {
        cout << "\nDividido en Cubos #" << arreglo.get_tamano()/cubos+1 << " con datos restantes " << arreglo.get_tamano() - contador << endl;
        for (i = 0; i <= arreglo.get_tamano()-contador; i++) {
            fin.agregarIndice(i, arreglo.obtener(contador));
            contador++;
        } 
        fin.imprimir();
        metodoShellSort(fin, fin.get_tamano());
        cout << "Ordenado" << endl;
        fin.imprimir();
    }
}