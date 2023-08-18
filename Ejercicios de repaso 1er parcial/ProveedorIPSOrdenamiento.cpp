/*
5) Se tiene un archivo de registros de tamaño fijo de proveedores con nombre ISP_G.DAT. El 
formato del registro de este archivo es el siguiente:
ID_ISP: Número de Proveedor de Internet/ Numérico
TIPO_PROD: Tipo de producto que vende / Un caracter 'A'; 'F' o 'G'. (ADSL– Fibra– 4G)
CPI: Cantidad de Pedidos de instalación / Numérico
CC: Cantidad de Clientes / Numérico
Los registros en el archivo no tienen ningún orden específico y se sabe que no contiene más 
de 100.
Se pide:
- Ordenar el Archivo ISP_G.dat
- Informar por pantalla la cantidad total de clientes, sin importar el proveedor.*/

#include <iostream>
#include <stdio.h>
#define MAX_CANT 100

using namespace std;


struct Proveedores
{
	int ID_ISP;
	char TIPO_PROD;
	int CPI;
	int CC;
};

void inicializar(Proveedores vec[],int tam,Proveedores valorIni);
void insertar(Proveedores vec[],int &len,Proveedores valor,int pos);
void insertarOrdenado(Proveedores vec[],int &len,Proveedores valor);


int main()
{
	//creamos un vector de registros para poder ordenar el archivo
	Proveedores vector[MAX_CANT];
	int len=0;
	
	Proveedores valorInicial;
	valorInicial.ID_ISP=0;
	valorInicial.TIPO_PROD='/';
	valorInicial.CPI=0;
	valorInicial.CC=0;
	
	inicializar(vector,MAX_CANT,valorInicial);
	
	//creamos el puntero al archivo y abrimos para lectura
	FILE *Prov;
	Prov = fopen("ISP_G.DAT","rb");
	
	Proveedores raux;
	int suma=0;
	
	fread(&raux,sizeof(struct Proveedores),1,Prov);
	
	while(!feof(Prov))
	{
		//podemos ordenar por cantidad de clientes
		insertarOrdenado(vector,len,raux);
		
		//mientras voy leyendo el archivo puedo hacer la suma de la cantidad de clientes
		suma = suma + raux.CC;
		
		fread(&raux,sizeof(struct Proveedores),1,Prov);
		
	}
	fclose(Prov);
	
	//abrimos de nuevo el archivo pero esta vez para escribir con los datos ya ordenados del vector de registro
	Prov = fopen("ISP_G.DAT","wb");
	
	for(int i=0; i<len; i++)
	{
		fwrite(&vector[i],sizeof(struct Proveedores),1,Prov);
	}
	fclose(Prov);
	
	cout<<"\nLa cantidad total de clientes es: "<<suma<<endl;



	return 0;
}

void inicializar(Proveedores vec[],int tam,Proveedores valorIni)
{
	for(int i=0; i < tam; i++)
	{
		vec[i] = valorIni;
	}
}
void insertar(Proveedores vec[],int &len,Proveedores valor,int pos)
{
	//mover los elemntos a la derecha para hacer lugar en pos e insertar el valor
	for(int i = len ; i > pos; i--)
	{
		vec[i].ID_ISP = vec[i - 1].ID_ISP;
		vec[i].TIPO_PROD = vec[i - 1].TIPO_PROD;
		vec[i].CPI = vec[i - 1].CPI;
		vec[i].CC = vec[i - 1].CC;
	}
	
	vec[pos].ID_ISP = valor.ID_ISP;
	vec[pos].TIPO_PROD = valor.TIPO_PROD;
	vec[pos].CPI = valor.CPI;
	vec[pos].CC = valor.CC;
	len++;
}

void insertarOrdenado(Proveedores vec[],int &len,Proveedores valor)
{
	//buscar la posicion donde voy a cargar el valor
	int i=0;
	while(i < len && vec[i].CC <= valor.CC)
	{
		i++;
	}
	//cargar el valor
	if(i==len)
	{
		vec[i].ID_ISP = valor.ID_ISP;
		vec[i].TIPO_PROD = valor.TIPO_PROD;
		vec[i].CPI = valor.CPI;
		vec[i].CC = valor.CC;
		len++;
	}
	else insertar(vec,len,valor,i);
}

