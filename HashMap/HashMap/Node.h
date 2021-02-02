#pragma once
#include "Record.h"

class Node : public Record {
	Node* link;

public :
	Node(string key, string val):Record(key,val),link(nullptr) {}
	Node* getLink() { return link; }
	void setLink(Node* next) { link = next; }
};
