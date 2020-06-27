#pragma once
/*
     배열기반 스택

     ADT 
       - push(x)      := x를 스택의 최상단에 추가.
       - pop()        := 스택의 최상단 요소를 삭제후 반환
       - isEmpty()    := 스택이 비어있는지 확인
       - peek()       := 스택의 최상단 요소 반환 
       - isFull()     := 스택이 가득차 있는지 확인
       - size()       := 스택에 있는 요소 개수 반환
       - display()    := 스택에 있는 모든 요소 출력
*/

#include <iostream>
using namespace std;

const int MAX_STACK_SIZE = 20;

class ArrayStack {
     int top;
     int data[MAX_STACK_SIZE];

public :
     ArrayStack() { top = -1; }
     ~ArrayStack(){}
     bool isEmpty() { return top == -1; }
     bool isFull() { return top == MAX_STACK_SIZE - 1; }

     void push(int e) {
          if (isFull()) {
               cout << "Stack Over Flow\n";
               return;
          }
          data[++top] = e;
     }

     int pop() {
          if (isEmpty()) {
               cout << "Stack Under Flow\n";
               return -1;
          }
          return data[top--];
     }

     int peek() {
          if (isEmpty()) {
               cout << "Stack Under Flow\n";
               return -1;
          }
          return data[top];
     }
     
     void display() {
          for (int i = 0; i <= top; i++) {
               cout << data[i] << ' ';
          }
          cout << endl;
     }

     int size() {
          return top+1;
     }
};