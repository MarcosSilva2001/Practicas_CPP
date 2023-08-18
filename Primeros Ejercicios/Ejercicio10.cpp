/*Ejercicio 10
Dados dos valores numéricos enteros, calcular e informar su producto
mediante sumas sucesivas. */

#include <iostream>

using namespace std;

int main()
{
	int num1, num2;
	int SumaSucesiva=0;
	
	cout <<"Ingrese un numero: ";
	cin >>num1;
	cout << "Ingrese otro numero: ";
	cin >>num2;
	
	for (int i=0 ; i < num2 ; i++)
	{
		SumaSucesiva = SumaSucesiva + num1;
	}
	
	cout << "\nEl producto de los numeros ingresados es:  "<<SumaSucesiva<<endl;



	return 0;
}

