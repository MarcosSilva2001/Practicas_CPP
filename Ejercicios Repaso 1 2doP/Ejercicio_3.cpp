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

struct pan
{
    int codigo;
    int cant_deposito;
};

int main(int argc, char const *argv[])
{

    // Creamos los punteros a los archivos y los abrimos
    FILE *Agosto;
    FILE *Septiembre;
    FILE *Burger;
    FILE *Pan;

    Comida auxA;
    Comida auxS;

    pan raux;

    Agosto = fopen("BurgerFastAgosto.dat", "rb");
    Septiembre = fopen("BurgerFastSeptiembre.dat", "rb");
    Burger = fopen("BurgerFast.dat", "wb");
    Pan = fopen("Pan.dat", "wb");

    // Leemos los archivos
    fread(&auxA, sizeof(Comida), 1, Agosto);
    fread(&auxS, sizeof(Comida), 1, Septiembre);

    while (!feof(Agosto) && !feof(Septiembre))
    {
        // verificamos si el id del producto del archivo agosto es mas chico que del archivo septiembre
        if (auxA.codigo < auxS.codigo)
        {
            // Verificar si el tipo de producto es pan, si es el caso agregar al archivo Pan.dat
            if (auxA.tipo == 'P')
            {
                raux.codigo = auxA.codigo;
                raux.cant_deposito = auxA.cant_deposito;
                fwrite(&raux, sizeof(Pan), 1, Pan);
            }
            else if (auxS.tipo == 'P')
            {
                raux.codigo = auxS.codigo;
                raux.cant_deposito = auxS.cant_deposito;
                fwrite(&raux, sizeof(Pan), 1, Pan);
            }
            // escribimos en el archivo BurgerFast
            fwrite(&auxA, sizeof(Comida), 1, Burger);
            fread(&auxA, sizeof(Comida), 1, Agosto);
        }
        else
        {
            if (auxA.tipo == 'P')
            {
                raux.codigo = auxA.codigo;
                raux.cant_deposito = auxA.cant_deposito;
                fwrite(&raux, sizeof(Pan), 1, Pan);
            }
            else if (auxS.tipo == 'P')
            {
                raux.codigo = auxS.codigo;
                raux.cant_deposito = auxS.cant_deposito;
                fwrite(&raux, sizeof(Pan), 1, Pan);
            }
            // escribimos en el archivo BurgerFast
            fwrite(&auxS, sizeof(Comida), 1, Burger);
            fread(&auxS, sizeof(Comida), 1, Agosto);
        }
    }

    // Salimos del bucle porque uno de los archivos ha terminado
    while (!feof(Agosto))
    {
        fwrite(&auxA, sizeof(Comida), 1, Burger);
        fread(&auxA, sizeof(Comida), 1, Agosto);

        if (auxA.tipo == 'P')
        {
            raux.codigo = auxA.codigo;
            raux.cant_deposito = auxA.cant_deposito;
            fwrite(&raux, sizeof(Pan), 1, Pan);
        }
    }

    while (!feof(Septiembre))
    {
        fwrite(&auxS, sizeof(Comida), 1, Burger);
        fread(&auxS, sizeof(Comida), 1, Septiembre);

        if (auxS.tipo == 'P')
        {
            raux.codigo = auxS.codigo;
            raux.cant_deposito = auxS.cant_deposito;
            fwrite(&raux, sizeof(Pan), 1, Pan);
        }
    }
    // Cerramos los archivos
    fclose(Agosto);
    fclose(Septiembre);
    fclose(Pan);
    fclose(Burger);

    return 0;
}
