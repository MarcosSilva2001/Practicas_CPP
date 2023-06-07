#include <iostream>
using namespace std;

int main()
{
    int num1, num2;
    int suma = 0, resta = 0, mult = 0;
    float division = 0;

    cout << "A continuación ingrese 2 números que desea operar..." << endl;
    cout << "Ingrese el primer número: ";
    cin >> num1;
    cout << "Ingrese el segundo número: ";
    cin >> num2;

    suma = num1 + num2;
    resta = num1 - num2;
    mult = num1 * num2;

    cout << "\n-------LOS RESULTADOS DE LAS OPERACIONES SON-------\n" << endl;
    cout << "La suma es: " << suma << endl;
    cout << "La resta es: " << resta << endl;
    cout << "La multiplicación es: " << mult << endl;

    if (num2 != 0)
    {
        division = (num1) / num2;
        cout << "La división es: " << division << endl;
    }
    else
    {
        cout << "Error: no se puede dividir por cero." << endl;
    }

    return 0;
}