/*Ejercicio 2 
Dada una terna de n�meros naturales que representan el d�a, el mes y el a�o 
de una determinada fecha informarla como un solo n�mero natural de 8 d�gitos 
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
	cout<<"Ingrese el a�o: ";
	cin>>anio;

	fecha= anio*10000 + mes*100 + dia;
	
	cout<<"\nLa fecha en formato AAAAMMDD es: "<<fecha<<endl;
		
	
	
	return 0;
}
