/*
Desarrolle los siguientes PROCEDIMIENTOS y defina los parámetros:
a- Dadas 2 Colas de enteros (Cola A y Cola B) genere la UNION de ambas en Cola C.

*/
#include <iostream>
#include <stdio.h>
using namespace std;

struct Nodo
{
    int info;
    Nodo *sgte;
};

void insertar(Nodo *&cfin, Nodo *&cfte,int valor);
int suprimir(Nodo *&cfte, Nodo *&cfin);
void Union();

int main(int argc, char const *argv[])
{

    Union(); 


    return 0;
}

void insertar(Nodo *&cfte, Nodo *&cfin, int valor)
{
    // crear Nodo ----> pedido de memoria
    Nodo *nuevo_nodo = new Nodo();

    // cargarlo con el valor
    nuevo_nodo->info = valor;
    nuevo_nodo->sgte = NULL;

    // Encolar (agregar los elementos por el final de la cola) se mueve colafin
    if (cfte == NULL)
    {
        cfte = nuevo_nodo;
    }
    else
    {
        cfin->sgte = nuevo_nodo;
    }
    cfin = nuevo_nodo;
}

int suprimir(Nodo *&cfte, Nodo *&cfin)
{
    // guardar el valor de retorno
    int retorno;
    retorno = cfte->info;

    // acomodar la cola
    Nodo *aux = cfte;
    cfte = cfte->sgte;
    if (cfte == NULL)
    {
        cfin = NULL;
    }

    // liberar el nodo delete
    delete aux;

    // retornar el valor
    return retorno;
}

void Union()
{
    Nodo *cfteA=NULL;
    Nodo *cfinA=NULL;
    //cargar cola A
    insertar(cfteA,cfinA,1);
    insertar(cfteA,cfinA,3);
    insertar(cfteA,cfinA,4);
    insertar(cfteA,cfinA,6);
    
    Nodo *cfteB=NULL;
    Nodo *cfinB=NULL;
    //cargar cola B
    insertar(cfteB,cfinB,7);
    insertar(cfteB,cfinB,2);
    insertar(cfteB,cfinB,9);
    insertar(cfteB,cfinB,11);

    Nodo *cfteC=NULL; 
    Nodo *cfinC=NULL;

    //cargamos los valores de la cola A en la cola C
    int valorA;
    while (cfteA!=NULL)
    {
        valorA=suprimir(cfteA,cfinA);
        insertar(cfteC,cfteC,valorA);
    }

    //cargamos los valores de la cola B en la cola C
    int valorB;
    while (cfteB!=NULL)
    {
        valorB=suprimir(cfteB,cfinB);
        insertar(cfteC,cfteC,valorB);
    }

    //mostramos la nueva cola C
    int valorC;
    cout<<"-------------- La cola C -----------------"<<endl;

    while (cfteC!=NULL)
    {
        valorC = suprimir(cfteC,cfinC);
        cout << "  " << valorC << endl;
    }
    
    
}
