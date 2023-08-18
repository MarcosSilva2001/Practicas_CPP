/*
2) Dado un vector (de registros) acerca las estadísticas de los jugadores que participaron en la
Copa América 2021 y marcaron goles; que contiene el código del jugador, Inicial de
Selección a la que pertenecen y la cantidad de goles convertidos. (Se sabe que hay
cómo máximo 276 jugadores), se pide determinar:
a- ¿Cuál es el Jugador que más goles convirtió? (Código del Jugador y cantidad de goles)
b- ¿Cuál es el Jugador que menos goles convirtió? (Código del Jugador y cantidad de goles)
c- Calcular el promedio de goles convertidos.
*/

#include <iostream>

using namespace std;

const int MaxJugador = 276;

struct Jugador
{
    int codigo;
    char inicialSelec[6];
    int goles;
};

// Declaración de funciones
void inicializar(Jugador vec[], int tam, Jugador valorIni);
void cargar(Jugador vec[], int tam, int &len);
int Max_Goleador(Jugador vec[], int len);
int Min_Goleador(Jugador vec[], int len);
int Promedio_Goles(Jugador vec[], int len);

int main()
{
    Jugador vec[MaxJugador];
    int len = 0;
    int numJugadores;

    cout << "Ingrese el número de jugadores que participan: ";
    cin >> numJugadores;

    Jugador valorIni;
    valorIni.codigo = 0;
    valorIni.inicialSelec[0] = '/';
    valorIni.goles = 0;

    inicializar(vec, numJugadores, valorIni);

    cargar(vec, numJugadores, len);

    // RESULTADOS DE LA COPA AMERICA
    cout << "         Resultados de la Copa América 2021: " << endl;
    cout << "--------------------------------------------------------" << endl;

    // a- ¿Cuál es el Jugador que más goles convirtió? (Código del Jugador y cantidad de goles)
    int posMax = Max_Goleador(vec, numJugadores);
    cout << "\nEl Jugador que más goles convirtió es: " << vec[posMax].codigo << " con " << vec[posMax].goles << " goles" << endl;

    // b- ¿Cuál es el Jugador que menos goles convirtió? (Código del Jugador y cantidad de goles)
    int posMin = Min_Goleador(vec, numJugadores);
    cout << "\nEl Jugador que menos goles convirtió es: " << vec[posMin].codigo << " con " << vec[posMin].goles << " goles" << endl;

    // c- Calcular el promedio de goles convertidos.
    int promedio = Promedio_Goles(vec, numJugadores);
    cout << "\nEl promedio de goles convertidos es: " << promedio << endl;
    cout << "\n--------------------------------------------------------" << endl;

    return 0;
}

void inicializar(Jugador vec[], int tam, Jugador valorIni)
{
    for (int i = 0; i < tam; i++)
    {
        vec[i] = valorIni; // Asignacion directa
    }
}

void cargar(Jugador vec[], int tam, int &len)
{
    cout << "------------- A continuacion debera cargar los datos de los jugadores ------------" << endl;
    for (int i = 0; i < tam; i++)
    {
        cout << "Ingrese el código del jugador: ";
        cin >> vec[i].codigo;
        cout << "Ingrese la inicial de la selección que representa: ";
        cin >> vec[i].inicialSelec;
        cout << "Digite la cantidad de goles que convirtió: ";
        cin >> vec[i].goles;
        len++;
    }
}

int Max_Goleador(Jugador vec[], int len)
{
    int posMax = 0;

    for (int i = 1; i < len; i++)
    {
        if (vec[posMax].goles < vec[i].goles)
        {
            posMax = i;
        }
    }

    return posMax;
}

int Min_Goleador(Jugador vec[], int len)
{
    int posMin = 0;

    for (int i = 1; i < len; i++)
    {
        if (vec[posMin].goles > vec[i].goles)
        {
            posMin = i;
        }
    }

    return posMin;
}

int Promedio_Goles(Jugador vec[], int len)
{
    int suma = 0;
    int cont = 0;

    for (int i = 0; i < len; i++)
    {
        suma = suma + vec[i].goles;
        cont++;
    }

    return (suma / cont);
}
