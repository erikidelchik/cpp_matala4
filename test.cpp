#include "doctest.h"
#include "tree.hpp"

using namespace ariel;
using namespace std;

TEST_CASE("tree 2 ary double pre order"){
    Node<double> root_node = Node(1.1);
    Tree<double> tree; 
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
     
     string str = "";
     
     for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node)
    {
        str+=to_string(node.get_value()) + " ";
    } 
    CHECK(str=="1.100000 1.200000 1.400000 1.500000 1.300000 1.600000 ");
     

}

TEST_CASE("tree 2 ary double post order"){
    Node<double> root_node = Node(1.1);
    Tree<double> tree; 
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
     
     string str = "";
     
     for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node)
    {
        str+=to_string(node.get_value()) + " ";
    } 
    CHECK(str=="1.400000 1.500000 1.200000 1.600000 1.300000 1.100000 ");
     

}

TEST_CASE("tree 2 ary double in order"){
    Node<double> root_node = Node(1.1);
    Tree<double> tree; 
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
     
     string str = "";
     
     for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node)
    {
        str+=to_string(node.get_value()) + " ";
    } 
    CHECK(str=="1.400000 1.200000 1.500000 1.100000 1.600000 1.300000 ");
     

}

TEST_CASE("tree 2 ary double bfs"){
    Node<double> root_node = Node(1.1);
    Tree<double> tree; 
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
     
     string str = "";
     
     for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node)
    {
        str+=to_string(node.get_value()) + " ";
    } 
    CHECK(str=="1.100000 1.200000 1.300000 1.400000 1.500000 1.600000 ");
     

}

TEST_CASE("tree 2 ary double dfs"){
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
     
     string str = "";
     
     for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node)
    {
        str+=to_string(node.get_value()) + " ";
    } 
    CHECK(str=="1.400000 1.500000 1.200000 1.600000 1.300000 1.100000 ");

}

TEST_CASE("tree 3 ary Complex in order (prints in dfs order)"){
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
    
    string str = "";
     
    for (auto node = three_ary_tree.begin_in_order(); node != three_ary_tree.end_in_order(); ++node){
        str+=node.get_value().toString() + " ";
    } 
    CHECK(str=="1 + 5i 1 + 2i 1 + 6i 1 + 3i 1 + 4i 1 + 1i ");
    
    

}

TEST_CASE("min heap"){
    Tree<Complex,3> three_ary_tree; // 3-ary tree.
    Node<Complex> r = Node(Complex(7,5));
    
    Node<Complex> r1 = Node(Complex(2,3));
    Node<Complex> r2 = Node(Complex(1,4));
    Node<Complex> r3 = Node(Complex(5,3));
    Node<Complex> r4 = Node(Complex(1,2));
    Node<Complex> r5 = Node(Complex(2,6));
    
    three_ary_tree.add_root(r);
    three_ary_tree.add_sub_node(r, r1);
    three_ary_tree.add_sub_node(r, r2);
    three_ary_tree.add_sub_node(r, r3);
    three_ary_tree.add_sub_node(r1, r4);
    three_ary_tree.add_sub_node(r2, r5);
    
    string str = "";
     
    for (auto node = three_ary_tree.begin_bfs_scan(); node != three_ary_tree.end_bfs_scan(); ++node){
        str+=node.get_value().toString() + " ";
    } 
    
    CHECK(str=="7 + 5i 2 + 3i 1 + 4i 5 + 3i 1 + 2i 2 + 6i ");
    
    string str2 = "";
    
    three_ary_tree.min_heap();
    
    for (auto node = three_ary_tree.begin_bfs_scan(); node != three_ary_tree.end_bfs_scan(); ++node){
        str2+=node.get_value().toString() + " ";
    } 
    
    CHECK(str2=="1 + 2i 2 + 3i 1 + 4i 5 + 3i 2 + 6i 7 + 5i ");
    

}


