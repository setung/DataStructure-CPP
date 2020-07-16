#pragma once
#include "ThreadBinNode.h"
#include <iostream>
using namespace std;

class ThreadBinTree {
     ThreadBinNode* root;
public :
     ThreadBinTree():root(NULL) {}
     void setRoot(ThreadBinNode* node) { root = node; }
     bool isEmpty() { return root == NULL; }

     void threadInorder() {
          if (!isEmpty()) {
               cout << "쓰레드 이진트리 : ";
               
               ThreadBinNode* q = root;
               while (q->getLeft())
                    q = q->getLeft();
               do {
                    cout << (char)q->getData() << ' ';
                    q = findSuccessor(q);
               } while (q);
               cout << '\n';
          }
     }

     ThreadBinNode* findSuccessor(ThreadBinNode* p) {
          ThreadBinNode* q = p->getRight();

          if (q == NULL || p->bThread) return q;

          while (q->getLeft() != NULL)
               q = q->getLeft();

          return q;
     }
};