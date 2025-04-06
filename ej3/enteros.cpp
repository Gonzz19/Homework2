

#include "enteros.hpp"
#include <string>

using namespace std;



// Sobrecarga del +
shared_ptr<Numero> Enteros::operator+(const Numero& a) const 
{
    const Enteros& other = dynamic_cast<const Enteros&>(a);  
    return shared_ptr<Numero>(new Enteros(this->valor + other.valor));
}

// Sobrecarga del -
shared_ptr<Numero> Enteros::operator-(const Numero& a) const 
{
    const Enteros& other = dynamic_cast<const Enteros&>(a);  
    return shared_ptr<Numero>(new Enteros(this->valor - other.valor));
}

// Sobrecarga del *
shared_ptr<Numero> Enteros::operator*(const Numero& a) const 
{
    const Enteros& other = dynamic_cast<const Enteros&>(a);  
    return shared_ptr<Numero>(new Enteros(this->valor * other.valor));
}

// Metodo to string
string Enteros::toString() const 
{
    // Convertir el valor entero a string
    return to_string(valor);
}