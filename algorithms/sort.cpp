#include "sort.h"

void quickSort (int *v, int left, int right) {
	int i = left, j = right;
	int tmp;
	int pivot = v[(left + right) / 2];

	while (i <= j) {
		while (v[i] < pivot && i <= j) {
			i++;
		}
		while (v[j] > pivot && i <= j) {
			j--;
		}
		if (i <= j) {
			tmp = v[i];
			v[i] = v[j];
			v[j] = tmp;
			i++;
			j--;
		}
	}

	if (left < j) {
		quickSort (v, left, j);
	} else if (i < right) {
		quickSort (v, i, right);
	}
}

inline void swap (int& x, int& y) {
	int tmp = x;
	x = y;
	y = tmp;
}

void selection_sort (int *v, int first, int last) {
	if (last == first) return;
	int least = first;

	for (int i = first; i <= last; i++) {
		if (v[least] >= v[i]) {
			least = i;
		}
	}

	swap (v[least], v[first]);

	return selection_sort(v, first + 1, last);
}

void selection_sort_it (int *v, int first, int last) {
	int least = first;

	while (first != last) {
		for (int i = first; i <= last; i++) {
			if (v[least] >= v[i]) {
				least = i;
			}
		}

		swap (v[least], v[first]);

		first++;
	}
}

void insertion_sort (int *v, int first, int last) {
// the first element is already a sorted sequence;
// it goes from the second element of the array until the last one
	for (int i = first + 1; i <= last; i++) {
// this is where the sorted sequence ends
		int j = i - 1;
// key is the element we want to insert into the sorted sequence
		int key = v[i];

// swapping positions until key is in the right place
		while (j >= first && v[j] > key) {
// it makes the key element "walk" through the sorted sequence
			swap (v[j + 1], v[j]);
			j--;
// it stops when j reaches -1 (the key element was the least) 
// or when the key is no longer larger than the previous element in the sorted sequence
		}

// now the key is the next element		
		key = v[i + 1];
	}
}

void bubble_sort (int *v, int first, int last) {
	for (int i = first; i <= last; i++) {
		for (int j = first; j <= last; j++) {
			if (v[j] > v[j + 1]) {
				swap (v[j], v[j + 1]);
			}
		}
	}
}
