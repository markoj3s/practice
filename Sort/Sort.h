#ifndef DEF_SORT
#define DEF_SORT

#include <iostream>
#include <math.h>

class Sort {

	public:
		template <typename T>
		static void Merge ( T A[], int p, int q, int r );
		template <typename T>
		static void MergeSort ( T A[], int p, int r );
		template <typename T>
		static void InsertionSortAsc ( T array[] );
		template <typename T>
		static void InsertionSortDesc ( T array[] );
		template <typename T>
		static void DisplayArray ( T array[], int length );
};


template <typename T>
void Sort::Merge ( T A[], int p, int q, int r ) {
	int n1 = q - p + 1;
	int n2 = r - q;

	T L[n1];
	T R[n2];

	for ( int i = 0; i < n1; i++ ) {
		L[i] = A[p+i];
	}

	for ( int j = 0; j < n2; j++ ) {
		R[j] = A[q+j+1];
	}

	L[n1] = 2147483647;
	R[n2] = 2147483647;

	int i = 0;
	int j = 0;

	for ( int k = p ; k <= r ; k++) {
		if ( L[i] <= R[j] ) {
			A[k] = L[i];
			i++;
		} else {
			A[k] = R[j];
			j++;
		}
	}
}

template <typename T>
void Sort::MergeSort ( T A[], int p, int r ) {
	if ( p < r) {
		int q = floor( (p+r)/2 );
		MergeSort ( A, p, q );
		MergeSort ( A, q + 1, r );
		Merge ( A, p, q, r );
	}
}

template <typename T>
void Sort::InsertionSortAsc ( T array[] ) {
	for ( int j = 1; j < 6; j++ ) {
		int tmp = array[j];
		int i = j;
		while ( i>0 && array[i-1] > tmp ) {
			array[i] = array[i-1];
			i--;
		}
		array[i] = tmp;
	}
}

template <typename T>
void Sort::InsertionSortDesc ( T array[] ) {
	for (int j = 1; j < 6; j++) {
		int tmp = array[j];
		int i = j;
		while ( i>0 && array[i-1] < tmp ) {
			array[i] = array[i-1];
			i--;
		}
		array[i] = tmp;
	}
}

template <typename T>
void Sort::DisplayArray( T array[], int length ) {
	std::cout << " ###";
	for (int i=0; i<length; i++) {
		std::cout << " " << array[i];
	}
	std::cout << " ###" << std::endl;

}

#endif
