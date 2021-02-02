
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
				cout << "�̹� ����Ǿ� ����\n";
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
				cout <<"Ž�� ����\n";
				p->display();
				return;
			}
		}
		cout << "Ž�� ���� : " << key << '\n';
	}
};