//erikidelchik@gmail.com


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

    Node<double> root_node = Node(1.1);
    Tree<double> tree; // Binary tree that contains doubles.
    tree.add_root(root_node);
    Node<double> n1 = Node(1.2);
    Node<double> n2 = Node(1.3);
    Node<double> n3 = Node(1.4);
    Node<double> n4 = Node(1.5);
    Node<double> n5 = Node(1.6);

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    // The tree should look like:
    /**
     *       root = 1.1
     *     /       \
     *    1.2      1.3
     *   /  \      /
     *  1.4  1.5  1.6
     */

    for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node)
    {
        cout << node.get_value() << endl;
    } // prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6
    cout<<"\n";

    for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node)
    {
        cout << node.get_value() << endl;
    } // prints: 1.4, 1.5, 1.2, 1.6, 1.3, 1.1
    cout<<"\n";

    for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node)
    {
        cout << node.get_value() << endl;
    } // prints: 1.4, 1.2, 1.5, 1.1, 1.6, 1.3
    cout<<"\n";

     for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node)
     {
         cout << node.get_value() << endl;
     } // prints: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6
     cout<<"\n";

    cout << tree; // Should print the graph using GUI.


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

     // The tree should look like:
    /**
     *       root = 1.1
     *     /      |     \
     *    1.2    1.3    1.4
     *   /        |
     *  1.5      1.6
     */
     cout<<three_ary_tree;
     
    return a.exec();
}
