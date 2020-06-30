#pragma once
/*
     배열기반 원형 덱

     ADT
       - addFront(e)
       - deleteFront()
       - addRear(e)
       - deleteRear()
       - isEmpty()
       - isFull()
       - getFront()
       - getRear()
       - deisplay()
*/


#include <iostream>
#define MAX_QUEUE_SIZE 100
using namespace std;

class ArrayCircularDeque {
protected:
     int front;
     int rear;
     int data[MAX_QUEUE_SIZE];

public:
     ArrayCircularDeque() { front = rear = 0; }
     bool isEmpty() { return front == rear; }
     bool isFull() { return (rear + 1) % MAX_QUEUE_SIZE == front; }

     void addRear(int val) {
          if (isFull()) cout << "포화상태\n";
          else {
               rear = (rear + 1) % MAX_QUEUE_SIZE;
               data[rear] = val;
          }
     }
     int deleteFront() {
          if (isEmpty()) cout << "공백상태\n";
          else {
               front = (front + 1) % MAX_QUEUE_SIZE;
               return data[front];
          }
     }
     int getFront() {
          if (isEmpty()) cout << "공백상태\n";
          else {
               return data[(front + 1) % MAX_QUEUE_SIZE];
          }
     }
     void addFront(int val) {
          if(isFull()) cout << "포화상태\n";
          else {
               data[front] = val;
               front = (front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
          }
     }
     int deleteRear() {
          if (isEmpty()) {
               cout << "공백상태\n";
               return -1;
          }
          else {
               int ret = data[rear];
               rear = (rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
               return ret;
          }
     }

     void display() {
          cout << "덱 내용 : ";
          int max = (front < rear) ? rear : rear + MAX_QUEUE_SIZE;

          for (int i = front + 1; i <= max; i++)
               cout << "[" << data[i % MAX_QUEUE_SIZE] << "] ";

          cout << endl;
     }
};