/* Ejercicio 15 
Dados 10 valores numéricos, informar cual es el el mayor.*/

#include <iostream>

using namespace std;

int main()
{
	int mayor=-999999, num=0;
	
	cout <<"Ingrese 10 valores: "<<endl;
	
	for(int i=0 ; i < 10 ; i++)
	{
		cin>>num;
		
		if(num > mayor)
		{
			mayor=num;	
		}
		
	}

 	cout <<"\nEl mayor numero ingresado es: "<< mayor <<endl;



	return 0;
}

