#pragma once
#include "Node.h"
#define MAX_VTXS 5

class AdjListGraph {
protected :
     int size;
     char vertices[MAX_VTXS];
     Node* adj[MAX_VTXS];

public :
     AdjListGraph() : size(0) {}
     ~AdjListGraph() { reset(); }
     void reset() {
          for (int i = 0; i < size; i++)
               if (adj[i] != NULL) delete adj[i];
          size = 0;
     }

     bool isEmpty() { return size == 0; }
     bool isFull() { return size >= MAX_VTXS; }
     char getVertex(int i) { return vertices[i]; }

     void insertVertex(char val) {
          if (!isFull()) {
               vertices[size] = val;
               adj[size++] = NULL;
          }
          else
               cout << "Error: Graph's vertex is full\n";

     }

     void insertEdge(int u, int v) {
          adj[u] = new Node(v, adj[u]);
          adj[v] = new Node(u, adj[v]);      // 방향그래프시 삭제
     }

     void display() {
          cout << size << endl;
          for (int i = 0; i < size; i++) {
               cout << getVertex(i) << ":  ";
               for (Node* v = adj[i]; v != NULL; v = v->getLink())
                    cout << getVertex(v->getId())<<' ';
               cout << endl;

          }
     }

     Node* adjacent(int v) { return adj[v]; }


};