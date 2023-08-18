/*Ejercicio 3*/

#include <iostream>
#include <stdio.h>
#define N 100

using namespace std;

struct Proveedores 
{
	int NRO_PROV;
	char TIPO_PROD; // 'A' ; 'F' o 'G'
	int  CPE;	
};

void inicializar(Proveedores vec[],int tam,Proveedores valorInicial);
void insertar(Proveedores vec[],int &len,Proveedores valor,int pos);
void insertarOrdenado(Proveedores vec[],int &len,Proveedores valor);

int main()
{
	//defino los vectores de registros  para poder ordenar
	Proveedores vec1[N];
	int len1;
	Proveedores vec2[N];
	int len2;
	
	Proveedores valorIni;
	valorIni.NRO_PROV = 0;
	valorIni.TIPO_PROD = '0';
	valorIni.CPE = 0;
	
	inicializar(vec1,N,valorIni);
	inicializar(vec2,N,valorIni);
	
	//creamos los punteros para los archivos
	FILE *Prov;
	Prov = fopen("Prov_AllProd.dat","rb");
	Proveedores raux;
	
	FILE *ProvA;
	FILE *ProvG;
		
	fread(&raux,sizeof(Proveedores),1,Prov);
	while(!feof(Prov))
	{
		//ordenamos los vectores de registros de manera decendente por cantidad de articulos entregados CPE
		if(raux.TIPO_PROD=='A')
		{
			insertarOrdenado(vec1,len1,raux);
			
		}else 
		{
			if(raux.TIPO_PROD=='G')
			{
				insertarOrdenado(vec2,len2,raux);	
			}
		}
		
		fread(&raux,sizeof(Proveedores),1,Prov);
	}
	fclose(Prov);
	
	//abrimos los archivos para escribir de manera ordanada
	ProvA = fopen("Prov_A.dat","wb");
	ProvG = fopen("Prov_G.dat","wb");
	
	//escritura del archivo Prov_A.dat
	for(int i=0 ; i <len1; i++)
	{
		fwrite(&vec1[i],sizeof(Proveedores),1,ProvA);
	}
	fclose(ProvA);
	
	//escritura del archivo Prov_G.dat
	for(int i=0 ; i <len2; i++)
	{
		fwrite(&vec2[i],sizeof(Proveedores),1,ProvG);
	}
	fclose(ProvG);

	
	

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
		vec[i].NRO_PROV = vec[i - 1].NRO_PROV;
		vec[i].TIPO_PROD = vec[i - 1].TIPO_PROD;
		vec[i].CPE = vec[i - 1].CPE;
	
	}
	
	vec[pos].NRO_PROV = valor.NRO_PROV;
	vec[pos].TIPO_PROD = valor.TIPO_PROD;
	vec[pos].CPE = valor.CPE;
	
	len++;
}

void insertarOrdenado(Proveedores vec[],int &len,Proveedores valor)
{
	//buscar la posicion donde voy a cargar el valor
	int i=0;
	while(i < len && vec[i].CPE >= valor.CPE)
	{
		i++;
	}
	//cargar el valor
	if(i==len)
	{
		vec[i].NRO_PROV = valor.NRO_PROV;
		vec[i].TIPO_PROD = valor.TIPO_PROD;
		vec[i].CPE = valor.CPE;
	
		len++;
	}
	else insertar(vec,len,valor,i);
}


