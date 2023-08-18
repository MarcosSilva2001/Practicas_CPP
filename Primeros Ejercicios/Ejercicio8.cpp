/*Eejrcicio 8
Dados un mes y el año al que corresponde, informar cuantos días tiene el mes. */

#include <iostream>

using namespace std;

int main()
{
	int year, month;
	int dias;
	
	cout<<"Ingrese un anio: ";
	cin>>year;
	cout<<"\nAhora ingrese un mes: ";
	cin>>month;
	
	
	if(month == 2)
	{
		//verificamos si es o no un año Bisiesto
		if((year % 4 == 0) && (year % 100 == 0) || (year % 400 == 0))
		{
			dias = 29;
		}
		else 
		{
			dias = 28;
		}
		
	}
	else if(month == 4 || month == 6 || month == 9 || month == 11)
	{
		dias = 30;
	}
	else
	{
		dias = 31;
	}
	
	cout<<"\n\nEl mes "<<month<<" del anio "<<year<<" tiene "<<dias<<" dias...";
	


	return 0;
}

