#include <string>
#define TABLE_SIZE 13
using namespace std;


// ���ڿ��� �� Ž��Ű�� ���ڷ� ��ȯ : ������ ���� ���
inline int transform(string key) {
	int number = 0;
	
	for (int i = 0; i < key.size(); i++)
		number += key[i];

	return number;
}

// �ؽ� �Լ� : ���� �Լ� ���
inline int hashFunction(string key) {
	return transform(key) % TABLE_SIZE;
}