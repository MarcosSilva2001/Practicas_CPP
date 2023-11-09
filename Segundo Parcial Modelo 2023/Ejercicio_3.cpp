/*Ejercicio 3: (3 puntos)
Se tiene un archivo de resultados electorales sumarizado llamado PASO.dat (sin Orden).
ID del Partido politico: 999999
Número de lista: 999
- ID de la Provincia: 99
Votos obtenidos: 9999999
Se pide:
a) Ordenar el archivo Paso DAT por ID del Partido
b) Armar una lista ordenada por Votos Obtenidos, si los votos obtenidos superaron 150.000 e imprimir la lista por pantalla.
Nota: Sólo puede leer 1 vez el archivo.*/
#include <iostream>
#include <stdio.h>
using namespace std;

struct EleccionesPaso
{
    int ID_Partido;
    int num_lista;
    int ID_Porvincia;
    int votos_obtenidos;
};
struct Nodo
{
    EleccionesPaso info;
    Nodo *sgte;
};

int main(int argc, char const *argv[])
{
    FILE *paso;
    paso = fopen("Paso.dat", "rb");

    Nodo *listaPartido = NULL;
    Nodo *listaOrd = NULL;

    EleccionesPaso raux;

    fread(&raux, sizeof(EleccionesPaso), 1, paso);

    while (!feof(paso))
    {
        // cargamos los datos del archivo en la listaOrd de manera ordenada por ID del partido
        insertarOrdenado(listaOrd, raux);

        if (raux.votos_obtenidos > 150000)
        {
            insertarOrdenado(listaPartido, raux); // lista ordeanada por votos obteneidos
        }

        fread(&raux, sizeof(EleccionesPaso), 1, paso);
    }
    fclose(paso);

    // ahora escribimos el archivo Paso.dat de manera ordenada usando la lista;

    Nodo *aux = lista;
    paso = fopen("Paso.dat", "wb");

    while (aux != NULL)
    {
        fwrite(&aux->info, sizeof(EleccionesPaso), 1, paso);
        aux = aux->sgte;
    }

    // mostramos por parntalla la lista  del partido ordenada por cantidad de votos
    mostrar(listaPartido);
    liberar(listaOrd);
    liberar(listaPartido);
    fclose(paso);

    return 0;
}
