#include <iostream>
#include "HashMap.h"
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
}

