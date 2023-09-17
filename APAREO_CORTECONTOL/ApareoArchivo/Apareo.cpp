/*
    Apareo de dos vectores o archivos. Se genera un tercer archivo o vector con los datos de los dos.
    Ambos archivos deben ser del mismo tipo y estar ordenados por una misma clave de ordenamiento.
    Los datos se intercalan de manera ordenada según un criterio.
*/

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
    // Definimos los punteros a los archivos de entrada y salida
    FILE *A;
    FILE *B;
    FILE *C;

    // Abrimos los archivos de entrada y el archivo de salida
    A = fopen("ArchA.dat", "rb");
    B = fopen("ArchB.dat", "rb");
    C = fopen("ArchC.dat", "wb");

    // Registros auxiliares para los archivos A y B
    Alumno rauxA;
    Alumno rauxB;

    // Leemos el primer registro de los archivos A y B
    fread(&rauxA, sizeof(struct Alumno), 1, A);
    fread(&rauxB, sizeof(struct Alumno), 1, B);

    // Realizamos el proceso de apareo
    while (!feof(A) && !feof(B))
    {
        while (!feof(A) && !feof(B))
        {
            if (rauxA.legajo < rauxB.legajo)
            {
                // Si el legajo en rauxA es menor, escribimos rauxA en el archivo de salida (C)
                fwrite(&rauxA, sizeof(struct Alumno), 1, C);
                fread(&rauxA, sizeof(struct Alumno), 1, A); // Pasamos al siguiente registro en A
            }
            else
            {
                // Si el legajo en rauxB es menor o igual, escribimos rauxB en el archivo de salida (C)
                fwrite(&rauxB, sizeof(struct Alumno), 1, C);
                fread(&rauxB, sizeof(struct Alumno), 1, B); // Pasamos al siguiente registro en B
            }
        }
    }

    // Si alguno de los archivos aún tiene registros, se procesan por separado
    while (!feof(A))
    {
        fwrite(&rauxA, sizeof(struct Alumno), 1, C);
        fread(&rauxA, sizeof(struct Alumno), 1, A);
    }
    while (!feof(B))
    {
        fwrite(&rauxB, sizeof(struct Alumno), 1, C);
        fread(&rauxB, sizeof(struct Alumno), 1, B);
    }

    // Cerramos los archivos
    fclose(A);
    fclose(B);
    fclose(C);

    return 0;
}
