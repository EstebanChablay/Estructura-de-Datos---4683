#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

typedef long long ll;

ll expo(ll base, ll exp) {
    if (exp == 0) {
        return 1;
    }
    ll tmp = expo(base, exp / 2);
    tmp *= tmp;
    if (exp % 2 == 1) {
        tmp *= base;
    }
    return tmp;
}

int main()
{
    int a = 0, b = 0;
    cout << "\t\tDivide y Venceras" << endl;
    cout << "Ingrese la base: ";
    cin >> a;
    cout << "Ingrese el exponente: ";
    cin >> b;
    cout << "Exponencial de el numero [" << a << "] con exponente [" << b << "] es: ";
    cout << expo(a, b);
}
