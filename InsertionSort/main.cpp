#include <iostream>
#include "InsertionSort.h"

using namespace std;

int main() {

	int const length(6);
	int array[length];
	array[0] = 6;
	array[1] = 5;
	array[2] = 4;
	array[3] = 3;
	array[4] = 2;
	array[5] = 1;

	InsertionSort::SortDesc<int>(array);
	InsertionSort::DisplayArray<int>(array, length);

	return 0;
}
