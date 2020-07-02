#pragma once
#include <iostream>
using namespace std;

class Node {
     Node* link;
     int data;

public :
     Node(int val = 0) :data(val), link(nullptr) {};
     Node* getLink() { return link; }
     void setLink(Node* next) { link = next; }
     void display() { cout << data << ' '; }
     bool hasData(int val) { return data == val; }

     void insertNext(Node* n) {
          if (n != nullptr) {
               n->link = link;
               link = n;
          }
     }

     Node* removeNext() {
          Node* removed = link;

          if(removed != nullptr)
               link = removed->link;

          return removed;
     }

};