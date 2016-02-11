#include <iostream>
#include <vector>
#include "Sort.h"

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

	Sort::MergeSort ( array, 0, length - 1 );
	Sort::DisplayArray ( array, length );

	array[0] = 6;
	array[1] = 5;
	array[2] = 4;
	array[3] = 3;
	array[4] = 2;
	array[5] = 1;

	Sort::InsertionSortAsc ( array, length );
	Sort::DisplayArray ( array, length );

	array[0] = 3;
	array[1] = 2;
	array[2] = 1;
	array[3] = 6;
	array[4] = 5;
	array[5] = 4;

	Sort::HeapSort ( array, length - 1 );
	Sort::DisplayArray ( array, length );

	return 0;
}
