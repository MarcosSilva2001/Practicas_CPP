/*Cree un programa que apile numeros ingresados y los muestre en orden inverso */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Nodo
{
	int dato;
	Nodo *sgte;
};

void push(Nodo *&pila, int valor);
int pop(Nodo *&pila);

int main()
{
	Nodo *pila = NULL;
	int num;
	int rdo;
	
	cout<<"\tCargar la PILA\n"<<endl;
		
	cout<<"Ingrese un valor; 0 para finalizar: ";
	cin>>num;
		
	while(num!=0)
	{
		push(pila,num);
		cout<<"Ingrese un valor; 0 para finalizar: ";
		cin>>num;
		
	}

	cout<<"\n\tMostrar los numeros en orden inverso\n"<<endl;
	while(pila!=NULL)
	{
		rdo=pop(pila);
		cout<<"     "<<rdo;
	}

	return 0;
}
void push(Nodo *&pila, int valor)
{
	//pedimos memoria para el nodo
	Nodo *nuevo_nodo = new Nodo();
	
	//cargamos el nodo con los datos
	nuevo_nodo->dato=valor;
	nuevo_nodo->sgte=pila;
	
	//actualizamos la pila para que ahora mire al nuevo nodo
	pila = nuevo_nodo;
	
}

int pop(Nodo *&pila)
{
	//creamos la variable que va a guardar el valor a retornar
	int ret;
	
	//le paso el valor que esta en el campo dato en el nodo que apunta pila
	ret = pila->dato;
	
	//creo una variable auxiliar para guardar la direccion de la cima que apunta pila para poder asi eliminar aux y actualizar pila
	Nodo *aux=pila;
	pila = aux->sgte;
	
	//libero memoria eliminando el nodo de la pila el cual ahora es apuntado por aux
	delete aux;
	
	//retorno el valor que tenia dicho nodo
	return ret;
}


