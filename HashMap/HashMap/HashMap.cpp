#include <iostream>
#include "HashMap.h"
#include "HashChainMap.h"
int main()
{
	HashMap hash;

	hash.addLinearProb("do", "반복");
	hash.addLinearProb("for", "반복");
	hash.addLinearProb("if", "분기");
	hash.addLinearProb("case", "분기");
	hash.addLinearProb("else", "분기");
	hash.addLinearProb("return", "반환");
	hash.addLinearProb("function", "함수");
	hash.display();
	hash.searchLinearProb("return");
	hash.searchLinearProb("class");
	hash.searchLinearProb("function");


	HashChainMap chainHash;

	chainHash.addRecord(new Node("do", "반복"));
	chainHash.addRecord(new Node("for", "반복"));
	chainHash.addRecord(new Node("if", "분기"));
	chainHash.addRecord(new Node("case", "분기"));
	chainHash.addRecord(new Node("else", "분기"));
	chainHash.addRecord(new Node("return", "반환"));
	chainHash.addRecord(new Node("function", "함수"));
	chainHash.display();
	chainHash.searchRecord("return");
	chainHash.searchRecord("class");
	chainHash.searchRecord("function");
}

