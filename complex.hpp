//erikidelchik@gmail.com

#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>
#include <cmath>
#include <QString>

using namespace std;

class Complex {
private:
    double real;
    double imag;

public:

    // Constructor
    explicit Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator*(const Complex& other) const {
        return Complex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
    }

    bool operator>(Complex &other) const{
        return sqrt(this->real* this->real + this->imag* this->imag)>sqrt(other.real*other.real+other.imag*other.imag);
    }

    QString toQString() const {
        if (imag >= 0)
            return QString("%1 + i%2").arg(real).arg(imag);
        else
            return QString("%1 - i%2").arg(real).arg(-imag);
    }


};



#endif // COMPLEX_HPP

