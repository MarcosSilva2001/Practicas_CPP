/* Ejercicio 5 
Dados dos valores numéricos, informar cual es el mayor y cual es el menor o, 
si ambos valores son iguales emitir un mensaje.*/

#include <iostream>

using namespace std;

int main()
{
	int num1 , num2;
	
	cout<<"-----------A continuacion ingrese dos numeros---------------"<<endl;
	cout<<"\nDigite el primer numero: ";
	cin>>num1;
	cout<<"\nDigite el segundo numero: ";
	cin>>num2;
	
	if(num1 != num2)	
	{
		if(num1 > num2)
		{
			cout<<"\nEl primer numero es mayor que el segundo.";
		}
		else
		{
			cout<<"\nEl primer numero es menor que el segundo.";
		}
	}
	else
	{
		cout<<"\nLos numeros son iguales"<<endl;
	}
	





	return 0;
}

