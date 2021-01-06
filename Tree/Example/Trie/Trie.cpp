#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int ALPABATS = 26;

class Tri {
private :
	vector<Tri*> arr= vector<Tri*>(ALPABATS);

public :
	Tri() {
		for (int i = 0; i < ALPABATS; i++)
			arr[i] = NULL;
	}

	~Tri() {
		for (int i = 0; i < ALPABATS; i++)
			if (arr[i] != NULL)
				delete arr[i];
	}

	void insert(string str, int index) {
		if (str[index] == '\0')
			return;

		int next = str[index] - 'a';

		if (arr[next] == NULL)
			arr[next] = new Tri();

		arr[next]->insert(str, index + 1);
	}

	bool find(string str, int index) {
		int next = str[index] - 'a';

		if (str[index] == '\0')
			return true;

		if (arr[next] == NULL)
			return false;

		return arr[next]->find(str, index+1);
	}


};

class Tri_Node {
private:
	Tri_Node* child[ALPABATS];

public:
	Tri_Node() {
		for (int i = 0; i < ALPABATS; i++)
			child[i] = NULL;
	}

	~Tri_Node() {
		for (int i = 0; i < ALPABATS; i++)
			if (child[i] != NULL)
				delete child[i];
	}

	int toNum(char c) {
		return tolower(c) - 'a';
	}

	void insert(const char* words) {
		if (*words == '\0')
			return;

		int next = toNum(*words);

		if (child[next] == NULL)
			child[next] = new Tri_Node();

		child[next]->insert(words + 1);
	}

	bool find(const char* words) {
		int next = toNum(*words);

		if (*words == '\0')
			return true;

		if (child[next] == NULL)
			return false;

		return child[next]->find(words + 1);
	}
};

void main()
{
	Tri tri;

	tri.insert("like",0);
	tri.insert("labc",0);

	if (tri.find("like",0))
		cout << true << endl;
	else
		cout << false << endl;

	if (tri.find("bike",0))
		cout << true << endl;
	else
		cout << false << endl;
	
}
