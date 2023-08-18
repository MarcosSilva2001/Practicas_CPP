/* Ejercicio 14 
 Dado un valor numérico entero m, determinar e imprimir un listado con los m
primeros múltiplos de 3 que no sean múltiples de 5. */

#include <iostream>

using namespace std;

int main()
{
	int m, numero=1;
	int contador=0;
	
	cout <<"Ingrese el valor para m: " ;
	cin >>m;
	
	cout <<"\nLos primeros " << m <<" multiplos de 3 que no sean multiplos de 5 son: "<<endl;
	
	while(contador < m)
	{
		if((numero % 3 == 0) && (numero % 5 != 0))
		{
			cout <<numero<<endl;
			contador++;
		}
		numero++;
	} 



	return 0;
}

