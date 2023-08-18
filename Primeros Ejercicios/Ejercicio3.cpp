/*Ejercicio 3 
Dado valor numérico entero que se ingresa por teclado, se pide informar: 
? La quinta parte de dicho valor, 
? el resto de la división por 5 y 
? la séptima parte de la quinta parte. */

#include <iostream>

using namespace std;

int main()
{
	int valor;
	cout<<"Ingrese un valor: ";
	cin>>valor;
	
	float quintaParte= valor / 5.0;
	int resto= valor % 5;
	float septimaParte= valor / 7.0;
	
	
	cout<<"\nLa quinta parte del numero es: "<<quintaParte<<endl;
	cout<<"El resto de dividir por 5 es: "<<resto<<endl;
	cout<<"La septima parte del numero es: "<<septimaParte<<endl;
	

	return 0;
}

