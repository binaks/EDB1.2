#include <iostream>

using namespace std;

void quickSort (int *v, int left, int right);

int leftBinarySearch (int *v, int first, int last, int x);

int rightBinarySearch (int *v, int first, int last, int x); 

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

	quickSort (v, 0, n - 1);

	cout << "Here's your sorted array: " << endl;
	cout << "v = [";
	for (int i = 0; i < n; i++) {
		if (i != (n - 1)) {
			cout << v[i] << " ";
		}
	}
	cout << "]" << endl;

	cout << "Enter a number: " << endl;
	cin >> k;
	
	pos = leftBinarySearch (v, 0, n - 1, k);

	pos2 = rightBinarySearch (v, 0, n - 1, k);
	
	if (pos >= 0) {
		cout << k << " first appears in the position " << pos  << " of your array." << endl;
		cout << k << " appears in your array " << (pos2 - pos) << " times." << endl;
	} else {
		cout << k << " is not an element of your array." << endl;
	}
}

void quickSort (int *v, int left, int right) {
	int i = left, j = right;
	int tmp;
	int pivot = v[(left + right) / 2];

	while (i <= j) {
		while (v[i] < pivot) {
			i++;
		}
		while (v[j] > pivot) {
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
			if (k != 0 || v[k - 1] == x) {
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
			if (k != 0 || v[k + 1] == x) {
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
