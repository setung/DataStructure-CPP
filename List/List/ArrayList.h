#pragma once
/*
     배열기반 리스트

     장점
      - 간단하게 구현 가능

     단점
      - 리스트의 사이즈가 제한됨
      - 데이터 삽입,삭제시 데이터를 이동 해야함.

      ATD
       - insert(pos,item)      := 배열 pos위치에 item 삽입
       - delete(pos)           := pos 위치에 있는 요소 제거
       - getEntry(pos)         := pos 위치에 있는 요소 반환
       - isEmpty()             := 공백 검사
       - isFull()              := 포화 검사
       - find(item)            := 배열에 item 요소가 있는지 검사
       - replace(pos,item)     := pos 위치에 있는 요소를 item으로 대체
       - size()                := 크기 개수 반환
       - display()             := 리스트 출력



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
               cout << "데이터 삽입 에러\n";
     }
     void remove(int pos) {
          if (!isEmpty() && pos >= 0 && pos <= length) {
               for (int i = pos + 1; i < length; i++)
                    data[i - 1] = data[i];
               length--;
          }
          else
               cout << "데이터 삭제 에러\n";
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
          cout << "리스트 전체 항목 수 : " << length << endl;
          for (int i = 0; i < length; i++)
               cout << data[i] << ' ';
          cout << endl;
          cout << endl;
     }

     

};
