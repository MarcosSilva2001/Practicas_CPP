/*
4) Se tiene un archivo de registros de tamaño fijo de proveedores con nombre ISP_G.DAT. El
formato del registro de este archivo es el siguiente:
ID_ISP: Número de Proveedor de Internet/ Numérico
TIPO_PROD: Tipo de producto que vende / Un caracter 'A'; 'F' o 'G'. (ADSL– Fibra– 4G)
CPI: Cantidad de Pedidos de instalación / Numérico
CC: Cantidad de Clientes / Numérico
Se pide:
Realizar un programa que lea ese archivo y genere un archivo PROV_A.dat que contenga los
Proveedores de la categoría ADSL, otro con los de Fibra, PROV_F.dat y un tercero con los de
4G PROV_G.dat. El formato del registro de estos archivos es el siguiente:
ID_ISP: Número de Proveedor de Internet/ Numérico
CPI: Cantidad de Pedidos de instalación / Numérico
CC: Cantidad de Clientes / Numérico
*/
#include <iostream>
#include <stdio.h>

using namespace std;

struct Proveedores
{
    int ID_ISP;     // Número de Proveedor de Internet (Numérico)
    char TIPO_PROD; // Tipo de producto que vende: 'A' (ADSL), 'F' (Fibra) o 'G' (4G)
    int CPI;        // Cantidad de Pedidos de instalación (Numérico)
    int CC;         // Cantidad de Clientes (Numérico)
};

struct Tipos
{
    int ID_ISP;
    int CPI;
    int CC;
};

int main()
{
    // Archivo ISP_G.DAT apertura en modo lectura
    FILE *Prov;
    Prov = fopen("ISP_G.DAT", "rb");
    Proveedores raux;

    // Archivos PROV_A.DAT, PROV_F.DAT y PROV_G.DAT apertura en modo escritura
    FILE *ProvA;
    ProvA = fopen("PROV_A.DAT", "wb");
    Proveedores rauxA;

    FILE *ProvF;
    ProvF = fopen("PROV_F.DAT", "wb");
    Proveedores rauxF;

    FILE *ProvG;
    ProvG = fopen("PROV_G.DAT", "wb");
    Proveedores rauxG;

    // Lectura del archivo ISP_G.DAT y procesamiento para generar los archivos requeridos
    fread(&raux, sizeof(Proveedores), 1, Prov);
    while (!feof(Prov))
    {
        if (raux.TIPO_PROD == 'A')
        {
            rauxA.ID_ISP = raux.ID_ISP;
            rauxA.CPI = raux.CPI;
            rauxA.CC = raux.CC;
            fwrite(&rauxA, sizeof(Tipos), 1, ProvA);
        }
        else if (raux.TIPO_PROD == 'F')
        {
            rauxF.ID_ISP = raux.ID_ISP;
            rauxF.CPI = raux.CPI;
            rauxF.CC = raux.CC;
            fwrite(&rauxF, sizeof(Tipos), 1, ProvF);
        }
        else if (raux.TIPO_PROD == 'G')
        {
            rauxG.ID_ISP = raux.ID_ISP;
            rauxG.CPI = raux.CPI;
            rauxG.CC = raux.CC;
            fwrite(&rauxG, sizeof(Tipos), 1, ProvG);
        }

        fread(&raux, sizeof(Proveedores), 1, Prov);
    }

    fclose(Prov);
    fclose(ProvA);
    fclose(ProvF);
    fclose(ProvG);

    return 0;
}
