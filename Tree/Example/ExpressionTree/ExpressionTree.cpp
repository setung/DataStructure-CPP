#include <iostream>
#include "BinaryTree.h"

int main()
{
     BinaryTree tree;
     BinaryNode* n1 = new BinaryNode(3, NULL, NULL);
     BinaryNode* n2 = new BinaryNode(2, NULL, NULL);
     BinaryNode* n3 = new BinaryNode('*', n1, n2);
     BinaryNode* n4 = new BinaryNode(5, NULL, NULL);
     BinaryNode* n5 = new BinaryNode(6, NULL, NULL);
     BinaryNode* n6 = new BinaryNode('-', n4, n5);
     BinaryNode* n7 = new BinaryNode('+', n3, n6);
     tree.setRoot(n7);

     cout << tree.evaluate();


}
