/*Vectores: Busqueda Binaria */

#include <iostream>

using namespace std;

const int N=10;

int BusquedaBinaria(int vec[],int len,int valor);

int main()
{
	//para utilizar la busqueda binaria necesitamos un vector ordenado
	int vector[N]={2,4,7,8,11,15};
	int len=6;
	
	
	//busquemos la posicion del numero 11 en el vector
	
	int pos1 = BusquedaBinaria(vector,len,11);
	
	cout<<"El numero 11 buscado esta en la posicion ["<<pos1<<"]"<<endl;


	return 0;
}

int BusquedaBinaria(int vec[],int len,int valor)
{
	int pos=-1;
	int primero=0;
	int medio;
	int ultimo=len -1;
	
	while (primero <= ultimo && pos==-1)
	{
		medio = (primero + ultimo)/2;
		
		if(vec[medio] == valor)
		{
			pos = medio;
		}
		else 
		{
			if(valor > vec[medio])
			{
				primero = medio + 1;
			}else
			{
				ultimo = medio - 1;
			}
		}
	}
	
	return pos;
}

