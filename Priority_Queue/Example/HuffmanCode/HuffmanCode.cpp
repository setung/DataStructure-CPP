#include <iostream>
#include <vector>
#include "MinHeap.h"

void MakeTree(vector<int> v) {
     MinHeap heap;

     for (int i = 0; i < v.size(); i++)
          heap.insert(v[i]);

     for (int i = 1; i < v.size(); i++) {
          HeapNode e1 = heap.remove();
          HeapNode e2 = heap.remove();
          heap.insert(e1.getKey() + e2.getKey());
          cout << e1.getKey() << "+" << e2.getKey() << endl;
     }

}

int main()
{
     vector<int> v = { 15,12,8,6,4 };
     MakeTree(v);
}

