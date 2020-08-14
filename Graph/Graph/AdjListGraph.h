#pragma once
#include "Node.h"
#include <queue>
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

class SrchALGraph : public AdjListGraph {
     bool visited[MAX_VTXS];

public :
     void resetVisited() {
          for (int i = 0; i < size; i++)
               visited[i] = false; 
     }

     bool isLinked(int u, int v) {
          for (Node* p = adj[u]; p != NULL; p = p->getLink())
               if (p->getId() == v) return true;
               else
                    false;
     }

     void DFS(int v) {
          visited[v] = true;
          cout << getVertex(v) << ' ';

          for (Node* p = adj[v]; p != NULL; p = p->getLink()) {
               if (!visited[p->getId()])
                    DFS(p->getId());
          }
     }

     void BFS(int v) {
          visited[v] = true;
          cout << getVertex(v) << ' ';
         
          queue<int> que;
          que.push(v);

          while (!que.empty()) {
               int v = que.front();
               que.pop();

               for (Node* w = adj[v]; w != NULL; w = w->getLink()) {
                    int id = w->getId();
                    if (!visited[id]) {
                         visited[id] = true;
                         cout << getVertex(id) << ' ';
                         que.push(id);
                    }
               }
          }
     }

};
