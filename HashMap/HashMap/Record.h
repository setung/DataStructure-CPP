#include <iostream>
#include <string>
#define KEY_SIZE 64
#define VALUE_SIZE 64
using namespace std;

class Record {
	string key;
	string value;

public :
	Record(string k = "", string v = "") { set(k, v); }
	void set(string k, string v = "") {
		key = k;
		value = v;
	}
	void reset() { set("", ""); }
	bool isEmpty() { return key.empty(); }
	bool equal(string k) { return k == key; }
	void display() { cout << key << " = " << value << '\n'; }
	string getKey() { return key; }
};