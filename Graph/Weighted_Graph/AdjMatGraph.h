#pragma once

#include <iostream>
#include <queue>
#define MAX_VTXS 256
using namespace std;

class AdjMatGraph {
protected :
     int size;                          // 정점의 개수
     char vertices[MAX_VTXS];           // 정점의 이름
     int adj[MAX_VTXS][MAX_VTXS];       // 인접 행렬

public :
     AdjMatGraph() { reset(); }

     char getVertex(int i) { return vertices[i]; }
     int getEdge(int i, int j) { return adj[i][j]; }
     void setEdge(int i, int j, int val) { adj[i][j] = val; }

     bool isEmpty() { return size == 0; }
     bool isFull() { return size >= MAX_VTXS; }

     void reset() {
          size = 0;
          for (int i = 0; i < MAX_VTXS; i++)
               for (int j = 0; j < MAX_VTXS; j++)
                    setEdge(i, j, 0);
     }

     void insertVertex(char name) {
          if (!isFull())
               vertices[size++] = name;
          else
               cout << "Error: Graph's vertex is full\n";
     }

     void insertEdge(int u, int v) {
          setEdge(u, v, 1);
          setEdge(v, u, 1);   // 방향그래프에서는 삭제 됨.
     }

     void display() {
          cout << size << '\n';
          for (int i = 0; i < size; i++) {
               cout << getVertex(i) << ":  ";
               for (int j = 0; j < size; j++)
                    cout << getEdge(i, j)<< ' ';
               cout << '\n';
          }
     }
};

