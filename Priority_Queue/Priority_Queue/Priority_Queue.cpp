#include <iostream>
#include "MaxHeap.h"

/*
     우선순위 큐
          배열, 링크드리스트로 구현이 가능하지만 
          보통 완전이진트리인 힙으로 구현을 함

     힙
      중복 허용함
      쵀대 힙 : 부모키가 자식키보다 크거나 같음
      최소 힙 : 반대


*/


void heapSort(int a[], int n) {
     MaxHeap h;
     for (int i = 0; i < n; i++)
          h.insert(a[i]);

     for (int i = n - 1; i >= 0; i--)
          a[i] = h.remove().getKey();
}

int main()
{
     MaxHeap heap;

     heap.insert(10);
     heap.insert(5);
     heap.insert(30);
     heap.insert(7);
     heap.insert(9);
     heap.insert(3);
     heap.insert(10);
     heap.display();

     heap.remove();
     heap.display();
     heap.remove();
     heap.display();
     heap.remove();
     heap.display();

     int data[10];
     cout << "힙정렬 전 : ";
     for (int i = 0; i < 10; i++) {
          data[i] = rand() % 100;
          cout << data[i] << ' ';
     }
     cout << '\n';

     heapSort(data, 10);

     cout << "힙정렬 후 : ";
     for (int i = 0; i < 10; i++) {
          cout << data[i] << ' ';
     }
     cout << '\n';
}

