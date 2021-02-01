#include <iostream>
#include <vector>

using namespace std;

// 정렬 되지 않은 배열 탐색
// 시간복잡도 O(n)
int sequentialSearch(vector<int> list, int key, int low, int high) {
    for (int i = low; i <= high; i++)
        if (list[i] == key)
            return i;
    return -1;
}

// 정렬 된 배열 탐색
// 시간복잡도 O(n)
int sortedSequentialSearch(vector<int> list, int key, int low, int high) {
    for (int i = low; i <= high; i++)
        if (list[i] == key)
            return i;
    return -1;
}

// 이진 탐색
// 정렬된 배열에서 사용 가능.
// 시간 복잡도 O(log2n)
int binarySearch(vector<int> list, int key, int low, int high) {
    int mid;

    while (low <= high) {
        mid = (low + high) / 2;

        if (key == list[mid])
            return mid;
        else if (key < list[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1;
}

// 반복문을 이용한 보간 탐색
// 시간복잡도 O(log2n)
int interpolationSearch(vector<int> list, int key) {
    int low = 0;
    int high = list.size() - 1;

    while ((list[low] < key) && (key <= list[high])) {
        int j = (int)((float)(key - list[low]) / (list[high] - list[low]) * (high / low) + low;
        if (key > list[j]) low = j + 1;
        else if (key < list[j]) high = j - 1;
        else
            return j;
    }

    return -1;
}

int main()
{
    std::cout << "Hello World!\n";
}
