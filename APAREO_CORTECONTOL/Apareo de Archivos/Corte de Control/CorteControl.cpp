/*
    Corte de Control ordena por una clave repetida, agrupa los registros por una clave o criterio.
    El archivo debe estar ordenado.
*/

#include <iostream>
#include <stdio.h>

using namespace std;

struct Multa
{
    int dominio;
    int tipo;
    int importe;
};

int main()
{
    FILE *Mul;
    Mul = fopen("Multas.dat", "rb"); // Abre el archivo "Multas.dat" en modo lectura

    Multa raux;
    int anterior;      // Almacena el dominio anterior para agrupar
    int sumaMulta = 0; // Almacena el total de multas para un dominio

    fread(&raux, sizeof(struct Multa), 1, Mul); // Lee el primer registro del archivo

    while (!feof(Mul))
    {
        // Guarda el dominio actual en 'anterior' para agrupar
        anterior = raux.dominio;
        sumaMulta = 0; // Reinicia la suma de multas

        // Itera mientras el dominio sea el mismo que 'anterior'
        while ((!feof(Mul)) && (anterior == raux.dominio))
        {
            sumaMulta += raux.importe;                  // Suma el importe de la multa actual
            fread(&raux, sizeof(struct Multa), 1, Mul); // Lee el siguiente registro para seguir agrupando
        }

        // Muestra el total de multas para el dominio agrupado
        cout << "El Dominio " << anterior << " tiene un total de multa de: " << sumaMulta << endl;
    }

    fclose(Mul); // Cierra el archivo
    return 0;
}
