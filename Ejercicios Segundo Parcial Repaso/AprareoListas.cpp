/*Dadas 2 Listas de enteros (Lista A y Lista B) genere la UNION de ambas en Lista C.*/

#include <iostream>

using namespace std;
struct Nodo
{
    int info;
    Nodo *sgte;
};

void UnionListas(Nodo *lista1,Nodo *lista2,Nodo *&lista3);
void mostrar(Nodo *lista);
void liberar(Nodo *&lista);

int main()
{
    Nodo *lista1 = NULL;
    Nodo *lista2 = NULL;
    Nodo *lista3 = NULL;
    
    UnionListas(lista1,lista2,lista3);
    mostrar(lista3);
    liberar(lista3);

    return 0;
}


void insertarOrdenado(Nodo*&Lista,int valor){
   //crear el nodo
   Nodo*nuevo=new Nodo();
   //cargar el nodo
   nuevo->info=valor;
   nuevo->sgte=NULL; //porque no s� d�nde va
   //Enlazarlo
   Nodo*aux=Lista; //recorro sin modificar la lista!!!
   Nodo*ant=NULL; //este me va a permitir enlazar
   //BUSCAR!!!!!!!!!!!!!!!!!!!
   while(aux!=NULL&&aux->info<valor){
      ant=aux;
      aux=aux->sgte; //avanzabamos en la lista
   }
   if(ant==NULL){//No entr� al while 1)lista vac�a 2)debo insertar al principio
      Lista=nuevo;
   }else{//Entr� al while, 1) en alguna parte de la lista 2)agregar al final
      ant->sgte=nuevo;
   }
   nuevo->sgte=aux;
}

void mostrar(Nodo*Lista){
   Nodo*aux=Lista;
   while(aux!=NULL){
      cout<<"  "<<aux->info;
      aux=aux->sgte;
   }
}

void liberar(Nodo*&Lista){
   Nodo*aux;
   while(Lista!=NULL){
      aux=Lista;
      Lista=Lista->sgte;
      delete(aux);
   }
}


void UnionListas(Nodo *lista1,Nodo *lista2,Nodo *&lista3)
{
    //cargamos las listas para tener algunos valores de prueba
    insertarOrdenado(lista1,2);
    insertarOrdenado(lista1,7);
    insertarOrdenado(lista1,9);
    insertarOrdenado(lista1,1);
    insertarOrdenado(lista1,5);

    insertarOrdenado(lista2,8);
    insertarOrdenado(lista2,11);
    insertarOrdenado(lista2,3);
    insertarOrdenado(lista2,19);

    //le asignamos la lista1 a lista3
    lista3 = lista1;
    //creamos un puntero auxiliar a lista2 que nos ayude a cargar lista3 con lo que tiene lista 2
    Nodo *aux = lista2;
    while (aux!=NULL)
    {
        insertarOrdenado(lista3,aux->info);
        aux=aux->sgte;
    }
    
}