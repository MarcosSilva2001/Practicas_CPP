/* Ejercicio 7 
Dado un triángulo representado por sus lados lado1, lado2 y lado3, determinar 
e indicar según corresponda: “equilátero”, “isósceles” o “escálenos”.*/

#include <iostream>

using namespace std;

int main()
{
	int l1, l2, l3;
	
	cout<<"Ingrese los lados para formar un triangulo: "<<endl;
	cin>>l1;
	cin>>l2;
	cin>>l3;
	
	//primero que nada verificamos que los valores ingresados forman un triangulo
	if((l1+l2 > l3) && (l1+l3 > l2) & (l2+l3 > l1))	
	{
		
		if(l1==l2 && l2==l3)
		{
			cout<<"\nEl tringulo que se forma es Equilatero...";
		} 
		else  if(l1==l2 || l1==l3 || l2==l3) 
			{
				cout<<"\nEl tringulo que se forma es Isoceles...";
			}
			else 
			{
				cout<<"\nEl tringulo que se forma es Escaleno...";
			}	
		
	}
	else
	{
		cout<<"\nLos valores proporcionados no forman un triangulo."<<endl;
	}
	
	



	return 0;
}

