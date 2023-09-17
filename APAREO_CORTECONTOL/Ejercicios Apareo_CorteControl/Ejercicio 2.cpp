/*
	Se tiene un archivo de los productos almacenados en el ala este del depósito Este.dat (ordenado por
	código de producto) y otro archivo de igual tipo con los productos del ala oeste Oeste.dat. (ordenado
	por código de producto).
	- Código de producto: 999999
	- Descripción
	- Stock: 99999
	Se pide:
	a) Obtener un único archivo con todos los productos y su stock ordenado por código de producto
*/

#include <iostream>
#include <stdio.h>

using namespace std;

struct Producto
{
	int codigo;
	char descripcion[30];
	int stock;
};

int main()
{
	FILE *Este;
	FILE *Oeste;
	FILE *Nuevo;
	
	Este=fopen("Este.dat","rb");
	Oeste=fopen("Oeste.dat","rb");
	Nuevo=fopen("Nuevo.dat","wb");
	
	Producto rauxE;
	Producto rauxO;
	
	fread(&rauxE,sizeof(Producto),1,Este);
	fread(&rauxO,sizeof(Producto),1,Oeste);
	
	while((!feof(Este)) && (!feof(Oeste)))
	{
		if(rauxE.codigo < rauxO.codigo)
		{
			fwrite(&rauxE,sizeof(Producto),1,Nuevo);
			fread(&rauxE,sizeof(Producto),1,Este);	
		
		}else 
		{
			fwrite(&rauxO,sizeof(Producto),1,Nuevo);
			fread(&rauxO,sizeof(Producto),1,Oeste);
		}	
	}
	
	while(!feof(Este))
	{
		fwrite(&rauxE,sizeof(Producto),1,Nuevo);
		fread(&rauxE,sizeof(Producto),1,Este);
	}
	while(!feof(Oeste))
	{
		fwrite(&rauxO,sizeof(Producto),1,Nuevo);
		fread(&rauxO,sizeof(Producto),1,Oeste);
	}
	fclose(Este);
	fclose(Oeste);
	fclose(Nuevo);

	return 0;
}

