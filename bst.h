//Implementation/Specification file
//******************************************************************
//
//   Programador : Isamar López Rodríguez 
//   Archivo     : bst.h                  Fecha : 5/12/16
//
//******************************************************************
//    Propósito :This file holds the derived class Binary Search
//    Tree with its public function members that manage
//    a list.
//
//******************************************************************
#ifndef BST_H
#define BST_H

#include "bt.h"

template<class Type>
class BST : public BT<Type>{
public:
    bool search(Type) const;

    void insert(Type);

    void deleteNode(const Type&);

    void deleteFromTree(Node<Type> * &);

}; //end of class BST declaration

#endif // BST_H

//class implementation

template<class Type>
bool BST<Type>::search(Type item) const{
    bool found = false;
    Node<Type> * current = BT<Type>::root;

    while(current != NULL && !found){
        if(item < current -> info)
            current = current -> llink;
        else if(item > current -> info)
            current = current -> rlink;
        else
            found = true;
    }//end while
    return found;
}

template<class Type>
void BST<Type>::insert(Type item){
    //always insert on leaves
    bool found = false;
    Node<Type> * current = BT<Type>::root;
    Node<Type> * parent = NULL;

    //search for insertion place
    while(current != NULL && !found){
        //move parent
        parent = current;

        //move current
        if(item < current -> info)
            current = current -> llink;
        else if(item > current -> info)
            current = current -> rlink;
        else
            found = true;
    }//end while

    if(found)
        cout << "Item is already in tree.\n";
    else{
        //insert
        Node<Type> * newNode = new Node<Type>(item);

        if(parent == NULL)
            BT<Type>::root = newNode;
        else if(item < parent -> info)
            parent -> llink = newNode;
        else
            parent -> rlink = newNode;
    }//end else
}//end function


//Delete Node
template <class Type>
void BST<Type>::deleteNode(const Type & deleteItem) {
    Node<Type> * current ;  // pointer to traverse the tree
    Node<Type> * previous ; // pointer behind current

    bool found = false;

    if ( BT<Type>::root == NULL)
        cout << "Cannot delete from the empty tree." << endl ;
    else{
        current =  BT<Type>::root ;

        previous =  BT<Type>::root ;

        while (current != NULL && !found){
            if (current -> info == deleteItem)
                found = true ;
            else{
                previous = current ;

                if (current -> info > deleteItem)
                    current = current -> llink ;

                else
                    current = current -> rlink ;
            }
        }

        if (current == NULL)
            cout << "The delete item is not in the tree.\n" << endl ;

        else if (found){
            if (current ==  BT<Type>::root)
                deleteFromTree(BT<Type>::root) ;

               else if (previous -> info > deleteItem)
                   deleteFromTree(previous -> llink);

               else
                   deleteFromTree(previous -> rlink);
           }
       }
   }


  // Delete from Tree
template <class Type>
void BST<Type>::deleteFromTree(Node<Type> * & ptr){
    Node<Type> * current ;  // pointer to traverse the tree
    Node<Type> * previous ; // pointer behind current
    Node<Type> * kod ;      // pointer to delete the node

    if (ptr == NULL)
        cerr << "Error: The node to be deleted is NULL.\n" << endl ;
// Case 1 - Node to be deleted is a leaf.
    else if(ptr -> llink == NULL && ptr -> rlink == NULL){
        kod = ptr;
        ptr = NULL;

        delete kod;
    }
    // Case 2 - Has no left subtree
    else if(ptr -> llink == NULL){
        kod = ptr;
        ptr = kod -> rlink;

        delete kod;
    }
    // Case 3 - Has no right subtree
    else if(ptr -> rlink == NULL){
        kod = ptr;
        ptr = kod -> llink;

        delete kod;
    }
    // Case 4 - Has non-empty left subtree and right subtree
    else{
        current = ptr -> llink;

        previous = NULL;

        while (current -> rlink != NULL){
            previous = current;
            current = current -> rlink;
        }

        ptr -> info = current -> info;
    // current did not move ; // current == p-> leftLink ; adjust p
        if (previous == NULL)
            ptr -> llink = current -> llink;
        else
            previous -> rlink = current -> llink;
            delete current;
    }
}

