#ifndef DEF_SORT
#define DEF_SORT

#include <iostream>

class Sort {

	public:
		template <typename T>
		static void Merge ( T A[], int p, int q, int r );
		template <typename T>
		static void MergeSort ( T A[], int p, int r );
		template <typename T>
		static void InsertionSortAsc ( T array[], int length );
		template <typename T>
		static void InsertionSortDesc ( T array[], int length );
		template <typename T>
		static void HeapSort ( T array [], int heapSize );
		template <typename T>
		static void MaxHeapify ( T array [], int i, int heapSize );
		template <typename T>
		static void BuildMaxHeap ( T array [], int arrayLength );
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
		int q = (int) (p+r)/2;
		MergeSort ( A, p, q );
		MergeSort ( A, q + 1, r );
		Merge ( A, p, q, r );
	}
}

template <typename T>
void Sort::InsertionSortAsc ( T array[], int length ) {
	for ( int j = 1; j < length; j++ ) {
		int tmp = array[j];
		int i = j;
		while ( i > 0 && array[i-1] > tmp ) {
			array[i] = array[i-1];
			i--;
		}
		array[i] = tmp;
	}
}

template <typename T>
void Sort::InsertionSortDesc ( T array[], int length ) {
	for (int j = 1; j < length; j++) {
		int tmp = array[j];
		int i = j;
		while ( i > 0 && array[i-1] < tmp ) {
			array[i] = array[i-1];
			i--;
		}
		array[i] = tmp;
	}
}

template <typename T>
void Sort::HeapSort ( T array [], int arrayLength ) {

	int heapSize = arrayLength;
	BuildMaxHeap (array, arrayLength);

	for ( int i = arrayLength; i >= 1; i-- ) {
		int tmp		= array[0];
		array[0] 	= array[i];
		array[i] 	= tmp;
		heapSize--;
		MaxHeapify (array, 0, heapSize);
	}
}

template <typename T>
void Sort::MaxHeapify ( T array [], int i, int heapSize ) {
	int l(0);
	int r(0);
	int largest(0);

	l = 2*i+1;
	r = 2*i+2;

	if ( l <= heapSize && array[l] > array[i] ) {
		largest = l;
	} else {
		largest = i;
	}

	if ( r <= heapSize && array[r] > array[largest] ) {
		largest = r;
	}

	if ( largest != i ) {
		int tmp 		= array[i];
		array[i] 		= array[largest];
		array[largest] 	= tmp;
		MaxHeapify ( array, largest, heapSize );
	}
}

template <typename T>
void Sort::BuildMaxHeap ( T array [], int arrayLength ) {
	for (int i = arrayLength/2; i >= 0;i--){
		MaxHeapify (array, i, arrayLength);
	}
}

template <typename T>
void Sort::DisplayArray( T array[], int length ) {
	std::cout << " ###";
	for ( int i = 0; i < length; i++ ) {
		std::cout << " " << array[i];
	}
	std::cout << " ###" << std::endl;

}

#endif
