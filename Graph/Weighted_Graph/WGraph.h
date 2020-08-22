#pragma once
#include "AdjMatGraph.h"
#include <queue>
#define INF 9999
/*
     ����ġ �׷���

     �ּҺ�� ���� Ʈ��
        - Kruskal�� MST �˰���
        - Prim



*/
class WGraph : public AdjMatGraph {
public:
     void insertEdge(int u, int v, int weight) {
          if (weight > INF)
               weight = INF;

          setEdge(u, v, weight);
     }

     bool hasEdge(int i, int j) { return (getEdge(i, j) < INF); }
};