
#include "cursos.hpp"
#include <iostream>
#include <algorithm>
#include <string>
#include <memory>

using namespace std;

// Constructor
Cursos::Cursos(string nombre) : nombre(nombre) {}

// Los getters
string Cursos::getNombre()
{
    return nombre;
}

vector<shared_ptr<Estudiantes>> Cursos::getEstudiantes()
{
    return estudiantes;
}

vector<shared_ptr<Estudiantes>> Cursos::getEstudiante(int id)
{
    // Buscamos el estudiante por id, si lo encuentro lo devuelvo
    for (int i = 0; i < estudiantes.size(); i++)
    {
        if (estudiantes[i]->getId() == id)
        {
            return { estudiantes[i] };
        }
    }
    cout << "No se encontro el estudiante con id: " << id << endl;
    return {};
}

// Chequeo si el estudiante ya existe en el curso
bool Cursos::checkEstudiante(int id)
{
    for (int i = 0; i < estudiantes.size(); i++)
    {
        if (estudiantes[i]->getId() == id)
        {
            return true;
        }
    }
    return false;
}

// Agrego un estudiante al curso
void Cursos::addEstudiante(shared_ptr<Estudiantes> estudiante)
{
    if (!checkEstudiante(estudiante->getId()))
    {
        estudiantes.push_back(estudiante);
        cout << "(" <<this->nombre << ")" <<"Estudiante agregado: " << estudiante->getNombre() << endl;
        estudiante->addCurso(*this, 0); 
    }
    else
    {
        // Si el estudiante ya existe en el curso, no lo agrego
        cout << "El estudiante ya existe en el curso." << endl;
    }
}

// Elimino un estudiante del curso
bool Cursos::removeEstudiante(int id)
{
    for (int i = 0; i < estudiantes.size(); i++)
    {
        if (estudiantes[i]->getId() == id)
        {
            estudiantes.erase(estudiantes.begin() + i);
            cout << "Estudiante eliminado: " << estudiantes[i]->getNombre() << endl;
            return true;
        }
    }
    // Si no lo encontre, imprimo un mensaje
    cout << "No se encontro el estudiante" << endl;
    return false;
}

// Imprimo los estudiantes del curso
// Los ordeno por nombre
void Cursos::imprimirEstudiantes()
{

    sort(estudiantes.begin(), estudiantes.end(), [](shared_ptr<Estudiantes> a, shared_ptr<Estudiantes> b) 
    {
        return a->getNombre() < b->getNombre();
    });
    cout << "Estudiantes en el curso " << nombre << ":" << endl;
    for (int i = 0; i < estudiantes.size(); i++)
    {
        // Desreferencio el puntero para acceder al objeto Estudiantes
        cout << *estudiantes[i] << endl;
    }
}

// Destructor
Cursos::~Cursos()
{
    estudiantes.clear();
    cout << "Curso " << nombre << " destruido." << endl;
}