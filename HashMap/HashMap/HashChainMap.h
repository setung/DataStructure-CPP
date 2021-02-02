
#include "Node.h"
#include "hashFunctions.h"

class HashChainMap {
	Node* table[TABLE_SIZE];

public :
	HashChainMap() {
		for (int i = 0; i < TABLE_SIZE; i++) table[i] = nullptr;
	}
	void display() {
		for (int i = 0; i < TABLE_SIZE; i++) {
			cout << i << ' ';
			for (Node* p = table[i]; p != NULL; p = p->getLink())
				cout << p->getKey();
			cout << '\n';
		}
	}

	void addRecord(Node* n) {
		int hashValue = hashFunction(n->getKey());
		for (Node* p = table[hashValue]; p != NULL; p = p->getLink()) {
			if (p->equal(n->getKey())) {
				cout << "이미 저장되어 있음\n";
				delete n;
				return;
			}
		}

		n->setLink(table[hashValue]);
		table[hashValue] = n;
	}

	void searchRecord(string key) {
		int hashValue = hashFunction(key);
		for (Node* p = table[hashValue]; p != NULL; p = p->getLink()) {
			if (p->equal(key)) {
				cout <<"탐색 성공\n";
				p->display();
				return;
			}
		}
		cout << "탐색 실패 : " << key << '\n';
	}
};