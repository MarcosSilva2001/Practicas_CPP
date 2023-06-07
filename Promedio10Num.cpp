#include <iostream>
#include <stdlib.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int num, suma=0;
    int i;


    cout<<"A continuacion ingrese 10 numeros por teclado"<<endl;

    for (i = 0; i < 10;  i++)
    {
        cout<<"\nDigite un numero: ";
        cin>>num;

        suma = suma + num;

    }
    
    suma = suma / i;

    cout<<"\nEl promedio de los 10 valores ingresados es: \n"<<suma<<endl;


    system("pause");
    return 0;
}
