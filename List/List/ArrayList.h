#pragma once
/*
     �迭��� ����Ʈ

     ����
      - �����ϰ� ���� ����

     ����
      - ����Ʈ�� ����� ���ѵ�
      - ������ ����,������ �����͸� �̵� �ؾ���.

      ATD
       - insert(pos,item)      := �迭 pos��ġ�� item ����
       - delete(pos)           := pos ��ġ�� �ִ� ��� ����
       - getEntry(pos)         := pos ��ġ�� �ִ� ��� ��ȯ
       - isEmpty()             := ���� �˻�
       - isFull()              := ��ȭ �˻�
       - find(item)            := �迭�� item ��Ұ� �ִ��� �˻�
       - replace(pos,item)     := pos ��ġ�� �ִ� ��Ҹ� item���� ��ü
       - size()                := ũ�� ���� ��ȯ
       - display()             := ����Ʈ ���



*/

#include <iostream>

using namespace std;

#define MAX_LIST_SIZE 100

class ArrayList {
     int data[MAX_LIST_SIZE];
     int length;

public :
     ArrayList(void) { length = 0; };

     void insert(int pos, int e) {
          if (!isFull() && pos >= 0 && pos <= length) {
               for (int i = length; i > pos; i--) {
                    data[i] = data[i - 1];
               }
               data[pos] = e;
               length++;
          }
          else
               cout << "������ ���� ����\n";
     }
     void remove(int pos) {
          if (!isEmpty() && pos >= 0 && pos <= length) {
               for (int i = pos + 1; i < length; i++)
                    data[i - 1] = data[i];
               length--;
          }
          else
               cout << "������ ���� ����\n";
     }
     int getEntry(int pos) { return data[pos]; }
     bool isEmpty() { return length == 0; }
     bool isFull() { return length == MAX_LIST_SIZE; }
     bool find(int item) {
          for (int i = 0; i < length; i++)
               if (data[i] == item) return true;
               else false;
     }
     void replace(int pos, int e) {
          data[pos] = e;
     }
     int size() { return length; }
     void clear() { length = 0; }
     void display() {
          cout << "����Ʈ ��ü �׸� �� : " << length << endl;
          for (int i = 0; i < length; i++)
               cout << data[i] << ' ';
          cout << endl;
          cout << endl;
     }

     

};
