#ifndef DEF_INSERTIONSORT
#define DEF_INSERTIONSORT

#include <iostream>

class InsertionSort {

	public:
		template <typename T>
		static void SortAsc ( T array[] );
		template <typename T>
		static void SortDesc ( T array[] );
		template <typename T>
		static void DisplayArray ( T array[], int length );
};


template <typename T>
void InsertionSort::SortAsc ( T array[] ) {
	for (int j = 1; j < 6; j++) {
		int tmp = array[j];
		int i = j;
		while (i>0 && array[i-1] > tmp) {
			array[i] = array[i-1];
			i = i-1;
		}
		array[i] = tmp;
	}
}

template <typename T>
void InsertionSort::SortDesc ( T array[] ) {
	for (int j = 1; j < 6; j++) {
		int tmp = array[j];
		int i = j;
		while (i>0 && array[i-1] < tmp) {
			array[i] = array[i-1];
			i = i-1;
		}
		array[i] = tmp;
	}
}

template <typename T>
void InsertionSort::DisplayArray( T array[], int length ) {
	for (int i=0; i<length; i++)
		std::cout << " " << array[i];
}

#endif
