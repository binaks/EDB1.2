#include <iostream>

using namespace std;

void quickSort (int *v, int left, int right);

int leftBinarySearch (int *v, int first, int last, int x);

int rightBinarySearch (int *v, int first, int last, int x); 

inline void swap(int& x, int& y);

void selection_sort(int *v, int first, int last);

void selection_sort_it (int *v, int first, int last);

void insertion_sort (int *v, int first, int last);

int main () {
	int n;
	int k;
	int pos;
	int pos2;

	cout << "Enter the size of the array: " << endl;
	cin >> n;

	int *v = new int [n];

	for (int i = 0; i < n; i++) {
		cout << "Enter the element " << i << " of the array: " << endl;
		cin >> v[i];
	}

	insertion_sort (v, 0, n - 1);

	cout << "Here's your sorted array: " << endl;
	cout << "v = [";
	for (int i = 0; i < n; i++) {
		cout << v[i];
		if (i != (n - 1)) {
			cout << " ";
		}
	}
	cout << "]" << endl;

	cout << "Enter a number: " << endl;
	cin >> k;
	
	pos = leftBinarySearch (v, 0, n - 1, k);

	pos2 = rightBinarySearch (v, 0, n - 1, k);
	
	if (pos >= 0) {
		cout << k << " first appears in the position " << pos << " of your array." << endl;
		cout << k << " last appears in the position " << pos2 << " of your array." << endl;
		cout << k << " appears in your array " << (pos2 - pos + 1) << " times." << endl;
	} else {
		cout << k << " is not an element of your array." << endl;
	}
}

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

int leftBinarySearch (int *v, int first, int last, int x) {
if (last < first) {
return -1;
} else {
int k = (first + last) / 2;
if (v[k] == x) {
	if (k != 0 && v[k - 1] == x) {
		return leftBinarySearch (v, first, k - 1, x);
	} else {
		return k;
	}
} else if (v[k] > x) {
	return leftBinarySearch (v, first, k - 1, x);
} else {
	return leftBinarySearch (v, k + 1, last, x);
}
}
}

int rightBinarySearch (int *v, int first, int last, int x) {
if (last < first) {
return -1;
} else {
int k = (first + last) / 2;
if (v[k] == x) {
	if (k != last && v[k + 1] == x) {
		return rightBinarySearch (v, k + 1, last, x);
	} else {
		return k;
	}
} else if (v[k] > x) {
	return rightBinarySearch (v, first, k - 1, x);
} else {
	return rightBinarySearch (v, k + 1, last, x);
}
}
}

inline void swap (int& x, int& y)
{
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
