#include <iostream>
#include "Arreglo.h"
#include "Ordenamientos.h"

using namespace std;

int main()
{
    Arreglo<int> arreglo;
    Arreglo<string> arregloString;
    Ordenamientos ord;
    int cubos;
    cout << "Ingrese los cubos: ";
    cin >> cubos;

    arreglo.agregarRandomicos();
    arreglo.imprimir();
    ord.ordenarGRuposShell_Chablay_Esteban(arreglo, arreglo.get_tamano(), cubos);
}