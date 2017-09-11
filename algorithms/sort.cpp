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
	int lowest = first;

	for (int i = first; i <= last; i++) {
		if (v[lowest] >= v[i]) {
			lowest = i;
		}
	}

	swap (v[lowest], v[first]);

	return selection_sort(v, first + 1, last);
}

void selection_sort_it (int *v, int first, int last) {
	int lowest = first;

	while (first != last) {
		for (int i = first; i <= last; i++) {
			if (v[lowest] >= v[i]) {
				lowest = i;
			}
		}

		swap (v[lowest], v[first]);

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
// it stops when j reaches -1 (the key element was the lowest) 
// or when the key is no longer larger than the previous element in the sorted sequence
		}

// now the key is the next element		
		key = v[i + 1];
	}
}

void bubble_sort (int *v, int first, int last) {
	for (int i = first; i <= last; i++) {
		for (int j = first; j <= last - i; j++) {
			if (v[j] >  v[j + 1]) {
				swap (v[j], v[j + 1]);
			}
		}
	}
}

void merge_sort (int *v, int first, int last) {
	int m = (first + last) / 2;

	if (first < last) {	
		merge_sort (v, first, m);
		merge_sort (v, m + 1, last);
		merge (v, first, last, m);
	}
}

void merge_doesntwork (int *v, int first, int last, int m) {
	int size1 = m - first + 1;
	int size2 = last - m;
	
	int *left = new int [size1];
	int *right = new int [size2];

	for (int i = 0; i < size1; i++) {
		left[i] = v[first + i];
	}	
	
	for (int i = 0; i < size2; i++) {
		right[i] = v[m + 1 + i];
	}

	int i = 0;
	int j = 0;
	int k = first;

	while (i <= m && j <= last && k <= last) {
		if (left[i] < right[j]) {
			v[k] = left[i];
			k++;
			i++;
		} else {
			v[k] = right[j];
			k++;
			j++;
		}
	}

	while (i <= m && k <= last) {
		v[k] = left[i];
		k++;
		i++;
	}

	while (j <= last & k <= last) {
		v[k] = right[j];
		k++;
		j++;
	}

	delete [] left;
	delete [] right;

	left = nullptr;
	right = nullptr;
}

void merge (int *v, int first, int last, int m) {
	int size = last - first;
	int* tmp = new int [size];

	int i = first;
	int j = m + 1;
	int k = first;

	while (i <= m && j <= last) {
		if (v[i] <= v[j]) {
			tmp[k] = v[i];
			k++;
			i++;
		} else {
			tmp[k] = v[j];
			k++;
			j++;
		}
	}
	
	while (i <= m) {
		tmp[k] = v[i];
		k++;
		i++;
	}

	while (j <= last) {
		tmp[k] = v[j];
		k++;
		j++;
	}

	for (k = first; k <= last; k++) {
		v[k] = tmp[k];
	}

	delete [] tmp;
	tmp = nullptr;
}

void quick_sort (int *v, int first, int last) {
	if (first < last) {
		int p = partition (v, first, last);

		quick_sort (v, first, p - 1);
		quick_sort (v, p + 1, last);
	}
}

int partition (int *v, int first, int last) {
	int pivot = v[last];

	int i = first;
	int j = last - 1;

	while (i <= j) {
		while (v[i] < pivot && i <= j) {
			i++;
		}

		while (v[j] > pivot && i <= j) {
			j--;
		}

		if (i <= j) {
			swap (v[i], v[j]);
		}
	}
	
	swap (v[i], v[last]);
	
	return i;
}
