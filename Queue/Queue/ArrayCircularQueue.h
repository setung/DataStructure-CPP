#pragma once
/*
     �迭��� ����ť

     ADT
       - enqueue(x)   := x�� ť�� �ǵڿ� �߰�.
       - dequeue      := ť�� �� �� ��Ҹ� ������ ��ȯ
       - isEmpty()    := ť�� ����ִ��� Ȯ��
       - peek()       := ť�� �Ǿ� ��� ��ȯ
       - isFull()     := ť�� ������ �ִ��� Ȯ��
       - size()       := ť�� �ִ� ��� ���� ��ȯ
       - display()    := ť�� �ִ� ��� ��� ���
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
          if (isFull()) cout << "��ȭ����\n";
          else {
               rear = (rear + 1) % MAX_QUEUE_SIZE;
               data[rear] = val;
          }

     }
     int dequeue() {
          if (isEmpty()) cout << "�������\n";
          else {
               front = (front + 1) % MAX_QUEUE_SIZE;
               return data[front];
          }
     }
     int peek() {
          if (isEmpty()) cout << "�������\n";
          else {
               return data[(front + 1) % MAX_QUEUE_SIZE];
          }
     }

     void display() {
          cout << "ť ���� : ";
          int max = (front < rear) ? rear : rear + MAX_QUEUE_SIZE;

          for (int i = front + 1; i <= max; i++)
               cout << "[" << data[i % MAX_QUEUE_SIZE] << "] ";

          cout << endl;
     }
};