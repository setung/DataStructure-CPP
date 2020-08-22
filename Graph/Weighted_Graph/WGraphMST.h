#pragma once
#include "MinHeap.h"
#include "WGraph.h"

//union-find ������ ó���ϱ� ���� Ŭ����
class VertexSets {
     int parent[MAX_VTXS];         // �θ� ������ id
     int nSets;                    // ���� ����

public:
     VertexSets(int n) : nSets(n) {
          for (int i = 0; i < nSets; i++)
               parent[i] = -1;
     }

     bool isRoot(int i) { return parent[i] < 0; }
     int findSet(int v) {                              // v�� ���� ������ ã�� ��ȯ
          while (!isRoot(v)) v = parent[v];
          return v;
     }
     void unionSets(int s1, int s2) {                  //���� s1�� ���� s2�� ��ħ
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
                    cout << "�����߰� : " << getVertex(e.getV1()) << " - " << getVertex(e.getV2()) << "(" << e.getKey() << ")";
                    set.unionSets(uset, vset);
                    edgeAccepted++;
               }
          }

     }
};