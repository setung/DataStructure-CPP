#include <string>
#define TABLE_SIZE 13
using namespace std;


// 문자열로 된 탐색키를 숫자로 변환 : 간단한 덧셈 방식
inline int transform(string key) {
	int number = 0;
	
	for (int i = 0; i < key.size(); i++)
		number += key[i];

	return number;
}

// 해싱 함수 : 제산 함수 사용
inline int hashFunction(string key) {
	return transform(key) % TABLE_SIZE;
}