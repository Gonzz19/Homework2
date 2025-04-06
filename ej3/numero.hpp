
#ifndef NUMERO_HPP
#define NUMERO_HPP

#include <string>
#include <memory>
using namespace std;

class Numero {
public:
    // Destructor
    virtual ~Numero() = default;

    // Sobrecarga de operadores
    virtual shared_ptr<Numero> operator+(const Numero &a) const = 0;
    virtual shared_ptr<Numero> operator-(const Numero &a) const = 0;
    virtual shared_ptr<Numero> operator*(const Numero &a) const = 0;

    // Metodos
    virtual string toString() const = 0;
};





#endif