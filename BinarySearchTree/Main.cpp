///////////////////////////////////////
// Workfile    : Main.cpp
// Author      : Matthias Schett
// Date        : 04-06-2013
// Description : BinarySearch Tree
// Remarks     : -
// Revision    : 0
///////////////////////////////////////


#include <iostream>
#include <vld.h>
#include "BinarySearchTree.h"


using namespace std;

void Print(int const x){
    cout << x << endl;
}

int main(){

    BinarySearchTree<int> tree;

    cout << std::boolalpha << "Insert Operation: " << tree.Insert(5) << endl;
    cout << "Insert Operation: " << tree.Insert(4) << endl;
    cout << "Insert Operation: " << tree.Insert(3) << endl;
    cout << "Insert Operation: " << tree.Insert(2) << endl;
    cout << "Insert Operation: " << tree.Insert(6) << endl;
    cout << "Insert Operation: " << tree.Insert(7) << endl;
    cout << "Insert Operation: " << tree.Insert(8) << endl;
    cout << "Insert Operation: " << tree.Insert(3) << endl;
    
    cout << endl << "Print In Order: " << endl;
    tree.VisitInOrder(Print);
    cout << endl << endl << "Print Post Order" << endl;
    tree.VisitPostOrder(Print);
    cout << endl << endl << "Print Pre Order" << endl;
    tree.VisitPreOrder(Print);

    
    BinarySearchTree<int> tree2 (tree);
    cout << endl << "Print In Order of copy ctor: " << endl;
    tree.VisitInOrder(Print);
    
    BinarySearchTree<int> tree3 = tree;
    cout << endl << "Print In Order of assigment: " << endl;
    tree.VisitInOrder(Print);


    cin.get();
    return 0;
}