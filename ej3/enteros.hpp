
#ifndef ENTEROS_HPP
#define ENTEROS_HPP

#include "numero.hpp"
using namespace std;

class Enteros : public Numero 
{
private:
    int valor;

public:
    // Constructor y destructor
    Enteros(int valor) : valor(valor) {}
    ~Enteros() override = default;

    // Sobrecarga de operadores
   shared_ptr<Numero> operator+(const Numero &a) const override;
   shared_ptr<Numero> operator-(const Numero &a) const override;
   shared_ptr<Numero> operator*(const Numero &a) const override;

   // Metodo toString
    string toString() const override;
};

#endif