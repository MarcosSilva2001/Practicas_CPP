/*Ejercicio 11 
Dados 10 números enteros, informar el promedio de los mayores que 100 y la 
suma de los menores que –10. */

#include <iostream>

using namespace std;

int main()
{
	int num, mayores, promedioMayor, sumaMenor=0 ;
	int contMayor=0 , contMenor=0;

	cout <<"Ingrese 10 numeros: "<<endl;
	
	for(int i=0 ; i < 10 ; i++)
	{
		cin>>num;
		
		if(num > 100)
		{
			mayores += num;
			contMayor++;
		}
		else if(num < -10)
		{
			sumaMenor += num;
			contMenor++;
		}

	}
	
	promedioMayor = mayores / contMayor;

	cout <<"El promedio de los mayores a 100 es: "<<promedioMayor<<endl;
	cout <<"La suma de los menores a -10 es: "<<sumaMenor<<endl;


	return 0;
}

