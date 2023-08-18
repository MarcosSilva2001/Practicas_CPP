/* Este es una plantilla basica de como:
# inicializar un vector en cero
# cargar un vector
# mostar el vector cargado
*/

#include <iostream>

using namespace std;

void cargaVector(int vec[], int &len1, int tam);
void mostrarVector(int vec[], int tam);


int main()
{
    int n;
    cout << "Ingrese la cantidad de posiciones para su vector: ";
    cin >> n;
    int vector[n] = {0}, len = 0; //con vector[n]={0} inicializamos todas las posiciones en cero sin usar un for 
  
	//invoco la funcion cargarVector
    cargaVector(vector, len, n);
    //invoco la funcion mostrarVector
    mostrarVector(vector, n);
    
    

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

void mostrarVector(int vec[], int tam)
{
    cout << "________Mostrar el vector cargado________" << endl;
    for (int i = 0; i < tam; i++)
    {
        cout << "  " << vec[i];
    }
}

