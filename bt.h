//Implementation/Specification file
//******************************************************************
//
//   Programador : Isamar López Rodríguez CCOM 3034 Sección 0U1
//   Num. Est.   : 801-08-3174            Primer Semestre 2016-2017
//   Asignación 9                         Prof. R. J. Colorado
//   Archivo     : bt.h                   Fecha : 5/12/16
//
//******************************************************************
//    Propósito :This file holds the base class Binary Tree with
//    its private, protected and public data members and functions
//    that manage a list.
//
//******************************************************************

#ifndef BT_H
#define BT_H
#include <iostream>

using namespace std;

template<class Type>
struct Node{
    //members in struct is by default public
    Type info;
    Node<Type> * llink; //left subtree
    Node<Type> * rlink; //right subtree

    Node(Type item) : info(item), llink(NULL), rlink(NULL) {}
}; //end of Node struct
 //class binary tree is base class for binary search tree
template<class Type>
class BT{


protected:
    Node<Type> * root;

public:

    //constructor
    BT();

    //copy constructor
    BT(const BT<Type> & other);

    //OAO
    const BT<Type> & operator=(const BT<Type> &);

    //destructor
    ~BT();

    //destroy tree, clear function
    //that empties the tree
    void destroyTree();

    //observers
    bool isEmpty() const;
    int treeHeight() const;
    int treeNodeCount() const;
    int treeLeavesCount() const;
    void inOrderTraversal() const; //prints to screen

private:

    //copy function to be used by copy constructor and OAO
    void copyTree(Node<Type> * &, Node<Type> *);

    //helper functions implemented recursively
    void destroy(Node<Type> *&);

    //height = number of edges on longest path
    int height(Node<Type> *) const;

    //returns longest path on either side
    int max(int, int) const;

    int nodeCount(Node<Type> *) const;
    int leavesCount(Node<Type> *) const;
    void inOrder(Node<Type> *) const;

};

#endif // BT_H

//wrapper functions call helper (recursive) functions

//class impementation
//constructor
template<class Type>
BT<Type>::BT() : root(NULL) {}

//copy constructor
template<class Type>
BT<Type>::BT(const BT<Type> & other){
    copyTree(root, other.root);
}

//OAO
template<class Type>
const BT<Type> & BT<Type>:: operator=(const BT<Type> & other){

    if(this != &other){

        destroy(root);
        copyTree(root, other.root);
    }

return * this;
}

//destructor
template<class Type>
BT<Type>::~BT(){
    destroy(root);
}

//destroy tree
template<class Type>
void BT<Type>::destroyTree(){
    destroy(root);
}

//observers
template<class Type>
bool BT<Type>::isEmpty() const{
    return(root == NULL);
}

template<class Type>
int BT<Type>::treeHeight() const{
    //invoke helper function
    return(height(root));
}

template<class Type>
int BT<Type>::treeNodeCount() const{
    return(nodeCount(root));
}

template<class Type>
int BT<Type>::treeLeavesCount() const{
    return(leavesCount(root));
}

template<class Type>
void BT<Type>::inOrderTraversal() const{
    if(isEmpty())
        cout << "Empty tree.\n";
    else
        inOrder(root);
}

//helper functions implemented recursively
template<class Type>
void BT<Type>::destroy(Node<Type> *&ptr){
    //not tail end recursive
    if(ptr != NULL){
        destroy(ptr->llink);
        destroy(ptr->rlink);
        delete ptr;
        ptr = NULL;
    }
}
//copy function to be used by copy constructor and OAO
template<class Type>
void BT<Type>::copyTree(Node<Type> * & copy, Node<Type> *original){
    if(original == NULL)
        copy=NULL;
    else{
        copy =new Node<Type>(original->info);
        copyTree(copy->llink, original->llink);//leftLink
        copyTree(copy->rlink, original->rlink);//rightLink
    }
}


template<class Type>
int BT<Type>::height(Node<Type> *ptr) const{
    //base case when root == NULL
    if(ptr == NULL)
        return -1;
    else
        //not tail end recursive
        return 1 + max(height(ptr->llink),
                       height(ptr->rlink));
}

//returns longest path on either side
template<class Type>
int BT<Type>::max(int l, int r) const{
    return(l >= r ? l : r);
}

template<class Type>
int BT<Type>::nodeCount(Node<Type> *ptr) const{
    if(ptr == NULL)
        return 0;
    else{
        return (1 + nodeCount(ptr -> llink) //count nodes on left subtree
                  + nodeCount(ptr -> rlink)); //count nodes on right subtree
    }
}

template<class Type>
int BT<Type>::leavesCount(Node<Type> *ptr) const{
    if(ptr == NULL) //base case 1
        return 0;
    else{ //base case 2
       if(ptr -> llink == NULL && ptr -> rlink == NULL) //base
           return 1;
       else
           return(leavesCount(ptr -> llink)
                  + leavesCount(ptr -> rlink));
    }
}

template<class Type>
void BT<Type>::inOrder(Node<Type> *ptr) const{
    if(ptr != NULL){
        inOrder(ptr -> llink); //left subtree
        cout << ptr -> info << endl; //displays both nodes
        inOrder(ptr -> rlink); //right subtree
    }
}
