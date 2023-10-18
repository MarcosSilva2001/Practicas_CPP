/*
    Se tiene un archivo de las notas de los alumnos de primer año de todos los finales rendidos, Primer.dat
    ordenado por número de legajo.
    - Legajo: 999999
    - Materia
    - Nota: 1..10
    Se pide:
    a) Obtener el promedio de cada alumno según los finales rendidos
*/

#include <iostream>
#include <stdio.h>

using namespace std;

struct Alumno
{
    int legajo;
    int materia;
    int nota;
};

int main()
{
    FILE *Alum;
    Alum = fopen("Primer.dat", "rb");

    Alumno raux;
    int anterior;
    int sumaNota = 0;
    int cont = 0;

    fread(&raux, sizeof(Alumno), 1, Alum);

    while (!feof(Alum))
    {
        // agrupamos por legajo
        anterior = raux.legajo;
        while ((!feof(Alum)) && (anterior == raux.legajo))
        {
            sumaNota += raux.nota;
            cont++;
            fread(&raux, sizeof(Alumno), 1, Alum);
        }

        // Muestra el de las notas del alumno por finales rendidos
        cout << "El alumno cuyo legajo es " << anterior << " tiene un promedio de nota de: " << sumaNota / cont << endl;
    }
    fclose(Alum);

    return 0;
}
