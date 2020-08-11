#include <iostream>
#include <functional>
#include <queue>
#include <vector>
using namespace std;

vector<int> heapSortDec(vector<int> v) {
     priority_queue<int> maxHeap;

     for (int i = 0; i < v.size(); i++)
          maxHeap.push(v[i]);

     for (int i = 0; i < v.size(); i++) {
          v[i] = maxHeap.top();
          maxHeap.pop();
     }

     return v;
}

vector<int> heapSortInc(vector<int> v) {
     priority_queue<int, vector<int>, greater<int>> minHeap;

     for (int i = 0; i < v.size(); i++)
          minHeap.push(v[i]);

     for (int i = 0; i < v.size(); i++) {
          v[i] = minHeap.top();
          minHeap.pop();
     }

     return v;
}


int main()
{
     vector<int> v = { 1, 5, 7, 3, 4, 6, 10 };

     cout << "정렬 전 : ";
     for (int i = 0; i < v.size(); i++)
     {
          cout << v[i] << ' ';
     }
     cout << endl;

     v = heapSortDec(v);

     cout << "오름차순 : ";
     for (int i = 0; i < v.size(); i++)
     {
          cout << v[i] << ' ';
     }
     cout << endl;

     v = heapSortInc(v);

     cout << "내림차순 : ";
     for (int i = 0; i < v.size(); i++)
     {
          cout << v[i] << ' ';
     }
     cout << endl;

}

