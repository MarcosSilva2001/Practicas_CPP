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

    // 2) Abrir el archivo para lectura
    Alum = fopen("K1115.dat", "rb");

    // 3) Lectura del archivo
    fread(&raux, sizeof(Alumno), 1, Alum);

    while (!feof(Alum)) // mientrar no sea el final del archivo
    {
        cout << "Legajo: " << raux.legajo << endl;
        cout << "DNI: " << raux.dni << endl;
        cout << "Nota 1: " << raux.nota1 << endl;
        cout << "Nota 2: " << raux.nota2 << endl;
        cout << "--------------------: " << endl;

        fread(&raux, sizeof(Alumno), 1, Alum);
    }

    fclose(Alum);

    return 0;
}
