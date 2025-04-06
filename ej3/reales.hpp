
#ifndef REALES_HPP
#define REALES_HPP

#include "numero.hpp"
using namespace std;

class Reales : public Numero 
{
private:
    float valor;
public:
    // Constructor y destructor
    Reales(double valor) : valor(valor) {}
    ~Reales() override = default;

    // sobreesrcirbo la Sobrecarga de operadores
    shared_ptr<Numero> operator+(const Numero &a) const override;
    shared_ptr<Numero> operator-(const Numero &a) const override;
    shared_ptr<Numero> operator*(const Numero &a) const override;

    // Metodos
    string toString() const override;
};

#endif