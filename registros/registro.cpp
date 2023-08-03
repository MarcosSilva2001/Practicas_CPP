/*un Registro es: Es una estructura de datos que agrupa varios elementos(campos) relacionados por un nombre puede
contener variables de diferentes tipos de datos, como enteros, flotantes, caracteres, punteros, etc.

Los valores almacenados pueden ser accedidos individualmente y se llaman campoa campo por un identificador*/

#include <iostream>

using namespace std;

// en este espacio declaramos los registros

struct Alumno
{
    int legajo;
    int curso;
    int nota;
};

void inicializar(Alumno vec[], int tam, Alumno valorIni);
void cargar(Alumno vec[], int &len, int tam);
void mostrar(Alumno vec[], int len);

int main()
{
    // delacramos un vector de struct de tipo alumno
    Alumno vector[3];
    int len = 0;
    Alumno regIni; // creo un registro para inicializar el vector de registro campo a campo

    // con esto inicializamos cada campo en cero
    regIni.legajo = 0;
    regIni.curso = 0;
    regIni.nota = 0;

    inicializar(vector, 3, regIni);
    cargar(vector, len, 3);
    mostrar(vector, len);

    return 0;
}
void inicializar(Alumno vec[], int tam, Alumno valorIni)
{
    for (int i = 0; i < 4; i++)
    {
        vec[i].legajo = valorIni.legajo;
        vec[i].curso = valorIni.curso;
        vec[i].nota = valorIni.nota;
    }
}
void cargar(Alumno vec[], int &len, int tam)
{
    cout << "A continuacion cargue el registro: " << endl;
    for (int i = 0; i < tam; i++)
    {

        cout << "\n----------CARGUE EL LA POSICION " << i << " DEL REGISTRO----------";
        cout << "\nLegajo: ";
        cin >> vec[i].legajo;
        cout << "\nCurso: ";
        cin >> vec[i].curso;
        cout << "\nNota: ";
        cin >> vec[i].nota;
        len++;
    }
}
void mostrar(Alumno vec[], int len)
{
    cout << "\nEl registro cargado es" << endl;

    for (int i = 0; i < len; i++)
    {
        cout << "\nLegajo: " << vec[i].legajo;
        cout << "\nCurso: " << vec[i].curso;
        cout << "\nNota: " << vec[i].nota;
        cout << "\n---------------------------";
    }
}
