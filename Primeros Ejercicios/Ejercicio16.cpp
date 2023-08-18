/* Ejercicio 16 
Dados n valores numéricos, informar el mayor, el menor y en que posición del 
conjunto fueron ingresados cada uno de ellos*/

#include <iostream>

using namespace std;

int main()
{
	int n, menor, mayor, posMayor;
	
	cout << "Ingrese un valor para n: ";
	cin >> n;
	
	int valores[n];
	
	cout <<"\n_________Acontinuacion debera ingresar "<< n <<" valores_________"<<endl;
	
	for(int i=0; i < n; i++)
	{
		cin>>valores[i];
		
		if(i==0)
		{
			mayor = valores[i];
			menor = valores[i];
			posMayor = i+1;
		}
		else if (valores[i] > mayor)
			{
				mayor = valores[i];
				posMayor = i+1;
			}
			if(valores[i] < menor)
			{
				menor = valores[i];
			}
	}

	cout <<"\nEl mayor valor ingresasdo es: "<< mayor <<endl;
	cout <<"Su pocicion es: "<< posMayor <<endl;
	


	return 0;
}

