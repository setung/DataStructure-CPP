#include <iostream>
using namespace std;


void hanoi(int num, char from, char by, char to) {
	if (num == 1) {
		cout << num << "을 " << from << "에서 " << to << "로 이동 \n";
	}
	else {
		hanoi(num - 1, from, to, by);
		cout << num << "을 " << from << "에서 " << to << "로 이동 \n";
		hanoi(num - 1, by, from, to);

	}
}

int main()
{
	hanoi(3, 'A', 'B', 'C');
}

