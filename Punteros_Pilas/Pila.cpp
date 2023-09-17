/*Tema: Pilas y Punteros*/

#include <iostream>
#include <stdio.h>

using namespace std;

//Declaramos el nodo
struct Nodo
{
	int info; // contiene el dato del nodo
	Nodo *sgte; //puntero que apunta a la direccion del proximo nodo
};

void push(Nodo *&pila, int valor);
int pop(Nodo *&pila);

int main()
{
	Nodo *pila = NULL; //declaramos puntero a la pila y lo iniciamos que apunte a vacio (NULL)
	
	int num;
	int rdo;
	
	cout <<"              Cargar la Pila 						"<<endl;
	cout <<"\nIngrese un valor o finalice con 0: ";
	cin >>num;
	
	while(num!=0)
	{
		push(pila,num);
		cout <<"Ingrese un valor o finalice con 0: ";
		cin >>num;
		
	}
	
	cout <<"\n               Extraer  valores de la Pila" <<endl<<endl;
	while(pila != NULL)
	{
		rdo = pop(pila);
		cout <<"El valor extraido es: "<< rdo <<endl;
		
	}
	



	return 0;
}

void push(Nodo *&pila, int valor)
{
	//Crear Nodo (Pedir memoria)
	Nodo* nuevo = new Nodo();
	
	//cargar el Nodo
	nuevo -> info = valor; //en el nodo campo info le paso el valor
	nuevo -> sgte = pila; // al puntero sgte del nodo le paso la direccion donde apunta el puntero pila
	
	//Conectar
	pila = nuevo; //actualizamos pila para que mire al que acaba de entrar en la pila , es el que tiene "nuevo"
	
}

int pop(Nodo *&pila)
{
	//Crear variable de retorno
	int resultado;
	
	//Guardo el valor de retorno
	resultado = pila -> info;
	
	//Librero memoria
	Nodo* aux = pila; //creo un puntero auxiliar que almacene la direccion que apunta pila para no eliinar lo que tiene pila y solo eliminar aux
	pila = aux -> sgte; // actualizo pila con la direccion que apunta al siguiente nodo
	delete aux; 
	
	//Retorno el valor
	return resultado;
	
}
