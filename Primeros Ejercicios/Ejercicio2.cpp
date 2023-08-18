/*Ejercicio 2 
Dada una terna de números naturales que representan el día, el mes y el año 
de una determinada fecha informarla como un solo número natural de 8 dígitos 
(aaaammdd).*/

#include <iostream>

using namespace std;

int main()
{
	int dia,mes,anio;
	int fecha;
	
	cout<<"Ingrese el dia: ";
	cin>>dia;
	cout<<"Ingrese el mes: ";
	cin>>mes;
	cout<<"Ingrese el año: ";
	cin>>anio;

	fecha= anio*10000 + mes*100 + dia;
	
	cout<<"\nLa fecha en formato AAAAMMDD es: "<<fecha<<endl;
		
	
	
	return 0;
}
