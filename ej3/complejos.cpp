

#include "complejos.hpp"
#include <iostream>
#include <string>

using namespace std;

// Sobrecarga del +
shared_ptr<Numero> Complejos::operator+(const Numero &a) const
{
    // casteo de la clase base a la clase derivada
    const Complejos other = dynamic_cast<const Complejos&>(a);
    // se retorna un puntero compartido a un nuevo objeto Complejos
    return shared_ptr<Numero>(new Complejos(this->real + other.real, this->imaginario + other.imaginario));
}

// Sobrecarga del -
shared_ptr<Numero> Complejos::operator-(const Numero &a) const
{
    const Complejos other = dynamic_cast<const Complejos&>(a);
    return shared_ptr<Numero>(new Complejos(this->real - other.real, this->imaginario - other.imaginario));
}

// Sobrecarga del *
shared_ptr<Numero> Complejos::operator*(const Numero &a) const
{
    const Complejos other = dynamic_cast<const Complejos&>(a);
    return shared_ptr<Numero>(new Complejos(this->real * other.real - this->imaginario * other.imaginario,
                                       this->real * other.imaginario + this->imaginario * other.real));
}

// Metodo toString
string Complejos::toString() const
{
    // se convierte el valor a string
    return to_string(real) + " + " + to_string(imaginario) + "i";
}