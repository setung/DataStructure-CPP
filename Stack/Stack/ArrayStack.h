#pragma once
/*
     �迭��� ����

     ADT 
       - push(x)      := x�� ������ �ֻ�ܿ� �߰�.
       - pop()        := ������ �ֻ�� ��Ҹ� ������ ��ȯ
       - isEmpty()    := ������ ����ִ��� Ȯ��
       - peek()       := ������ �ֻ�� ��� ��ȯ 
       - isFull()     := ������ ������ �ִ��� Ȯ��
       - size()       := ���ÿ� �ִ� ��� ���� ��ȯ
       - display()    := ���ÿ� �ִ� ��� ��� ���
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