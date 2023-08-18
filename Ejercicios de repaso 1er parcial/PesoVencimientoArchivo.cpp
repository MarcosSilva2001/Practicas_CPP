/*
Se tiene un archivo de registros de tamaño fijo de productos a la venta en un depósito con 
nombre PROD_DEP.DAT. El formato del registro de este archivo es el siguiente:
COD_PROD: Código del producto / Numérico
PESO: Peso en kilogramos del producto / Numérico
VTO: Fecha de vencimiento del producto / Numérico Formato ‘MMAAAA’
Se pide realizar un programa que lea ese archivo y genere dos archivos nuevos. El primero 
(PESADOS.dat) que contenga todos los productos de más de 50 kg. Con el siguiente 
formato:
COD_PROD: Código del producto / Numérico
VTO: Fecha de vencimiento del producto / Numérico Formato ‘MMAAAA’
El segundo (VENC2021.dat) que contenga los productos que se vencen en el año 2021 con el 
siguiente formato:
COD_PROD: Código del producto / Numérico
PESO: Peso en kilogramos del producto / Numérico
VTO: Fecha de vencimiento del producto / Numérico Formato ‘MMAAAA’*/

#include <iostream>
#include <stdio.h>

struct Producto
{
	int Codigo; //Entero
	float Peso; //Decimal
	int VTO; //Numérico Formato ‘MMAAAA’
	
};
struct Pesado
{
	int Codigo;
	int VTO;
	
};


int main()
{
	//creamos el puntero al archivo y abrimos para lectura
	FILE *Prod;
	Prod = fopen("PROD_DEP.DAT","rb");
	Producto raux;
	
	//creamos los dos archivos que piden
	FILE *Pesa;
	Pesa = fopen("PESADOS.dat","wb");
	Pesado rauxP;
	
	FILE *Venc;
	Venc = fopen("VENC2021.dat","wb");
	
	fread(&raux,sizeof(struct Producto),1,Prod);
	while(!feof(Prod))
	{
		if(raux.Peso > 50.0)
		{
			rauxP.Codigo = raux.Codigo;
			rauxP.VTO = raux.VTO;
			
			fwrite(&rauxP,sizeof(Pesado),1,Pesa);
			
		}else
		{
			if(raux.VTO >= 012021 && raux.VTO <= 122021)
			{
				fwrite(&raux,sizeof(Pesado),1,Venc);
			}
		
		}
		
		fread(&raux,sizeof(struct Producto),1,Prod);
		
	}
	fclose(Prod);
	fclose(Pesa);
	fclose(Venc);

	
	return 0;
}


