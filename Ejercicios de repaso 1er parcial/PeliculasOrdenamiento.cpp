/*
6) Se tiene un archivo de pel�culas infantiles en cartelera en los cines de Buenos Aires para las 
vacaciones de invierno PelInf.DAT (Sin Orden)
- C�digo de Pel�cula: 999999
- Cantidad de Cines en las que se present�: 99999
- Cantidad de entradas vendidas: 999999999
Se pide:
a) Ordenar el Archivo por Entradas Vendidas
b) Listar las 10 pel�culas que m�s entradas vendidas tuvieron (al listar incluir toda la 
informaci�n referente a la pel�cula)
Nota: S�lo debe leer 1 vez el archivo. Se sabe que no hay m�s de 50 pel�culas*/
#include <iostream>
#include <stdio.h>
#define MAX_CANT 50

using namespace std;

// Definici�n de la estructura de datos
struct Peliculas
{
	int codPelicula;
	int cantPresentadas;
	int cantVendidas;
};

// Declaraci�n de funciones
void inicializar(Peliculas vec[],int tam,Peliculas valorIni);
void insertar(Peliculas vec[],int &len,Peliculas valor,int pos);
void insertarOrdenado(Peliculas vec[],int &len,Peliculas valor);


int main()
{
	//creamos un vector de registros para poder ordenar el archivo
	Peliculas vector[MAX_CANT];
	int len=0;
	
	// Valor inicial para el vector de registros
    Peliculas valorInicial;
    valorInicial.codPelicula = 0;
    valorInicial.cantPresentadas = 0;
    valorInicial.cantVendidas = 0;

    // Inicializaci�n del vector
    inicializar(vector, MAX_CANT, valorInicial);

    // Apertura del archivo para lectura
    FILE *Pelis;
    Pelis = fopen("PelInf.DAT", "rb");

    Peliculas raux;

    // Lectura de registros desde el archivo
    fread(&raux, sizeof(struct Peliculas), 1, Pelis);

    while (!feof(Pelis)) 
	{
        // Ordenamiento e inserci�n en el vector de mator a menor
        insertarOrdenado(vector, len, raux);
        
        fread(&raux, sizeof(struct Peliculas), 1, Pelis);
    }
    fclose(Pelis);

    // Apertura del archivo para escritura
    Pelis = fopen("PelInf.DAT", "wb");

    // Escritura de registros ordenados en el archivo
    for (int i = 0; i < len; i++) 
	{
        fwrite(&vector[i], sizeof(struct Peliculas), 1, Pelis);
    }
    fclose(Pelis);
    
    //listar las 10 peliculas con mas entradas vendidas
	cout<<"------------- Las 10 peliculas que mas ventas tuvieron son --------------"<<endl;

    for(int i=0 ; i < 10; i++)
    {
    	cout << vector[i].cantVendidas << endl;
	}

   

    return 0;
}

// Funci�n para inicializar un vector de registros
void inicializar(Peliculas vec[], int tam, Peliculas valorIni) 
{
    for (int i = 0; i < tam; i++) 
	{
        vec[i] = valorIni;
    }
}

// Funci�n para insertar un registro en una posici�n espec�fica
void insertar(Peliculas vec[], int &len, Peliculas valor, int pos) 
{
    for (int i = len; i > pos; i--) 
	{
        vec[i].codPelicula = vec[i - 1].codPelicula;
        vec[i].cantPresentadas = vec[i - 1].cantPresentadas;
        vec[i].cantVendidas = vec[i - 1].cantVendidas;
        
    }

    vec[pos].codPelicula = valor.codPelicula;
    vec[pos].cantPresentadas = valor.cantPresentadas;
    vec[pos].cantVendidas = valor.cantVendidas;
    len++;
}

// Funci�n para insertar un registro en orden seg�n CC
void insertarOrdenado(Peliculas vec[], int &len, Peliculas valor) 
{
    int i = 0;
    while (i < len && vec[i].cantVendidas >= valor.cantVendidas) 
	{
        i++;
    }

    if (i == len) 
	{
        vec[i].codPelicula = valor.codPelicula;
    	vec[i].cantPresentadas = valor.cantPresentadas;
    	vec[i].cantVendidas = valor.cantVendidas;
    	len++;
    	
    } else insertar(vec, len, valor, i);
}

