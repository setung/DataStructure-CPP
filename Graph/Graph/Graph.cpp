#include <iostream>
#include "AdjMatGraph.h"
#include "AdjListGraph.h"
/*
     Graph ADT
     정점의 집합과 간선의 집합

     create()         := 그래프 생성
     isEmpty()        := 공백 상태인지 체크
     insertVertex(v)  := 그래프에 정점 v를 삽입
     insertEdge(u,v)  := 그래프에 간선(u,v)를 삽입
     deleteVertex(v)  := 그래프의 정점 v 삭제 , v와 연결된 간선 삭제
     deleteEdge(u,v)  := 그래프의 간선 (u,v)를 삭제
     adjacent(v)      := 정점 v에 인접한 모든 정점의 집합을 반환

*/


int main()
{
     AdjMatGraph matG;

     for (int i = 0; i < 4; i++)
          matG.insertVertex('A' + i);
     matG.insertEdge(0, 1);
     matG.insertEdge(0, 3);
     matG.insertEdge(1, 2);
     matG.insertEdge(1, 3);
     matG.insertEdge(2, 3);
     matG.display();


     AdjListGraph listG;
     for (int i = 0; i < 4; i++)
          listG.insertVertex('A' + i);
     listG.insertEdge(0, 1);
     listG.insertEdge(0, 3);
     listG.insertEdge(1, 2);
     listG.insertEdge(1, 3);
     listG.insertEdge(2, 3);
     listG.display();
}

