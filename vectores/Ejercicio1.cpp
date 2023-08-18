/* Ejercicio 1) Dado un vector Prueba 1 y su len, busque el valor mínimo e imprímalo por pantalla*/

#include <iostream>

using namespace std;

void cargaVector(int vec[], int &len1, int tam);
int minimoValor(int vec[],int len1,int pos);

int main()
{
    int n;
    cout << "Ingrese la cantidad de posiciones para su vector: ";
    cin >> n;
    int Prueba1[n] = {0}, len = 0;
  
	//invoco la funcion cargarVector
    cargaVector(Prueba1, len, n);
    
    //delcalo la variable posMin y le asigo la funcion minimoValor
    int posMin = minimoValor(Prueba1,len,posMin);
    
    cout <<"\n\nEl minimo valor ingresado es: " << Prueba1[posMin] <<endl;
    cout <<"Su posicion es: " << posMin + 1<<endl;

    return 0;
}

void cargaVector(int vec[], int &len1, int tam)
{
    cout << "\nA continuacion ingrese los valores para su vector de [" << tam << "] posiciones: " << endl;

    for (int i = 0; i < tam; i++)
    {
        cin >> vec[i];
        len1++;
    }
}

int minimoValor(int vec[],int len1,int pos)
{
	int minimo;
	pos=0;
	
	for(int i=1; i < len1; i++)
	{
		minimo=vec[pos];
		
		if(vec[i] < minimo)
		{
			minimo=vec[i];
			pos=i;
		}
	}
	
	return pos;		
	
}
