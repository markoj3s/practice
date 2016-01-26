#include "InsertionSort.h"

using namespace std;

void InsertionSort::SortAsc ( int array[] ) {
	for (int j = 1; j < 6; j++) {
		int tmp = array[j];
		int i = j;
		while (i>0 && array[i-1] > tmp) {
			array[i] = array[i-1];
			array[i-1] = tmp;
			i = i-1;
		}
	}
}

void InsertionSort::SortDesc ( int array[] ) {
	for (int j = 1; j < 6; j++) {
		int tmp = array[j];
		int i = j;
		while (i>0 && array[i-1] < tmp) {
			array[i] = array[i-1];
			array[i-1] = tmp;
			i = i-1;
		}
	}
}

void InsertionSort::DisplayArray( int array[], int length ) {
	for (int i=0; i<length; i++)
		std::cout << " " << array[i];
}


