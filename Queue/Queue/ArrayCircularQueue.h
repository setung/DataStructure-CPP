#pragma once
/*
     배열기반 원형큐

     ADT
       - enqueue(x)   := x를 큐의 맨뒤에 추가.
       - dequeue      := 큐의 맨 앞 요소를 삭제후 반환
       - isEmpty()    := 큐가 비어있는지 확인
       - peek()       := 큐의 맨앞 요소 반환
       - isFull()     := 큐가 가득차 있는지 확인
       - size()       := 큐에 있는 요소 개수 반환
       - display()    := 큐에 있는 모든 요소 출력
*/

#include <iostream>
#define MAX_QUEUE_SIZE 100

using namespace std;

class ArrayCircularQueue {
protected:
     int front;
     int rear;
     int data[MAX_QUEUE_SIZE];

public:
     ArrayCircularQueue() { front = rear = 0; }
     bool isEmpty() { return front == rear; }
     bool isFull() { return (rear + 1) % MAX_QUEUE_SIZE == front; }

     void enqueue(int val) {
          if (isFull()) cout << "포화상태\n";
          else {
               rear = (rear + 1) % MAX_QUEUE_SIZE;
               data[rear] = val;
          }

     }
     int dequeue() {
          if (isEmpty()) cout << "공백상태\n";
          else {
               front = (front + 1) % MAX_QUEUE_SIZE;
               return data[front];
          }
     }
     int peek() {
          if (isEmpty()) cout << "공백상태\n";
          else {
               return data[(front + 1) % MAX_QUEUE_SIZE];
          }
     }

     void display() {
          cout << "큐 내용 : ";
          int max = (front < rear) ? rear : rear + MAX_QUEUE_SIZE;

          for (int i = front + 1; i <= max; i++)
               cout << "[" << data[i % MAX_QUEUE_SIZE] << "] ";

          cout << endl;
     }
};