#ifndef ESTUDIANTES_HPP
#define ESTUDIANTES_HPP

#include <vector>
#include <string>
#include <memory>
#include "cursos.hpp"

using namespace std;

class Cursos;

class Estudiantes
{
private:
    // Atributos
    int id;
    string nombre;
    vector<pair<shared_ptr<Cursos>, float>> cursos;

public:
    // Constructor y destructor
    Estudiantes(int id, string nombre);
    ~Estudiantes();

    // Getters y setters
    int getId();
    string getNombre();
    string getCursos();
    void setNota(Cursos &curso, float nota);

    // Metodos
    bool checkCurso(Cursos &curso);
    bool addCurso(Cursos &curso, float nota);
    bool removeCurso(Cursos &curso);
    float getPromedio();
    void printEstudiante();

    // Sobrecarga de operadores
    friend std::ostream& operator<<(std::ostream& os, const Estudiantes& e);
    bool operator<(const Estudiantes& e); 
};


#endif