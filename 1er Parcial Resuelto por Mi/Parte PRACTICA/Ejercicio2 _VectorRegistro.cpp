/* 
1) dado un vector de productos que contiene el codigo de producto, codigo de serie y cantidad de unidades disponibles en deposito
(hay un maximo de 200 productos en la empresa). Determinar:
a) El producto que mas unidades tiene
b) El producto cuyo codigo de serie es 7000
c) Promedio de unidades en el deposito por producto.
 */

#include <iostream>

using namespace std;

struct Producto
{
	int codProducto;
	int codSerie;
	int cantidadDisponible;	
};


int MasUnidades(Producto vec[],int len);
void CodeSerie7000(Producto vec[], int len);
void promedio(Producto vec[],int len);


int main()
{
	//suponemos que el vector esta cargado len posiciones
	Producto vec[200];
	int len;
	
	//llamamos la funcion 
	int masUni = MasUnidades(vec,len);
	cout << "El producto con mas unidades disponibles es: " << vec[masUni].codProducto <<endl;

	//llamamos al procedimiento CodeSerie7000
	CodeSerie7000(vec,len),
	
	//llamamos procedimento promedio
	promedio(vec,len);
	
	

	return 0;
}

//a) El producto que mas unidades tiene
int MasUnidades(Producto vec[],int len)
{
	int pos = 0;
	for(int i=1; i < len; i++)
	{
		if(vec[pos].cantidadDisponible < vec[i].cantidadDisponible)
		{
			pos = i;	
		}
	}
	return pos;
}

//b) El producto cuyo codigo de serie es 7000
void CodeSerie7000(Producto vec[], int len)
{
	
	for(int i = 0 ; i < len; i++)
	{
		if(vec[i].codSerie == 7000)
		{
			cout << "El producto que tiene codigo de serie 7000 es: " << vec[i].codProducto <<endl;
		}
	}
	
}
//c) Promedio de unidades en el deposito por producto.
void promedio(Producto vec[],int len)
{
	int suma=0;
	
	for(int i = 0; i < len; i++)
	{
		suma = suma +vec[i].cantidadDisponible;
	
	}
	
	cout << "El promedio de unidades en el deposito es: " << suma/len <<endl;
}
