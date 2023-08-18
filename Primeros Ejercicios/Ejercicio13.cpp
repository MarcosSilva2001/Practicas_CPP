/*Ejercicio 13 
Se ingresa un conjunto de valores reales, cada uno de los cuales representan 
el sueldo de un empleado, excepto el último valor que será 0 para indicar el fin del 
ingreso de datos. Se pide desarrollar un programa que determine e informe: 
? Cuántos empleados ganan menos $2000. 
? Cuántos ganan $2000 o más pero menos de $3000. 
? Cuántos ganan $3000 o más pero menos de $5000. 
? Cuántos ganan $5000 o más. */

#include <iostream>

using namespace std;

int main()
{
	float sueldo;
	int cont1=0, cont2=0, cont3=0, cont4=0;
	
	cout <<"Ingrese un sueldo o cero para finalizar: ";
	cin >>sueldo;
	
	//iteramos con un while hasta que el usuario ingrese un valor cero
	while(sueldo!=0)
	{
		if(sueldo > 0)
		{
			if(sueldo < 2000)
			{
				cont1++;
			}
			if(sueldo >= 2000 && sueldo < 3000)
			{
				cont2++;
			}
			if(sueldo >= 3000 && sueldo < 5000)
			{
				cont3++;
			}
			if(sueldo >= 5000)
			{
				cont4++;
			}
		
		}else
		{
			cout <<"\nEl sueldo ingresado no es valido, por favor ingrese valores positivos "<<endl<<endl;
		}
		
		cout <<"Ingrese un sueldo o cero para finalizar: "<<endl;
		cin >>sueldo;
	}

	cout <<"\n________________LOS RESULTADOS SON: __________________ "<<endl;
	
	cout <<"\nLos empleados que ganan menos de $2000 son: "<< cont1 ;
	cout <<"\nLos empleados que ganan mas de $2000 pero menos de $3000 son: "<< cont2 ;
	cout <<"\nLos empleados que ganan mas de $3000 pero menos de $5000 son: "<< cont3 ;
	cout <<"\nLos empleados que ganan mas de $5000 son: "<< cont4 ;





	return 0;
}

