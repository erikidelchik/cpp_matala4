#include "iostream"
#include "node.hpp"
#include <queue>
#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <QGraphicsTextItem>
#include <QVBoxLayout>
#include <QWidget>


#pragma once


using namespace std;

namespace ariel{

    class TreeNode : public QGraphicsEllipseItem {
        QString text;
    public:
        TreeNode(const QString& text="", QGraphicsItem* parent = nullptr):QGraphicsEllipseItem(parent) {
            this->text = text;
            setRect(-15, -15, 30, 30); // Node size

            QGraphicsTextItem* textItem = new QGraphicsTextItem(text, this);
            textItem->setPos(-10, -10); // Adjust text position within the node
        }
    };

    template<typename T>
    void addTreeNode(QGraphicsScene* scene,TreeNode* node, Node<T>* parent, Node<T>* child) {

        node->setPos(child->posX,child->posY); // Positioning node
        scene->addItem(node);

        QGraphicsLineItem* line = new QGraphicsLineItem(parent->posX, parent->posY, node->pos().x(), node->pos().y());
        scene->addItem(line); // Connecting line

    }



    template<typename T,int max_children=2>
    class Tree{
    private:
        Node<T>* root;


    public:

        Tree():root(nullptr){};

        void add_root(Node<T>& node){
            if(root){
                for(Node<T>* child:root->children){
                    node.children.push_back(child);
                }
            }
            root = &node;
            root->posX = 0;
            root->posY = 0;

        }

        void add_sub_node(Node<T>& n1,Node<T>& n2){
            if(n1.children.size()<max_children){

                n1.children.push_back(&n2);

                const double siblingSpacing = 80.0;

                // Calculate the X position of the new node
                if (n1.children.size() == 1) {
                    // First child
                    n2.posX = n1.posX;
                } else {
                    // Calculate X position for subsequent children
                    Node<T>* prevSibling = n1.children[n1.children.size() - 2];
                    n2.posX = prevSibling->posX + siblingSpacing;
                }

                // Adjust the X position of all children to be centered around the parent
                double totalWidth = (n1.children.size() - 1) * siblingSpacing;
                double startX = n1.posX - totalWidth / 2;
                for (size_t i = 0; i < n1.children.size(); ++i) {
                    n1.children[i]->posX = startX + i * siblingSpacing;
                }

                n2.posY = n1.posY + 80;
                return;
            }
            cout<<"number of children cannot be more than "<<max_children<<endl;
        }

        class iterator{
        public:
            int curr;
            vector<Node<T>*> order;
            Node<T>* p_curr;

            explicit iterator(Node<T>* root){
                curr = 0;
                if(!root) {
                    p_curr = nullptr;
                }

            }

            virtual iterator& operator++(){
                if(curr<order.size()) {
                    curr++;
                    p_curr = order[curr];
                    return *this;
                }
                else{
                    p_curr = nullptr;
                    return *this;
                }
            }

            const iterator operator++(int){
                iterator temp = *this;
                if(curr<order.size()) {
                    curr++;
                    p_curr = order[curr];
                    return temp;
                }
                else{
                    curr++;
                    p_curr = nullptr;
                    return temp;
                }
            }

            virtual bool operator==(const iterator& it) const{
                return this->p_curr==it.p_curr;
            }

            virtual bool operator!=(const iterator& it) const{
                return !(this->operator==(it));
            }

            virtual T get_value(){
                return p_curr->getValue();
            }

        };



        class pre_order_iterator:public iterator{

        public:

            explicit pre_order_iterator(Node<T>* root): iterator(root){
                if(root){
                    set_pre_order(root);
                    this->p_curr = this->order[0];
                }
            }


            void set_pre_order(Node<T>* node){
                if(node->children.size()==0){
                    this->order.push_back(node);
                    return;
                }
                else if(node->children.size()==1){
                    this->order.push_back(node);
                    set_pre_order(node->children[0]);
                }
                else if(node->children.size()==2){
                    this->order.push_back(node);
                    set_pre_order(node->children[0]);
                    set_pre_order(node->children[1]);
                }
            }

        };// end of pre-order iterator class



        class in_order_iterator:public iterator{

        public:
            explicit in_order_iterator(Node<T>* root): iterator(root){

                if(root){
                    set_in_order(root);
                    this->p_curr = this->order[0];
                }


            }

            void set_in_order(Node<T>* node){
                if(node->children.size()==0){
                    this->order.push_back(node);
                    return;
                }
                else if(node->children.size()==1){
                    set_in_order(node->children[0]);
                    this->order.push_back(node);
                }
                else if(node->children.size()==2){
                    set_in_order(node->children[0]);
                    this->order.push_back(node);
                    set_in_order(node->children[1]);
                }
            }

        };//end in-order iterator class

