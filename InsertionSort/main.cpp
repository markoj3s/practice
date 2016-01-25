#include <iostream>

using namespace std;

int main() {

	int array[6];
	array[0] = 6;
	array[1] = 5;
	array[2] = 4;
	array[3] = 3;
	array[4] = 2;
	array[5] = 1;

	for (int j = 1; j < 6; j++) {
		int tmp = array[j];
		int i = j;
		while (i>=0 && array[i-1] > tmp) {
			array[i] = array[i-1];
			array[i-1] = tmp;
			i = i-1;
		}
	}

	for (int i=0; i<6; i++)
		std::cout << " " << array[i];

	return 0;
}
