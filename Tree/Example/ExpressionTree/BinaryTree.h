#pragma once
#include "BinaryNode.h";
#include <queue>

class BinaryTree {
     
     BinaryNode* root;

public :
     BinaryTree():root(NULL){}
     void setRoot(BinaryNode* node) { root = node; }
     BinaryNode* getRoot()          { return root; }
     bool isEmpty()                 { return root == NULL; }


     int evaluate() {
          return evaluate(root);
     }
     int evaluate(BinaryNode* node) {
          if (node == NULL) return 0;
          if (node->isLeaf()) return node->getData();
          else {
               int op1 = evaluate(node->getLeft());
               int op2 = evaluate(node->getRight());
               
               switch (node->getData())
               {
                    case '+': return op1 + op2;
                    case '-': return op1 - op2;
                    case '*': return op1 * op2;
                    case '/': return op1 / op2;
                    
               }
               return 0;
          }
     }


};