#ifndef DEF_MERGESORT
#define DEF_MERGESORT

#include <iostream>
#include <math.h>

class MergeSort {

	public:
		template <typename T>
		static void Merge (T A[], int p, int q, int r);
		template <typename T>
		static void DoMergeSort ( T A[], int p, int r );
		template <typename T>
		static void DisplayArray ( T A[], int length );
};


template <typename T>
void MergeSort::Merge ( T A[], int p, int q, int r ) {
	int n1 = q - p + 1;
	int n2 = r - q;

	T L[n1];
	T R[n2];

	for (int i = 0; i < n1; i++) {
		L[i] = A[p+i];
	}

	for (int j = 0; j < n2; j++) {
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
void MergeSort::DoMergeSort ( T A[], int p, int r ) {
	if ( p < r) {
		int q = floor((p+r)/2);
		DoMergeSort (A, p, q);
		DoMergeSort (A, q + 1, r);
		Merge (A, p, q, r);
	}
}

template <typename T>
void MergeSort::DisplayArray( T array[], int length ) {
	for (int i=0; i<length; i++)
		std::cout << " " << array[i];
}

#endif
