
#include "estudiantes.hpp"
#include "cursos.hpp"
#include <iostream>
#include <vector>

using namespace std;


int main()
{
    // Crear cursos
    Cursos curso1("Analaisis Matematico");
    Cursos curso2("Fisica I");

    // Crear estudiantes
    shared_ptr<Estudiantes> estudiante1 = make_shared<Estudiantes>(1, "Juan Gomez");
    shared_ptr<Estudiantes> estudiante2 = make_shared<Estudiantes>(2, "Maria Recarte");
    shared_ptr<Estudiantes> estudiante3 = make_shared<Estudiantes>(3, "Carlos Malaspina");
    shared_ptr<Estudiantes> estudiante4 = make_shared<Estudiantes>(4, "Ana Clara Farias");

    // Agregar estudiantes al curso (Matematicas)
    curso1.addEstudiante(estudiante1);
    curso1.addEstudiante(estudiante2);
    curso1.addEstudiante(estudiante3);

    // Agregar notas a los estudiantes
    estudiante1->setNota(curso1, 8.5);
    estudiante2->setNota(curso1, 9.0);
    estudiante3->setNota(curso1, 7.5);

    // Agregar estudiantes al curso (Fisica)
    curso2.addEstudiante(estudiante1);
    curso2.addEstudiante(estudiante2);
    curso2.addEstudiante(estudiante3);
    curso2.addEstudiante(estudiante4);

    // Agregar notas a los estudiantes
    estudiante1->setNota(curso2, 8.0);
    estudiante2->setNota(curso2, 9.5);
    estudiante3->setNota(curso2, 7.0);
    estudiante4->setNota(curso2, 8.0);


    // Mostrar estudiantes en el curso de Matematicas
    curso1.imprimirEstudiantes();
    cout << endl;
    // Mostrar estudiantes en el curso de Fisica
    curso2.imprimirEstudiantes();
    cout << endl;

    // Mostrar los promedios de los estudiantes
    cout << "Promedios de los estudiantes:" << endl;
    cout << estudiante1->getNombre() << ": " << estudiante1->getPromedio() << endl;
    cout << estudiante2->getNombre() << ": " << estudiante2->getPromedio() << endl;
    cout << estudiante3->getNombre() << ": " << estudiante3->getPromedio() << endl;
    cout << estudiante4->getNombre() << ": " << estudiante4->getPromedio() << endl;
    cout << endl;

    // Remuevo a un estudiante del curso q no esta y a uno que si
    curso1.removeEstudiante(4);
    curso1.removeEstudiante(3);
    cout << endl;

    // Imprimo info de los estudiantes
    cout << "Info de los estudiantes:" << endl;
    estudiante1->printEstudiante();
    estudiante2->printEstudiante();
    estudiante3->printEstudiante();
    estudiante4->printEstudiante();

    // Imprimo cursos, post delete

    cout << "Cursos de los estudiantes:" << endl;
    curso1.imprimirEstudiantes();
    curso2.imprimirEstudiantes();
    cout << endl;
    return 0;
}
