//Client file
//******************************************************************
//
//   Programador : Isamar López Rodríguez 
//   Archivo     : menu.cpp               Fecha : 5/12/16
//
//******************************************************************
//    Propósito :This file holds the main that finally displays
//    the values of the class Binary Tree(base class) and Binary
//    Search Tree(derived class) while using a menu to guide the
//    user through a list.
//
//******************************************************************
#include <iostream>
#include "bst.h"
#include <string>
using namespace std;


int menu();
void execute(BST<string>&);

int main(){
    BST <string>bst;
    execute(bst);

    return 0;
}

// Display the menu and get a choice.
int menu(){


    int choice;

    cout <<"======================================================\n";
    cout << "\nWhat do you wish to do with your list?\n\n"
    << "1. Insert in tree\n"
    << "2. Search in tree\n"
    << "3. Remove from tree\n"
    << "4. Display tree\n"
    << "5. Height of tree\n"
    << "6. Number of nodes\n"
    << "7. Nunmber of leaves\n"
    << "8. Destroy tree\n"
    << "9. Quit program\n\n"
    << "Enter your choice: ";
    cin >> choice;

return choice;
}

//excecute the given choice between 1 and 9
void execute(BST<string>& bst){

    string element="";
    int index=0;
    int choice=0;
    do{

    choice=menu();

    switch (choice){
    case 1: cout << "\nWich element would you like to insert an element?\n";
             cin >> element;
             bst.insert(element);
             bst.inOrderTraversal();
    break;
    case 2:
        if(bst.isEmpty())
            cout<<"\nEmpty list. Cannot search for element.\n";
        else{
            cout << "\nWhich element would you like to search for?\n";
            cin>>element;
           if( bst.search(element))
               cout<<"\nElement found in list.\n";
           else
            cout<<"\nElement not found.\n";
        }
    break;
    case 3: cout << "\nWhich element would you like to remove an element?\n";
            cin >> element;
            bst.deleteNode(element);
            bst.inOrderTraversal();
    break;

    case 4:
        if(bst.isEmpty())
            cout<<"\nEmpty list. Cannot display.\n";
        else
        bst.inOrderTraversal();
    break;
    case 5: cout << "\nThe height of the tree is: "<<bst.treeHeight()<<endl;
    break;

    case 6: cout<<"The number of nodes is: "<<bst.treeNodeCount()<<endl;
    break;

    case 7: cout<<"The number of nodes is: "<<bst.treeNodeCount()<<endl;
    break;

    case 8: cout<< "\nList is now empty.\n";
            bst.destroyTree();
    break;

    case 9: cout << "\nProgram ending.\n";
    break;

    default: cout << "The valid choices are 1 through 8. Run the\n"
                  << "program again and select one of those.\n";
    }

    }while(choice !=9);

}




