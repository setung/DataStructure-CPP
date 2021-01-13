#include <iostream>
#include <vector>
#include <string>
using namespace std;

#pragma region func
inline void swap(int& x, int& y) {
    int t = x;
    x = y;
    y = t;
}

static void initRandom(vector<int> &list, int max = 100) {
    for (int i = 0; i < list.size(); i++)
        list[i] = (rand() % max);
}

static void printArray(vector<int> &list, string str) {
    cout << str << " = ";
    for (int a : list)
        cout << a << ' ';
    cout << '\n';
}
#pragma endregion

#pragma region 선택 정렬
void selectionSort(vector<int> &list) {
    for (int i = 0; i < list.size() - 1; i++) {
        int least = i;
        for (int j = i + 1; j < list.size(); j++)
            if (list[j] < list[least]) least = j;
        
        swap(list[i], list[least]);
    }
}
#pragma endregion

#pragma region 삽입 정렬
void insertionSort(vector<int>& list) {
    for (int i = 1; i < list.size(); i++) {
        int key = list[i];
        int j;
        for (j = i - 1; j > -1 && list[j] > key; j--)
              list[j + 1] = list[j];

        list[j+1] = key;
    }
}
#pragma endregion

#pragma region 버블 정렬
void bubbleSort(vector<int>& list) {
  /*  for (int i = list.size() - 1; i > 0; i--) {
        for (int j = 0; j < i; j++)
            if (list[j] > list[j + 1])
                swap(list[j], list[j + 1]);
    }*/

    for (int i = 0; i < list.size(); i++) {
        for(int j =0; j<list.size()-1-i; j++)
            if(list[j] >list[j+1])
                swap(list[j], list[j + 1]);
    }
}
#pragma endregion

#pragma region 셸 정렬
void sortGapInsertion(vector<int>& list, int first, int last, int gap) {
    int i, j, key;
    for (i = first + gap; i <= last; i = i + gap) {
        key = list[i];
        for (j = i - gap; j >= first && key < list[j]; j = j - gap)
            list[j + gap] = list[j];
        list[j + gap] = key;
    }
}
void shellSort(vector<int>& list) {
    for (int gap = list.size() / 2; gap > 0; gap = gap / 2) {
        printArray(list, "Shell...");
        if (gap % 2 == 0) gap++;
        for (int i = 0; i < gap; i++)
            sortGapInsertion(list, i, list.size() - 1, gap);
    }
}
#pragma endregion

#pragma region 합병 정렬
void merge(vector<int> &list, int left, int mid, int right) {
    int i, j, k = left, l;
    vector<int> sorted(list.size());

    for (i = left, j = mid + 1; i <= mid && j <= right;)
        sorted[k++] = (list[i] <= list[j] ? list[i++] : list[j++]);

    if (i > mid)
        for (l = j; l <= right; l++,k++)
            sorted[k] = (list[l]);
    else
        for (l = i; l <= mid; l++, k++)
            sorted[k] = (list[l]);

    for (l = left; l <= right; l++)
        list[l] = sorted[l];
}

void mergeSort(vector<int>& list, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(list, left, mid);
        mergeSort(list, mid + 1, right);
        merge(list, left, mid, right);
    }
}
#pragma endregion

#pragma region 퀵 정렬
int partition(vector<int>& list, int left, int right) {
    int low = left;
    int high = right + 1;
    int pivot = list[left];
    do {
        do {
            low++;
        } while (low <= right && list[low] < pivot);

        do {
            high--;
        } while (high >= left && list[high] > pivot);

        if (low < high)
            swap(list[low], list[high]);
    } while (low < high);

    swap(list[left], list[high]);
   
    return high;
}

void quickSort(vector<int>& list, int left, int right) {
    if (left < right) {
        int q = partition(list, left, right);
        quickSort(list, left, q - 1);
        quickSort(list, q+1, right);
    }
}
#pragma endregion


int main()
{
    vector<int> list(16);
    initRandom(list);
    printArray(list, "Original");
    quickSort(list,0,15);
    printArray(list, "quickSort");
}

