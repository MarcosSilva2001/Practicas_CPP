/*Ejercicio 2: (3 puntos)
Se tiene un vector de los alumnos del curso K1151, que contiene todos los alumnos que se inscribieron en
la materia con los siguientes campos:
-Numero de Legajo,
-Nota del Primer Parcial
-Nota del Segundo Parcial.
Además, se cuenta con una lista ordenada que contiene las notas de los que rindieron recuperatorio del Segundo Parcial;
cada nodo de la lista contiene:
-Número de Legajo
-Nota del recuperatorio.
Se pide, actualizar el vector K1151 con la información que hay en la lista, SOLO para el campo Nota Segundo Parcial
si es que aprobó el recuperatorio, sino no hacer nada.
Ej: Si un alumno obtuvo 6 o más en su recuperatorio (esto se encontrará en el nodo) en el vector en el campo de Nota
del Segundo Parcial, tendrá que aparecer esa nueva nota. Si obtuvo menos que 6, no modificar. Se sabe que cómo Máximo hay 50 alumnos.
*/
#include <iostream>
using namespace std;

// registros
struct Curso_K1115
{
    int legajo;
    int nota_primerP;
    int nota_segundoP;
};
struct Recu_SegundoP
{
    int legajo;
    int nota_recu2;
};
struct Nodo
{
    Recu_SegundoP info;
    Nodo *sgte;
};

// encabezados de los procedimientos y funciones
int buscar(Curso_K1115 vec[], int len, int valor);
void liberar(Nodo *&lista);

int main(int argc, char const *argv[])
{
    // 1)
    Curso_K1115 K1115[50];
    int len;

    Nodo *lista;
    int pos;
    Nodo *aux = lista;

    while (aux != NULL)
    {
        pos = buscar(K1115, len, aux->info.legajo);

        if (pos != -1 && aux->info.nota_recu2 >= 6)
        {
            K1115[pos].nota_segundoP = aux->info.nota_recu2;
        }

        aux = aux->sgte;
    }

    liberar(lista);

    return 0;
}
