#pragma once
#include "MinHeap.h"
#include "WGraph.h"

//union-find 연산을 처리하기 위한 클래스
class VertexSets {
     int parent[MAX_VTXS];         // 부모 정점의 id
     int nSets;                    // 집합 갯수

public:
     VertexSets(int n) : nSets(n) {
          for (int i = 0; i < nSets; i++)
               parent[i] = -1;
     }

     bool isRoot(int i) { return parent[i] < 0; }
     int findSet(int v) {                              // v가 속한 집합을 찾아 반환
          while (!isRoot(v)) v = parent[v];
          return v;
     }
     void unionSets(int s1, int s2) {                  //집합 s1을 집합 s2에 합침
          parent[s1] = s2;
          nSets--;
     }

};


class WGraphMST : public WGraph {
public :
     void kruskal() {
          MinHeap heap;

          for (int i = 0; i < size - 1; i++)
               for (int j = i + 1; j < size; j++)
                    if (hasEdge(i, j))
                         heap.insert(getEdge(i, j), i, j);

          VertexSets set(size);
          int edgeAccepted = 0;
          while (edgeAccepted < size - 1) {
               HeapNode e = heap.remove();
               int uset = set.findSet(e.getV1());
               int vset = set.findSet(e.getV2());

               if (uset != vset) {
                    cout << "간선추가 : " << getVertex(e.getV1()) << " - " << getVertex(e.getV2()) << "(" << e.getKey() << ")";
                    set.unionSets(uset, vset);
                    edgeAccepted++;
               }
          }

     }
};