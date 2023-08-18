/*8) Se tiene un archivo de registros de tamaño fijo de los jugadores convocados a la Copa 
América 2021 con nombre Jugadores2021.DAT. El formato del registro de este archivo es el 
siguiente:
COD_JUG: Código del Jugador / Número
SELECCIÓN: ID de la Selección en la que juegan / Número
EDAD: Edad / Numérico
ALTURA: Estatura del jugador / Número decimal
Se pide realizar un programa que lea ese archivo y genere dos archivos nuevos. El primero 
(SUB23.dat) que contenga todos los Jugadores de hasta 23 años. Con el siguiente formato:
COD_JUG: Código del Jugador / Número
SELECCIÓN: ID de la Selección en la que juegan / Número
EDAD: Edad / Numérico
ALTURA: Estatura del jugador / Número decimal
El segundo (MAY180.dat) que contenga los Jugadores que miden más de 1,80m el siguiente 
formato:
COD_JUG: Código del Jugador / Número
SELECCIÓN: ID de la Selección en la que juegan / Número
EDAD: Edad / Numérico*/

#include <iostream>
#include <stdio.h>

using namespace std;

struct Jugador1
{
	int COD_JUG;
	int SELECCION;
	int EDAD;
	float ALTURA;
};

struct Jugador2
{
	int COD_JUG;
	int SELECCION;
	int EDAD;
};

int main()
{
	//cremos los punteros a archivos y abrimos 
	FILE *JUG;
	JUG = fopen("Jugadores2021.DAT","rb");
	Jugador1 raux;
	
	FILE *Sub23;
	Sub23= fopen("Sub23.dat","wb");
	
	FILE *Alt;
	Alt= fopen("MAY180.dat","wb");
	Jugador2 raux2;
	
	fread(&raux,sizeof(Jugador1),1,JUG);
	while(!feof(JUG))
	{
		if(raux.EDAD <= 23)
		{
			fwrite(&raux,sizeof(Jugador1),1,Sub23);
			
		}else
		{
			if(raux.ALTURA > 180.0)
			{
				raux2.COD_JUG = raux.COD_JUG;
				raux2.SELECCION = raux.SELECCION;
				raux2.EDAD = raux.EDAD;
				
				fwrite(&raux2,sizeof(Jugador2),1,Alt);
			}
		}
		
		fread(&raux,sizeof(Jugador1),1,JUG);
		
	}
	fclose(JUG);
	fclose(Sub23);
	fclose(Alt);


	return 0;
}

