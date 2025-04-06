#include "estudiantes.hpp"
#include <iostream>
#include <string>

using namespace std;

// Constructor
Estudiantes::Estudiantes(int id, string nombre) : id(id), nombre(nombre) {}

// Los getters
int Estudiantes::getId()
{
    return id;
}

string Estudiantes::getNombre()
{
    return nombre;
}

string Estudiantes::getCursos()
{
    string cursosStr = "";
    for (int i = 0; i < cursos.size(); i++)
    {
        cursosStr += cursos[i].first->getNombre() + ",";
    }
    return cursosStr;
}

// El unico setter
void Estudiantes::setNota(Cursos &curso, float nota)
{
    for (int i = 0; i < cursos.size(); i++)
    {
        if (cursos[i].first->getNombre() == curso.getNombre())
        {
            cursos[i].second = nota;
            return;
        }
    }
    cout << "El curso no existe" << endl;
}

// Chequeo si el curso ya existe en el estudiante
bool Estudiantes::checkCurso(Cursos &curso)
{
    for (int i = 0; i < cursos.size(); i++)
    {
        if (cursos[i].first->getNombre() == curso.getNombre())
        {
            return true;
        }
    }
    return false;
}

// Agrego un curso al estudiante
bool Estudiantes::addCurso(Cursos &curso, float nota)
{
    if (!checkCurso(curso))
    {
        shared_ptr<Cursos> cursoPtr = make_shared<Cursos>(curso);
        cursos.push_back(make_pair(cursoPtr, nota));
        return true;
    }
    else
    {
        // Si el curso ya existe en el estudiante, no lo agrego
        cout << "El curso ya esta registrado" << endl;
        return false;
    }
}

// Elimino un curso del estudiante
bool Estudiantes::removeCurso(Cursos &curso)
{
    for (int i = 0; i < cursos.size(); i++)
    {
        if (cursos[i].first->getNombre() == curso.getNombre())
        {
            cursos.erase(cursos.begin() + i);
            curso.removeEstudiante(this->id);
            return true;
        }
    }
    // Si el curso no existe en el estudiante, no lo elimino
    cout << "No se encontro el curso" << endl;
    return false;
}

// Devuelvo el promedio de las notas del estudiante
float Estudiantes::getPromedio()
{
    float suma = 0;
    for (int i = 0; i < cursos.size(); i++)
    {
        suma += cursos[i].second;
    }
    return suma / cursos.size();
}

// Devuelvo la info del estudiante
void Estudiantes::printEstudiante()
{
    cout << "ID: " << id << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Cursos: " << getCursos() << endl;
    cout << "Promedio: " << getPromedio() << endl;
    cout << endl;
}

// Destructor
Estudiantes::~Estudiantes()
{
    cursos.clear();
    cout << "Destructor de Estudiantes llamado" << endl;
}

// Sobrecarga de operadores
bool Estudiantes::operator<(const Estudiantes& e)
{
    return this->id < e.id;
}

std::ostream& operator<<(std::ostream& os, const Estudiantes& e)
{
    os << "ID: " << e.id << ", Nombre: " << e.nombre;
    return os;
}