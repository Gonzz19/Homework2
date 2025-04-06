
#ifndef CURSOS_HPP
#define CURSOS_HPP

#include <vector>
#include <string>
#include "estudiantes.hpp"
#include <memory>

using namespace std;

class Estudiantes;

class Cursos
{
private:
    // Atributos
    vector<shared_ptr<Estudiantes>> estudiantes;
    string nombre;
    const int capacidad = 20;

public:
    // Constructor y destructor
    Cursos(string nombre);
    ~Cursos();

    // Getters
    string getNombre();
    vector<shared_ptr<Estudiantes>> getEstudiante(int id);
    vector<shared_ptr<Estudiantes>> getEstudiantes();

    // Metodos
    void addEstudiante(shared_ptr<Estudiantes> estudiante);
    bool removeEstudiante(int id);
    void imprimirEstudiantes();
    bool checkEstudiante(int id);
};


#endif