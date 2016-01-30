#include <iostream>
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

	Sort::InsertionSortAsc ( array );
	Sort::DisplayArray ( array, length );

	return 0;
}
