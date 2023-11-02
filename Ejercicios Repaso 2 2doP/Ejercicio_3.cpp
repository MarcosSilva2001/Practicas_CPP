/*
Se tiene un archivo de la materia prima necesaria para una cadena de comidas rápidas BurgerFast.dat.
(sin orden)
- Código de Producto: 999999
- Descripción del producto
- Cantidad de unidades en depósito: 99999
- Tipo de producto: ‘H’, ‘N’ ó ‘P’ (Hamburguesas, Nuggets o Pan)
- Vencimiento: MMAAAA
Se pide:
a) Ordenar el archivo BurgerFast.DAT por código de Producto
b) Generar un archivo sólo para panes Pan.dat con la siguiente estructura:
a. Código de Producto: 999999
b. Cantidad de unidades en depósito: 99999
c. Vencimiento: MMAAAA
c) Generar un archivo UsarAntes.dat con los productos que tengan más de 1000 unidades en stock
ó se venzan el 122022 o antes, con la estructura original.
Nota: Sólo puede leer 1 vez el archivo.
*/
#include <iostream>
#include <stdio.h>
using namespace std;

struct ComidaRapida
{
    int codigoProd;
    char descripcion[30];
    int stock;
    char tipoProd; // H’, ‘N’ ó ‘P’ (Hamburguesas, Nuggets o Pan)
    int vencimiento;
};

struct Pan
{
    int codigoProd;
    int stock;
    int vencimiento;
};

struct Nodo
{
    ComidaRapida info;
    Nodo *sgte;
};

// Prodeciminetos y Funciones
void insertarOrdenado(Nodo *&lista, int valor);
void liberar(Nodo *&lista);

int main(int argc, char const *argv[])
{
    // definimos los Punteros a los archivos
    FILE *Burger;
    FILE *UsarA;
    FILE *Pan;
    // abrimos los archivos
    Burger = fopen("BurgerFast.dat", "rb");
    Pan = fopen("Pan.dat", "wb");
    UsarA = fopen("UsarAntes.dat", "wb");

    // registros para recorrer los archivos y una lista para ordenar
    ComidaRapida rauxB;
    Pan rauxP;
    Nodo *lista;
    // leemos el archivo
    fread(&rauxB, sizeof(ComidaRapida), 1, Burger);

    while (!feof(Burger))
    {
        insertarOrdenado(lista, rauxB); // ordenamiento por codigo de producto

        // verificar si el producto es de tipo P y escribir el archivo Pan.dat
        if (rauxB.tipoProd == 'P')
        {
            rauxP.codigoProd = rauxB.codigoProd;
            rauxP.stock = rauxB.stock;
            rauxP.vencimiento = rauxB.vencimiento;
            fwrite(&rauxP, sizeof(Pan), 1, Pan);
        }

        // verificar los productos con mas de 1000 unidades en stock y que venzan el 122022 o antes
        if ((rauxB.stock > 1000) && rauxB.vencimiento <= 122022)
        {
            fwrite(&rauxB, sizeof(ComidaRapida), 1, UsarA);
        }

        // leemos el siguiente registro del archivo BurgerFast
        fread(&rauxB, sizeof(ComidaRapida), 1, Burger);
    }
    fclose(Burger);
    fclose(Pan);
    fclose(UsarA);

    // ahora escribimos el archivo BurgerFast ordenado
    Burger = fopen("BurgerFast.dat", "wb");
    // declaramos un Nodo auxiliar para ordenar el archivo y no perder la referecia de la lista ya ordeanda
    Nodo *aux = lista;

    while (aux != NULL)
    {
        fwrite(&aux->info, sizeof(ComidaRapida), 1, Burger);
        aux = aux->sgte;
    }
    fclose(Burger);
    liberar(lista);

    return 0;
}
