#pragma once
#include "Node.h"

class Linked_List {
     Node org;

public :
     Linked_List() : org(0) {}
     ~Linked_List() { clear(); }
     
     void clear() {
          while (!isEmpty()) {
               delete remove(0);
          }
     }
     Node* getHead() { return org.getLink(); }
     bool isEmpty() { return getHead() == nullptr; }

     Node* getEntry(int pos) {
          Node* n = &org;
          for (int i = -1; i < pos; i++, n = n->getLink()) {
               if (n == nullptr)
                    break;
          }

          return n;
     }

     void insert(int pos, Node* n) {
          Node* prev = getEntry(pos - 1);

          if (prev != nullptr)
               prev->insertNext(n);
     }

     Node* remove(int pos) {
          Node* prev = getEntry(pos - 1);
          return prev->removeNext();
     }

     Node* find(int val) {
          for (Node* p = getHead(); p != nullptr; p = p->getLink()) {
               if (p->hasData(val)) return p;
          }

          return nullptr;
     }

     void replace(int pos, Node* n) {
          Node* prev = getEntry(pos - 1);
          if (prev != nullptr) {
               delete prev->removeNext();
               prev->insertNext(n);
          }
     }

     int size() {
          int count = 0;
          for (Node* p = getHead(); p != nullptr; p = p->getLink())
               count++;
          return count;
     }

     void display() {
          cout << "전체 항목 수 : " << size() << endl;
          for (Node* p = getHead(); p != nullptr; p = p->getLink())
               p->display();
          cout << '\n';
     }



};