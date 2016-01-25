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

	//My version
	for (int i = 1 ; i < 6 ; i++) {
		int j = i;
		while (j >= 0 && array[j] < array[j-1]) {
			int tmp = array[j-1];
			array[j-1] = array[j];
			array[j] = tmp;
			j = j-1;
		}
	}

	/*
	//Intro to Algo version
	for (int j = 1 ; j < 6 ; j++) {
		int key = array[j];
		int i = j-1;
		while (i >= 0 && array[i] > key) {
			array[i+1] = array[i];
			i = i-1;
			array[i+1] = key;
		}
	}
	*/

	for (int i=0; i<6; i++)
		std::cout << " " << array[i];

	return 0;
}
