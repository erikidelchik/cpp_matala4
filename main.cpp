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

    // Node<double> root_node = Node(1.9);
    // Tree<double,3> tree; // Binary tree that contains doubles.
    // tree.add_root(root_node);
    // Node<double> n1 = Node(1.6);
    // Node<double> n2 = Node(1.3);
    // Node<double> n3 = Node(1.2);
    // Node<double> n4 = Node(1.4);
    // Node<double> n5 = Node(1.1);
    // Node<double> n6 = Node(1.7);
    // Node<double> n7 = Node(1.8);

    Tree<Complex> tree;
    Node<Complex> root_node = Node(Complex(1,2));
    Node<Complex> n1 = Node(Complex(1,3));
    Node<Complex> n2 = Node(Complex(3,2));
    Node<Complex> n3 = Node(Complex(2,8));
    Node<Complex> n4 = Node(Complex(1,1));
    tree.add_root(root_node);

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);

    cout<<tree;

    tree.min_heap();

    cout<<tree;

    return a.exec();
}

