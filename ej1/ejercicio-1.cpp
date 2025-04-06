#include <iostream>
#include "ejercicio-1.hpp"
#include <limits>

using namespace std;

enum TIPOS{HORAS, MINUTOS, SEGUNDOS, FRANJA};
enum FRANJAS{AM, PM};


int Tiempo::checktime(int cant, int tipo)
{
    if (tipo == HORAS)
    {
        if (cant < 0 || cant > 11) return 1;
    }
    else if (tipo == MINUTOS)
    {
        if (cant < 0 || cant > 59) return 2;
    }
    else if (tipo == SEGUNDOS)
    {
        if (cant < 0 || cant > 59) return 3;
    }
    else if (tipo == FRANJA)
    {
        if (cant != AM && cant != PM) return 4;
    }
    return 0;
};

Tiempo::Tiempo(int Lashoras, int Losminutos, int Lossegundos, bool Lafranja)
{
    horas = Lashoras;
    minutos = Losminutos;
    segundos = Lossegundos;
    franja = Lafranja;
}

void Tiempo::setHoras(int horas)
{
    this->horas = horas;
}

void Tiempo::setMinutos(int minutos)
{
    this->minutos = minutos;
}

void Tiempo::setSegundos(int segundos)
{
    this->segundos = segundos;
}

void Tiempo::setFranja(bool Lafranja)
{
    this->franja = Lafranja;
}

void Tiempo::imprimir()
{
    cout << "La hora es: " << horas << ":" << minutos << ":" << segundos;
    if (franja == AM)
        cout << " AM" << endl;
    else
        cout << " PM" << endl;
}

int Tiempo::getHoras()
{
    return horas;
}

int Tiempo::getMinutos()
{
    return minutos;
}

int Tiempo::getSegundos()
{
    return segundos;
}

bool Tiempo::getFranja()
{
    return franja;
}

void Tiempo::imprimir24hrs()
{
    int horas24 = horas;
    if (franja == PM && horas != 12)
        horas24 += 12;
    else if (franja == AM && horas == 12)
        horas24 = 0;

    cout << "La hora en formato 24hrs es: " << horas24 << ":" << minutos << ":" << segundos << endl;
}

Tiempo::~Tiempo()
{
    this->horas = 0;
    this->minutos = 0;
    this->segundos = 0;
    this->franja = AM;
    cout << "El objeto tiempo ha sido destruido" << endl;
}

int main()
{
    bool flag = true;
    int horas, minutos, segundos, opcion;
    bool franja;
    Tiempo t1(0, 0, 0, AM);
    cout << "Ingrese una opcion: " << endl;
    cout << "0) Crear un objeto tiempo sin pasarle parametro" << endl;
    cout << "1) Pasandole solo la hora " << endl;
    cout << "2) Pasandole la hora y los minutos" << endl;
    cout << "3) Pasandole la hora, los minutos y los segundos" << endl;
    cout << "4) Pasandole la hora, los minutos, los segundos y la franja horaria" << endl;
    cin >> opcion;
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        cout << "Error: entrada no valida" << endl;
        cout << "se asume que el objeto se crea sin pasarle parametros" << endl;
        opcion = 0;
    }

    if (opcion > 0 && opcion < 5)
    {
        cout << "Ingrese la hora: ";
        cin >> horas;
        while (t1.checktime(horas, HORAS) != 0)
        {
            cout << "Error: horas fuera de rango" << endl;
            cout << "Ingrese la hora: ";
            cin >> horas;
        }
        t1.setHoras(horas);        
        if (opcion > 1)
        {
            cout << "Ingrese los minutos: ";
            cin >> minutos;
            while (t1.checktime(minutos, MINUTOS) != 0)
            {
                cout << "Error: minutos fuera de rango" << endl;
                cout << "Ingrese los minutos: ";
                cin >> minutos;
            }
            t1.setMinutos(minutos);
            if (opcion > 2)
            {
                cout << "Ingrese los segundos: ";
                cin >> segundos;
                while (t1.checktime(segundos, SEGUNDOS) != 0)
                {
                    cout << "Error: segundos fuera de rango" << endl;
                    cout << "Ingrese los segundos: ";
                    cin >> segundos;
                }
                t1.setSegundos(segundos);
                if (opcion > 3)
                {
                    cout << "Ingrese la franja horaria (0 para AM, 1 para PM): ";
                    cin >> franja;
                    while (t1.checktime(franja, FRANJA) != 0)
                    {
                        cout << "Error: franja horaria fuera de rango" << endl;
                        cout << "Ingrese la franja horaria (0 para AM, 1 para PM): ";
                        cin >> franja;
                    }
                    t1.setFranja(franja);
                }
            }
        }
    }
    else
    {
        if (opcion != 0)
        {
        cout << "Opcion no valida" << endl;
        return 0;
        }   
    }
    cout << "El objeto se ha creado correctamente" << endl;
  
    while (flag)
    {
        cout << "Ingrese una opcion: " << endl;
        cout << "1) Cambiar la hora" << endl;
        cout << "2) Cambiar los minutos" << endl;
        cout << "3) Cambiar los segundos" << endl;
        cout << "4) Cambiar la franja horaria" << endl;
        cout << "5) Imprimir la hora" << endl;
        cout << "6) Imprimir la hora en formato 24hrs" << endl;
        cout << "7) Salir" << endl;
        cin >> opcion;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Error: entrada no valida" << endl;
            continue;
        }
        switch (opcion)
        {
            case 1:
                cout << "Ingrese la nueva hora: ";
                cin >> horas;
                while (t1.checktime(horas, HORAS) != 0)
                {
                    cout << "Error: horas fuera de rango" << endl;
                    cout << "Ingrese la nueva hora: ";
                    cin >> horas;
                }
                t1.setHoras(horas);
                break;

            case 2:
                cout << "Ingrese los nuevos minutos: ";
                cin >> minutos;
                while (t1.checktime(minutos, MINUTOS) != 0)
                {
                    cout << "Error: minutos fuera de rango" << endl;
                    cout << "Ingrese los nuevos minutos: ";
                    cin >> minutos;
                }
                t1.setMinutos(minutos);
                break;

            case 3:
                cout << "Ingrese los nuevos segundos: ";
                cin >> segundos;
                while (t1.checktime(segundos, SEGUNDOS) != 0)
                {
                    cout << "Error: segundos fuera de rango" << endl;
                    cout << "Ingrese los nuevos segundos: ";
                    cin >> segundos;
                }
                t1.setSegundos(segundos);
                break;

            case 4:
                cout << "Ingrese la nueva franja horaria (0 para AM, 1 para PM): ";
                cin >> franja;
                while (t1.checktime(franja, FRANJA) != 0)
                {
                    cout << "Error: franja horaria fuera de rango" << endl;
                    cout << "Ingrese la nueva franja horaria (0 para AM, 1 para PM): ";
                    cin >> franja;
                }
                t1.setFranja(franja);
                break;

            case 5:
                t1.imprimir();
                break;
            case 6:
                t1.imprimir24hrs();
                break;
            case 7:
                cout << "Saliendo..." << endl;
                flag = false;
                break;
            default:
                cout << "Opcion no valida" << endl;
                break;
        }
    }
    return 0;
}