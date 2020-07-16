#include "ThreadBinTree.h"

int main()
{
     ThreadBinTree tree;

     ThreadBinNode* n1 = new ThreadBinNode('A', NULL, NULL, true);
     ThreadBinNode* n2 = new ThreadBinNode('B', NULL, NULL, true);
     ThreadBinNode* n3 = new ThreadBinNode('C', n1, n2, false);
     ThreadBinNode* n4 = new ThreadBinNode('D', NULL, NULL, true);
     ThreadBinNode* n5 = new ThreadBinNode('E', NULL, NULL, false);
     ThreadBinNode* n6 = new ThreadBinNode('F', n4, n5, false);
     ThreadBinNode* n7 = new ThreadBinNode('G', n3, n6, false);

     tree.setRoot(n7);
     n1->setRight(n3);
     n2->setRight(n7);
     n4->setRight(n6);

     tree.threadInorder();
}

