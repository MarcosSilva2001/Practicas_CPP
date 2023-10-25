/*
Ejercicio 3:
Se tienen dos archivos de la materia prima necesaria para una cadena de comidas rápidas
BurgerFastAgosto.dat y BurgerFastSeptiembre.dat ordenado por código de producto.
- Código de Producto: 999999
- Cantidad de unidades en depósito: 99999
- Tipo de producto: ‘H’, ‘N’ ó ‘P’ (Hamburguesas, Nuggets o Pan)
Se pide:
a) Obtener un archivo BurgerFast.dat que consolide ambos archivos.
b) Generar un archivo sólo para panes Pan.dat con la siguiente estructura:
a. Código de Producto: 999999
b. Cantidad de unidades en depósito: 99999
Nota: Sólo puede leer 1 vez el archivo.
*/

#include <iostream>
#include <stdio.h>
using namespace std;

struct Comida
{
    int codigo;
    int cant_deposito;
    char tipo; // 'H', 'N' o 'P' (Hamburguesas, Nuggets o Pan)
};

struct Pan
{
    int codigo;
    int cant_deposito;
};

struct Nodo
{
    Comida info;
    Nodo *sgte;
};

void insertarOrdenado(Nodo *&Lista, Comida valor);
void mostrar(Nodo *Lista);
void liberar(Nodo *&Lista);

int main(int argc, char const *argv[])
{
    // Listas
    Nodo *lista = NULL; // Lista que contendrá los datos ordenados de los 2 archivos

    // Creamos los punteros a los archivos y los abrimos
    FILE *Agosto;
    FILE *Septiembre;
    FILE *Burger;
    FILE *Pan;

    Comida auxA;
    Comida auxS;
    Pan raux;

    Agosto = fopen("BurgerFastAgosto.dat", "rb");
    Septiembre = fopen("BurgerFastSeptiembre.dat", "rb");
    Pan = fopen("Pan.dat", "wb");

    // Leemos los archivos
    fread(&auxA, sizeof(Comida), 1, Agosto);
    fread(&auxS, sizeof(Comida), 1, Septiembre);

    // Cargamos la lista ordenada con los datos del archivo y escribimos el archivo para panes
    while (!feof(Agosto) || !feof(Septiembre))
    {
        // Verificar si el tipo de producto es pan, si es el caso agregar al archivo Pan.dat
        if (auxA.tipo == 'P')
        {
            raux.codigo = auxA.codigo;
            raux.cant_deposito = auxA.cant_deposito;
            fwrite(&raux, sizeof(Pan), 1, Pan);
        }
        if (auxS.tipo == 'P')
        {
            raux.codigo = auxS.codigo;
            raux.cant_deposito = auxS.cant_deposito;
            fwrite(&raux, sizeof(Pan), 1, Pan);
        }

        // Insertamos de manera ordenada los datos del archivo leidas por los regristros auxA y auxS en la lista
        insertarOrdenado(lista, auxA);
        insertarOrdenado(lista, auxS);

        fread(&auxA, sizeof(Comida), 1, Agosto);
        fread(&auxS, sizeof(Comida), 1, Septiembre);
    }

    // Salimos del bucle porque uno de los archivos ha terminado
    // Seguimos cargando la lista con los datos del archivo que aun no termino y escribimos el archivo de pan si es necesario
    if (!feof(Agosto))
    {
        insertarOrdenado(lista, auxA);
        fread(&auxA, sizeof(Comida), 1, Agosto);

        if (auxA.tipo == 'P')
        {
            raux.codigo = auxA.codigo;
            raux.cant_deposito = auxA.cant_deposito;
            fwrite(&raux, sizeof(Pan), 1, Pan);
        }
    }

    if (!feof(Septiembre))
    {
        insertarOrdenado(lista, auxS);
        fread(&auxS, sizeof(Comida), 1, Septiembre);

        if (auxS.tipo == 'P')
        {
            raux.codigo = auxS.codigo;
            raux.cant_deposito = auxS.cant_deposito;
            fwrite(&raux, sizeof(Pan), 1, Pan);
        }
    }
    
    // Cerramos los archivos que ya no usaremos
    fclose(Agosto);
    fclose(Septiembre);
    fclose(Pan);
    
    // Escribimos el archivo BurgerFrast.dat con los datos ordenados de la lista
    Burger = fopen("BurgerFast.dat", "wb");

    Nodo *auxiliar = lista;
    while (auxiliar != NULL)
    {
        fwrite(&auxiliar->info, sizeof(Comida), 1, Burger);
        auxiliar = auxiliar->sgte;
    }
    fclose(Burger);
    liberar(lista);

    return 0;
}
