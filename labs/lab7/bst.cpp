#include <iostream>
#include "bst.h"
#include <vector>
using namespace std;

int main()
{
    BinarySearchTree <int> bst;
    bst.insert(56);
    bst.insert(77);
    bst.insert(564);
    bst.insert(4);
    bst.insert(621);
    bst.insert(164);
    bst.insert(21);
    
    bst.printTree();
    cout << endl;
    cout << endl;

    //bst.remove(4);
    //bst.remove(21);
    //bst.remove(45);
    //bst.remove(56);
    //bst.remove(77);
    //bst.printTree();

    bst.printInternal();




return 0;    
}