        class post_order_iterator:public iterator{
        public:
            explicit post_order_iterator(Node<T>* root): iterator(root){
                if(root){
                    set_post_order(root);
                    this->p_curr = this->order[0];
                }
            }

            void set_post_order(Node<T>* node){
                if(node->children.size()==0){
                    this->order.push_back(node);
                    return;
                }
                else if(node->children.size()==1){
                    set_post_order(node->children[0]);
                    this->order.push_back(node);
                }
                else if(node->children.size()==2){
                    set_post_order(node->children[0]);
                    set_post_order(node->children[1]);
                    this->order.push_back(node);
                }
            }

        };//end post-order iterator class

        class bfs_iterator{
        public:
            queue<Node<T>*> order;
            Node<T>* p_curr;


            explicit bfs_iterator(Node<T>* root){
                if(root){
                    p_curr = root;
                    order.push(root);
                }
                else p_curr = nullptr;
            }

            bfs_iterator operator++(){
                if(order.empty()){
                    p_curr= nullptr;
                    return *this;
                }

                if(!p_curr->children.empty()){
                    for(Node<T>* child:p_curr->children){
                        order.push(child);
                    }
                }

                order.pop();
                if(!order.empty())
                    p_curr = order.front();
                else p_curr = nullptr;

                return *this;
            }

            const bfs_iterator operator++(int){
                bfs_iterator tmp = *this;
                if(order.empty()){
                    p_curr= nullptr;
                    return tmp;
                }
                if(!p_curr->children.empty()){
                    for(Node<T>* child:p_curr->children){
                        order.push(child);
                    }
                }

                order.pop();
                if(!order.empty())
                    p_curr = order.front();
                else p_curr = nullptr;


                return tmp;
            }

            bool operator==(const bfs_iterator& it) const{
                return this->p_curr==it.p_curr;
            }

            bool operator!=(const bfs_iterator& it) const{
                return this->p_curr!=it.p_curr;
            }

            T get_value(){
                return p_curr->getValue();
            }

        };//end bfs iterator class


        pre_order_iterator begin_pre_order(){
            if(max_children==2)
                return pre_order_iterator(root);
        }

        pre_order_iterator end_pre_order(){
            if(max_children==2)
                return pre_order_iterator(nullptr);
        }

        in_order_iterator begin_in_order(){
            if(max_children==2)
                return in_order_iterator(root);
        }

        in_order_iterator end_in_order(){
            if(max_children==2)
                return in_order_iterator(nullptr);
        }

        post_order_iterator begin_post_order(){
            if(max_children==2)
                return post_order_iterator(root);
        }

        post_order_iterator end_post_order(){
            if(max_children==2)
                return post_order_iterator(nullptr);
        }

        bfs_iterator begin_bfs_scan(){
            return bfs_iterator(root);
        }

        bfs_iterator end_bfs_scan(){
            return bfs_iterator(nullptr);
        }

        in_order_iterator begin_dfs_scan(){
            if(max_children==2)
                return in_order_iterator(root);
        }

        in_order_iterator end_dfs_scan(){
            if(max_children==2)
                return in_order_iterator(nullptr);
        }

        friend ostream& operator<<(ostream& os,Tree& tree){
            QGraphicsScene* scene = new QGraphicsScene();


            bfs_iterator node = tree.begin_bfs_scan();

            TreeNode* treeRoot = new TreeNode(node.p_curr->toQString());
            scene->addItem(treeRoot);


            for (; node != tree.end_bfs_scan(); ++node){

                for(Node<T>* child:node.p_curr->children){
                    TreeNode* newNode = new TreeNode((child->toQString()));
                    addTreeNode(scene,newNode,node.p_curr,child);

                }


            }


            QGraphicsView* view = new QGraphicsView(scene);
            view->show();

            return os;
        }

        void min_heap(){
            bfs_iterator it1 = begin_bfs_scan();
            vector<T> values;

            for(;it1!=end_bfs_scan();++it1){
                values.push_back(it1.p_curr->getValue());
            }

            for(int i=0;i<values.size()-1;i++){
                for(int j=0;j<values.size()-1-i;j++){
                    if(values[j]>values[j+1]){
                        T temp = values[j];
                        values[j] = values[j+1];
                        values[j+1] = temp;
                    }
                }
            }

            int k = 0;
            bfs_iterator it2 = begin_bfs_scan();
            for(;it2!=end_bfs_scan();++it2) {
                it2.p_curr->value = values[k];
                k++;
            }
        }


    };


}

