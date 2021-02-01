#pragma once
#include <iostream>
#include <vector>

using namespace std;

struct Index
{
	int key;
	int index;
};

int sequentialSearch(vector<int> list, int key, int low, int high) {
	for (int i = low; i <= high; i++)
		if (list[i] == key)
			return i;
	return -1;
}

// 시간복잡도 O(m + n/m)
int indexedSearch(vector<int> list, int nList, Index* tbl, int nTbl, int key) {
	if (key < list[0] || key > list[nList - 1])
		return -1;

	for (int i = 0; i < nTbl - 1; i++) {
		if (tbl[i].key <= key && tbl[i + 1].key > key)
			return sequentialSearch(list, key, tbl[i].index, tbl[i + 1].index);
	}
	return sequentialSearch(list, key, tbl[nTbl - 1].index, nList);

}
