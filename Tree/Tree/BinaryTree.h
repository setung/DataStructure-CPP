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

     //순회
     void inoder() {
          cout << "\n inorder: ";
          inorder(root);
     }
     void inorder(BinaryNode* node) {
          if (node != NULL) {
               inorder(node->getLeft());
               cout << node->getData()<<" ";
               inorder(node->getRight());
          }
     }
     void preorder(){
          cout << "\n preorder: ";
          preorder(root);
     }
     void preorder(BinaryNode* node) {
          if (node != NULL) {
               cout << node->getData() << " ";
               preorder(node->getLeft());
               preorder(node->getRight());
          }
     }
     void postorder(){
          cout << "\n postorder: ";
          postorder(root);
     }
     void postorder(BinaryNode* node) {
          if (node != NULL) {
               postorder(node->getLeft());
               postorder(node->getRight());
               cout << node->getData() << " ";
          }
     }
     void levelorder(){
          cout << "\n leavelorder: ";
         
          if (!isEmpty()) {
               queue<BinaryNode*> q;
               q.push(root);
               while (!q.empty()) {
                    BinaryNode* n = q.front();
                    q.pop();
                    if (n != NULL) {
                         cout << n->getData() << ' ';
                         q.push(n->getLeft());
                         q.push(n->getRight());
                    }
               }
          }
          
     }

     //추가 연산
     int getCount() { return 0; }
     int getHeight() { return 0; }
     int getLeafCount() { return 0; }

};