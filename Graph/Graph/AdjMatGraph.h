#pragma once
/*
     2차원 배열 기반 그래프
          - n개의 정점을 가지는 그래프는 항상 n^2의 크기를 가짐
          - 두 정점을 연결하는 간선의 존재 여부를 O(1) 알수 있음
          - 정점의 차수는 O(n)
          - 그래프의 존재하는 모든 간선의 수는 (On^2)

*/

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

class SrchANGraoh : public AdjMatGraph {
     bool visited[MAX_VTXS];

public:
     void resetVisited() {
          for (int i = 0; i < size; i++)
               visited[i] = false;
     }
     bool isLinked(int u, int v) { return getEdge(u, v) != 0; }

     void DFS(int v) {
          visited[v] = true;
          cout << getVertex(v) << ' ';

          for (int w = 0; w < size; w++) {
               if (isLinked(v, w) && !visited[w])
                    DFS(w);
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

               for(int w= 0; w<size; w++) 
                    if (isLinked(v, w) && !visited[w]) {
                         visited[w] = true;
                         cout << getVertex(w)<<' ';
                         que.push(w);
                    }

          }
     }
};