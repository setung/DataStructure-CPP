#pragma once
#include "BinaryNode.h";
#include <queue>

class LinkedBinaryTree {
     
     BinaryNode* root;

public :
     LinkedBinaryTree():root(NULL){}
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
     int getCount() { return isEmpty() ? 0 : getCount(root); }
     int getCount(BinaryNode* node) {
          if (node == NULL) return 0;
          return 1 + getCount(node->getLeft()) + getCount(node->getRight());
     }
     int getHeight() { return isEmpty() ? 0 : getHeight(root); }
     int getHeight(BinaryNode* node) {
          if (node == NULL) return 0;
          int hLeft = getHeight(node->getLeft());
          int hRight = getHeight(node->getRight());
          return (hLeft>hRight) ? hLeft+1 : hRight+1; 
     }
     int getLeafCount() { return isEmpty() ? 0 : getLeafCount(root); }
     int getLeafCount(BinaryNode *node) {
          if (node == NULL) return 0;
          if (node->isLeaf()) return 1;
          else return getLeafCount(node->getLeft()) + getLeafCount(node->getRight()); 
     }

};