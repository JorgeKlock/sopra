#include <iostream>

using namespace std;



void escribeNumerosDescendentes(int numero)
{
    if(numero > 1){
        cout << numero << endl;
        escribeNumerosDescendentes(numero-2);
    }
    // Este else-if es innecesario si se asumen numeros naturales
    else if (numero <-1){
        cout << numero << endl;
        escribeNumerosDescendentes(numero+2);
    }
    else{
        cout << numero << endl;
    }
}

void esNumeroPar(int numero)
{
    if(numero % 2 == 0){
        cout << "El número es par." << endl;
        escribeNumerosDescendentes(numero);
    }
    else{
        cout << "El número es impar." << endl;
        escribeNumerosDescendentes(numero);
    }
}

int leerNumero()
{
    int numero_leido;
    cout << "Introduzca un número: ";
    cin >> numero_leido;
    return numero_leido;
}

int main()
{
    int numero;
    numero = leerNumero();
    esNumeroPar(numero);
}

