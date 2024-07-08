#include "iostream"
#include "vector"
#include "complex.hpp"
#pragma once
using namespace std;


namespace ariel{

template<typename T>
struct ToQString {
    static QString convert(const T& value) {
        return QString::number(value);
    }
};

template<>
struct ToQString<std::string> {
    static QString convert(const std::string& value) {
        return QString::fromStdString(value);
    }
};

template<>
struct ToQString<Complex>{
    static QString convert(const Complex& com){
        return QString::fromStdString(com.toString());
    }
};


template<typename T>
class Node{
public:
    T value;
    double posX;
    double posY;
    int level;
    vector<Node<T>*> children;
    explicit Node(T val): value(val){}

    T getValue(){
        return value;
    }

    QString toQString() const {
        return ToQString<T>::convert(value);
    }

};



}

