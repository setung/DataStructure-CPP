
/*
     우선순위 큐 (최대힙) ADT
          - isEmpty()          := 우선순위 큐가 비어있는지 확인
          - isFull(int i)      := 우선순위 큐가 포화상태인지 확인
          - getParent(int i)   := i번째 노드의 부모노드 반환
          - getLeft(int i)     := i번째 노드의 왼쪽자식노드 반환
          - insert(int key)    := i번쨰 노드의 오른쪽자식노드 반환
          - remove()           := 우선순위 가장 높은 노드 삭제 및 반환
          - find()             := 우선순위 가장 높은 노드 반환
          - display()          := 우선순위 큐 노드출력 

*/

#pragma once
#include "HeapNode.h"
#define MAX_ELEMENT 200

class MaxHeap
{
     HeapNode node[MAX_ELEMENT];
     int size;

public:
     MaxHeap() : size(0) {}
     bool isEmpty() { return size == 0; }
     bool isFull() { return size == MAX_ELEMENT - 1; }

     HeapNode& getParent(int i) { return node[i / 2]; }
     HeapNode& getLeft(int i) { return node[i * 2]; }
     HeapNode& getRight(int i) { return node[i * 2 + 1]; }
     
     void insert(int key) {
          if (isFull()) return;

          int i = ++size;

          while (i != 1 && key > getParent(i).getKey()) {
               node[i] = getParent(i);
               i /= 2;
          }

          node[i].setKey(key);
     }

     HeapNode remove() {
          if (isEmpty()) return NULL;
          HeapNode item = node[1];
          HeapNode last = node[size--];
          int parent = 1;
          int child = 2;

          while (child <= size) {
               if (child < size && getLeft(parent).getKey() < getRight(parent).getKey())
                    child++;

               if (last.getKey() >= node[child].getKey())
                    break;

               node[parent] = node[child];
               parent = child;
               child *= 2;
          }

          node[parent] = last;

          return item;
     }
     HeapNode find() {
          return NULL;
     }

     void display() {
          for (int i = 1, level = 1; i <= size; i++) {
               if (i == level) {
                    cout << '\n';
                    level *= 2;
               }
               node[i].display();
          }
          cout << "\n-------------------\n";
     }

};
