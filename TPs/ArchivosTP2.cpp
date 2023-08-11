/*
Se tiene un archivo de la materia prima necesaria para una cadena de comidas rápidas BurgerFast.dat. (sin orden)

-          Código de Producto: 999999

-          Cantidad de unidades en depósito: 99999

-          Tipo de producto: ‘H’, ‘N’ ó ‘P’ (Hamburguesas, Nuggets o Pan)

-          Vencimiento: MMAAAA

Se pide:

a)       Generar un archivo sólo para panes Pan.dat con la siguiente estructura:

- Código de Producto: 999999

- Cantidad de unidades en depósito: 99999

- Vencimiento: MMAAAA

b)      Generar un archivo UsarAntes.dat con los productos que tengan más de 1000 unidades en stock ó se venzan el 122023 o antes,
con la estructura original
*/

#include <stdio.h>
#include <iostream>

using namespace std;

struct Producto
{
    int codigo;
    int cantidad;
    char tipo;
    int vencimiento;
};
struct Pan
{
    int codigo;
    int cantidad;
    int vencimiento;
};

int main()
{
    // a)     Generar un archivo sólo para panes Pan.dat
    FILE *PointerProd;
    PointerProd = fopen("BurgerFast.dat", "rb");
    Producto rauxProd;

    FILE *Panes;
    Panes = fopen("Pan.dat", "wb");
    Pan rauxPan;

    fread(&rauxProd, sizeof(Producto), 1, PointerProd);

    // con rauxProd leemos los datos del archivo BurgerFast.fat y lo cargamos en el nuevo archivo Pan.dat que abrimos para escritura
    while (!feof(PointerProd))
    {
        if (rauxProd.tipo == 'P')
        {
            rauxPan.codigo = rauxProd.codigo;
            rauxPan.cantidad = rauxProd.cantidad;
            rauxPan.vencimiento = rauxProd.vencimiento;
            // escribimos en el archivo Pan.dat
            fwrite(&rauxPan, sizeof(Pan), 1, Panes);
        }

        fread(&rauxProd, sizeof(Producto), 1, PointerProd);
    }
    fclose(PointerProd);
    fclose(Panes);

    // b) Generar un archivo UsarAntes.dat con los productos que tengan más de 1000 unidades en stock ó se venzan el 122023 o antes, con la estructura original

    PointerProd = fopen("BurgerFast.dat", "rb"); // abrimos nuevamente el archivo BurgerFast.dat

    // declaramos un nuevo puntero para el archivo UsarAntes.dat
    FILE *PointerAntes;
    PointerAntes = fopen("UsarAntes.dat", "wb");

    fread(&rauxProd, sizeof(Producto), 1, PointerProd);

    while (!feof(PointerProd))
    {
        if (rauxProd.cantidad > 1000 || rauxProd.vencimiento <= 112023)
        {
            // para escribir el nuevo archivo usamos la estructura original Producto
            fwrite(&rauxProd, sizeof(Producto), 1, PointerAntes);
        }
        fread(&rauxProd, sizeof(Producto), 1, PointerProd);
    }
    fclose(PointerProd);
    fclose(PointerAntes);

    return 0;
}