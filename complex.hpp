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
    
    string toString() const {
    	int r = real*10;
    	int im = imag*10;
    	if(imag>=0){
    	    return to_string(r/10) +" + "+ to_string(im/10)+"i";
    	}
    	else
            return to_string(r/10) +" - "+ to_string(im/10)+"i";
    
    }


};



#endif // COMPLEX_HPP

