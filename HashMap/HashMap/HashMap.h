#include "Record.h"
#include "hashFunctions.h"
#include <vector>
using namespace std;

class HashMap {
	Record table[TABLE_SIZE];
public :
	HashMap() { reset(); }
	void reset() {
		for (int i = 0; i < TABLE_SIZE; i++)
			table[i].reset();
	}

	void display() {
		for (int i = 0; i < TABLE_SIZE; i++) {
			cout << i << " "; 
			table[i].display();
		}
	}

	void addLinearProb(string key, string value) {
		int i, hashValue;
		hashValue = i = hashFunction(key);

		while (table[i].isEmpty() == false) {
			if (table[i].equal(key)) {
				cout << '[' << key << ']' << " Ž��Ű�� �ߺ� �Ǿ����ϴ�.\n";
				return;
			}

			i = (i + 1) % TABLE_SIZE;
			if (i == hashValue) {
				cout << '[' << key << ']' << " ���̺��� ���� á���ϴ�.\n";
				return;
			}
		}

		table[i].set(key, value);
	}

	Record* searchLinearProb(string key) {
		int i, hashValue;
		hashValue = i = hashFunction(key);

		while (table[i].isEmpty() == false) {
			if (table[i].equal(key)) {
				cout << '[' << key << ']' << " Ž�� ����. "<< i << "\n";
				table[i].display();
				return table+i;
			}

			i = (i + 1) % TABLE_SIZE;
			if (i == hashValue)  break;
		}

		cout << '[' << key << ']' << " Ž�� ����: ã�� ���� ���̺� ����.\n";
		return nullptr;
	}
};