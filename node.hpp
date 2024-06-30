#include "iostream"
#include "vector"
#pragma once
using namespace std;


namespace ariel{

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



};



}

