#pragma once
#include <iostream>

class Node {
     Node* link;
     int data;
public:
     Node(int val = 0) : data(val), link(NULL) {}
     Node* getLink() { return link; }
     void setLink(Node* p) { link = p; }
     void display() { std::cout << " " << data; }
     int getData() { return data; }
     void setData(int val) { data = val; }
}; 