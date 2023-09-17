/*
	Se tiene las ventas del año de un retail, dividido en 3 archivos, uno por trimestre (1erTrimestre.dat,2doTrimestre.dat y 3erTrimestre.dat)
	ordenados por código de producto.
	- Código de producto: 999999
	- Descripción
	- Unidades vendidas: 99999
	Se pide:
	a) Obtener un único archivo con todas las ventas ordenado por código de producto 2018.dat
*/

#include <iostream>
#include <stdio.h>

using namespace std;

struct Ventas_Prod
{
	int codigo;
	char descripcion[30];
	int vendidas;
};

int main()
{
	FILE *Primer;
	FILE *Segundo;
	FILE *Tercer;
	FILE *Nuevo;
	
	Primer=fopen("1erTrimestre.dat","rb");
	Segundo=fopen("2doTrimestre.dat","rb");
	Tercer=fopen("3erTrimestre.dat","rb");
	Nuevo=fopen("NuevoVentas.dat","wb");
	
	Ventas_Prod rauxP;
	Ventas_Prod rauxS;
	Ventas_Prod rauxT;
		
	fread(&rauxP,sizeof(Ventas_Prod),1,Primer);
	fread(&rauxS,sizeof(Ventas_Prod),1,Segundo);
	fread(&rauxT,sizeof(Ventas_Prod),1,Tercer);
	
	while((!feof(Primer)) && (!feof(Segundo)) && (!feof(Tercer)))
	{
		if(rauxP.codigo < rauxS.codigo)
		{
			if(rauxP.codigo < rauxT.codigo)
			{
				fwrite(&rauxP,sizeof(Ventas_Prod),1,Nuevo);	
				fread(&rauxP,sizeof(Ventas_Prod),1,Primer);
				
			}else 
			{
				fwrite(&rauxT,sizeof(Ventas_Prod),1,Nuevo);	
				fread(&rauxT,sizeof(Ventas_Prod),1,Tercer);
			}
					
		}else 
		{
			if(rauxS.codigo < rauxT.codigo)
			{
				fwrite(&rauxS,sizeof(Ventas_Prod),1,Nuevo);
				fread(&rauxS,sizeof(Ventas_Prod),1,Segundo);
			}else 
			{
				fwrite(&rauxT,sizeof(Ventas_Prod),1,Nuevo);	
				fread(&rauxT,sizeof(Ventas_Prod),1,Tercer);
			}
			
		}	
	}
	
	while(!feof(Primer))
	{
		fwrite(&rauxP,sizeof(Ventas_Prod),1,Nuevo);	
		fread(&rauxP,sizeof(Ventas_Prod),1,Primer);
	}
	while(!feof(Segundo))
	{
		fwrite(&rauxS,sizeof(Ventas_Prod),1,Nuevo);	
		fread(&rauxS,sizeof(Ventas_Prod),1,Segundo);
	}
	while(!feof(Tercer))
	{
		fwrite(&rauxT,sizeof(Ventas_Prod),1,Nuevo);	
		fread(&rauxT,sizeof(Ventas_Prod),1,Tercer);
	}
	fclose(Primer);
	fclose(Segundo);
	fclose(Tercer);
	fclose(Nuevo);

	return 0;
}

