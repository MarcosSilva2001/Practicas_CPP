#include <iostream>
#include <stdio.h>

using namespace std;

struct Alumno
{
    int legajo;
    int dni;
    int nota1;
    int nota2;
};

int main()
{
    // definimos un registro aux para recorrer cada campo del archivo y guardar los datos en raux
    Alumno raux;

    // 1) Definir un puntero al archivo
    FILE *Alum;

    // 2) Abrir el archivo para escritura
    Alum = fopen("K1115.dat", "wb");

    // 3) Escribimos el archivo
    cout << "Ingrese un legajo o 0 para finalizar: " << endl;
    cin >> raux.legajo;

    while (raux.legajo > 0)
    { // procesamos
        cout << "Digite un DNI: " << endl;
        cin >> raux.dni;
        cout << "Ingrese la nota 1: " << endl;
        cin >> raux.nota1;
        cout << "Ingrese la nota 2: " << endl;
        cin >> raux.nota2;

        // escribimos
        fwrite(&raux, sizeof(Alumno), 1, Alum);

        cout << "Ingrese un legajo o 0 para finalizar: " << endl;
        cin >> raux.legajo;
    }

    fclose(Alum);

    return 0;
}
