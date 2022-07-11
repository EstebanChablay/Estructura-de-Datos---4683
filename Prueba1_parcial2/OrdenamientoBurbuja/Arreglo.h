#pragma once
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

template <typename T>
class Arreglo {
private:
    T* _datos = nullptr;
    int _tamano = 0;

public:
    Arreglo();
    void agregar(T elemento);
    void agregarIndice(int, T);
    void agregarRandomicos();
    T obtener(int indice);
    void imprimir();
    int get_tamano();
    void set_tamano(int);
    T* get_datos();
    void set_datos(T);
    void borrar();
};

template<typename T>
int Arreglo<T>::get_tamano()
{
    return _tamano;
}

template<typename T>
void Arreglo<T>::set_tamano(int tam) {
    this->_tamano = tam;
}


template <typename T>
T* Arreglo<T>::get_datos() {
    return _datos;
}

template<typename T>
void Arreglo<T>::set_datos(T dat) {
    this->_datos = dat;
}

template <typename T>
Arreglo<T>::Arreglo() {}

template <typename T>
void Arreglo<T>::borrar() {
    //_detele[] _datos;
}

template <typename T>
void Arreglo<T>::agregar(T elemento) {
    if (_tamano == 0) {
        _datos = new T[1];
    }
    else {
        T* nuevo = new T[_tamano + 1];

        for (int i = 0; i < _tamano; i++) {
            *(nuevo + i) = *(_datos + i);
        }

        delete[] _datos;
        _datos = nuevo;
    }
    *(_datos + _tamano) = elemento;
    _tamano++;
}

template <typename T>
void Arreglo<T>::agregarIndice(int indice, T elemento) {
    *(_datos + indice) = elemento;
}

template <typename T>
void Arreglo<T>::agregarRandomicos() {
    int a = 0;
    for (int i = 0; i < 100; i++) {
        a = rand() % 9999999;
        agregar(a);
    }
}

template<typename T>
T Arreglo<T>::obtener(int indice)
{
    return *(_datos + indice);;
}

template <typename T>
void Arreglo<T>::imprimir() {
    if (_datos) {
        cout << "[";

        for (int i = 0; i < _tamano; i++) {
            cout << *(_datos + i);

            if (i != _tamano - 1) {
                cout << ", ";
            }
        }

        cout << "]" << endl;
    }
    else {
        cout << "La lista se encuentra vacia" << endl;
    }


}