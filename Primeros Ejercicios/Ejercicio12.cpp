
/* En un torneo de fútbol participan k equipos. El torneo se juega con el sistema 
de “todos contra todos”. Por cada partido en el que participa un equipo se dispone 
de la siguiente información: 
* código de equipo (codEq) y 
* código de resultadp (“P” = perdido, “E” = empatado, “G”= ganado). 
 
Se dispone de un lote de datos conteniendo todos los resultados del torneo, 
agrupados por codEq. 
Desarrollar el programa que imprima, por cada equipo, su código y el puntaje 
total que obtuvo considerando que suma 3 puntos por cada partido ganado y 1 
punto por cada partido empatado. */

#include <iostream>

using namespace std;

int main()
{
    int k = 0, puntaje = 0;
    char codResultado;

    cout << "Ingrese la cantidad de equipos que participan: " << endl;
    cin >> k;
    
    int EquipoPuntaje[k] = {0};
    int codEquipo[k] = {0};

    // k define la cantidad de equipos, nos sirve para saber hasta qué valor iterar
    for (int i = 0; i < k; i++)
    {
        cout << "\n           Equipo [" << i + 1 << "] " << endl;
        cout << "\nDigite el codigo del equipo: ";
        cin >> codEquipo[i];

        cout << "\nIngrese el codigo de resultado (P = perdido, E = empatado, G = ganado): " << endl;
        cin >> codResultado;

        // verificamos que el código ingresado sea válido
        while (codResultado != 'P' && codResultado != 'E' && codResultado != 'G')
        {
            cout << "Codigo de resultado inválido... Ingrese nuevamente: " << endl;
            cin >> codResultado;
        }

        // evaluamos el código de resultado y cargamos el puntaje a ese equipo
        if (codResultado == 'P')
        {
            EquipoPuntaje[i] += 1;
        }
        else if (codResultado == 'G')
        {
             EquipoPuntaje[i] += 3;
        }

    }

    cout << "\n\n                 RESULTADOS FINALES" << endl;

    for (int i = 0; i < k; i++)
    {
        cout << "\nLos resultados del Equipo [" << i + 1 << "] son:  " << endl;
        cout << "Codigo de Equipo: " << codEquipo[i] << endl;
        cout << "Puntaje Total: " << EquipoPuntaje[i] << " puntos..." << endl;
    }

    return 0;
}

