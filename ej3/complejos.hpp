
#ifndef COMPLEJOS_HPP
#define COMPLEJOS_HPP

#include "numero.hpp"


class Complejos : public Numero 
{
private:
    double real;
    double imaginario;
public:
    // Constructor y destructor
    Complejos(double real, double imaginario) : real(real), imaginario(imaginario) {}
    ~Complejos() override = default;

    // Sobrecarga de operadores
    shared_ptr<Numero> operator+(const Numero &a) const override;
    shared_ptr<Numero> operator-(const Numero &a) const override;
    shared_ptr<Numero> operator*(const Numero &a) const override;

    // Metodos
    string toString() const override;
};
#endif