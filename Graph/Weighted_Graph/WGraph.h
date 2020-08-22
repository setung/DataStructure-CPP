#pragma once
#include "AdjMatGraph.h"
#include <queue>
#define INF 9999
/*
     가중치 그래프

     최소비용 신장 트리
        - Kruskal의 MST 알고리즘
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