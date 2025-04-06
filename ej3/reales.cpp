

#include "reales.hpp"



using namespace std;

// Sobrecarga del +
shared_ptr<Numero> Reales::operator+(const Numero& a) const 
{
    // casteo de la clase base a la clase derivada
    const Reales& other = dynamic_cast<const Reales&>(a);
    // se retorna un puntero compartido a un nuevo objeto Reales  
    return shared_ptr<Numero>(new Reales(this->valor + other.valor));
}

// Sobrecarga del -
shared_ptr<Numero> Reales::operator-(const Numero& a) const 
{
    const Reales& other = dynamic_cast<const Reales&>(a); 
    return shared_ptr<Numero>(new Reales(this->valor - other.valor));
}

// Sobrecarga del *
shared_ptr<Numero> Reales::operator*(const Numero& a) const 
{
    const Reales& other = dynamic_cast<const Reales&>(a); 
    return shared_ptr<Numero>(new Reales(this->valor * other.valor));
}

// Metodo toString
string Reales::toString() const 
{
    // se convierte el valor a string
    return to_string(valor);
}