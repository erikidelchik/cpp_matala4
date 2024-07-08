#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <QGraphicsTextItem>
#include <QVBoxLayout>
#include <QWidget>
#include "tree.hpp"
#include <iostream>

using namespace ariel;

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    Tree<Complex,3> three_ary_tree; // 3-ary tree.
    Node<Complex> r = Node(Complex(1,1));
    
    Node<Complex> r1 = Node(Complex(1,2));
    Node<Complex> r2 = Node(Complex(1,3));
    Node<Complex> r3 = Node(Complex(1,4));
    Node<Complex> r4 = Node(Complex(1,5));
    Node<Complex> r5 = Node(Complex(1,6));
    
    three_ary_tree.add_root(r);
    three_ary_tree.add_sub_node(r, r1);
    three_ary_tree.add_sub_node(r, r2);
    three_ary_tree.add_sub_node(r, r3);
    three_ary_tree.add_sub_node(r1, r4);
    three_ary_tree.add_sub_node(r2, r5);

     
     cout<<three_ary_tree;
     
    return a.exec();
}
