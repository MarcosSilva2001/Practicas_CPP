#include <iostream>
using namespace std;

int main() {
    int valor;
    int suma = 0;
    int contador = 0;
    float promedio;

    while (true) {
        cout << "Ingrese un valor (finaliza con un valor negativo): ";
        cin >> valor;
        
        if (valor < 0) {
            break;
        }

        suma += valor;
        contador++;
    }

    if (contador > 0) {
        promedio = (suma) / contador;
        cout << "La suma es: " << suma << endl;
        cout << "El promedio es: " << promedio << endl;
    } else {
        cout << "No se ingresaron valores válidos." << endl;
    }

    return 0;
}