#include <iostream>
#include <stdlib.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int nota;
    int sumaProm=0;

    for(int i=1; i<4; i++)
    {
        cout<<" Ingrese la nota "<<i<<":  ";
        cin>>nota;

        sumaProm=sumaProm + nota;
    }
    
    sumaProm= sumaProm/3;

    cout <<"\nEl promedio de las notas ingresadas es: "<<sumaProm<< endl;


    system("pause");
    return 0;
}
