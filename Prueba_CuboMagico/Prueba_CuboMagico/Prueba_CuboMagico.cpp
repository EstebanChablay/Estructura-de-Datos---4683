#include <iostream>
#include "CuboMagico.h"

using namespace std;

int main()
{
	int** cuadrado, dim, num;
	int serie, centinela;
	cout << "Ingrese la dimension: ";
	cin >> dim;
	num = 2 * dim - 1;
	cout << num << endl;
	cout << "Ingrese la serie: ";
	cin >> serie;
	cout << "Ingrese el centinela: ";
	cin >> centinela;
	cuadrado = (int**)calloc(num, sizeof(int*));
	for (int i = 0; i < num; i++) {
		*(cuadrado + i) = (int*)calloc(num, sizeof(int));
		//cout << *(cuadrado + i) << endl;
	}
	CuboMagico cubo = CuboMagico(cuadrado);
	cubo.llenar(num, num, serie, centinela);
	//cubo.mostrar(num, num);
	cubo.verificar(num, num);
	system("pause");
}
