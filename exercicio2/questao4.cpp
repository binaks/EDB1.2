#include <iostream>

using namespace std;

bool isBitonic (int *v, int n);

bool isCrescent (int *v, int n); 

int findPeak (int *v, int first, int last);

int bitonicBinarySearch (int *v, int first, int last, int x, int peak); 

int rightBinarySearch (int *v, int first, int last, int x);

int leftBinarySearch (int *v, int first, int last, int x);

int main () {
	int n;
	bool bitonic;
	int peak;
	int x;
	int pos;

	cout << "Enter the size of your array: " << endl;

	cin >> n;

	int *v = new int [n];

	for (int i = 0; i < n; i++) {
		cout << "Enter the element in the position " << i << " of your array: " << endl;
		cin >> v[i];
	}

	cout << "Here's your array: " << endl;

	cout << "v = [";
	for (int i = 0; i < n; i++) {
		cout << v[i];
		if (i != (n - 1)) {
			cout << " ";
		}
	}
	cout << "]" << endl;

	bitonic = isBitonic (v, n - 1);

	if (bitonic) {
		cout << "Your array is bitonic! :)" << endl;
		peak = findPeak (v, 0, n - 1);
		cout << "Its peak is in the position " << peak << "." << endl;

		cout << "Enter a number you want to search in your array: " << endl;
		cin >> x;
		
		pos = bitonicBinarySearch (v, 0, n - 1, x, peak);

		if (pos >= 0) {
			cout << x << " is in the position " << pos << " of your array." << endl;
		} else {
			cout << x << " is not an element of your array." << endl;
		}
	} else {
		cout << "Your array is *not* bitonic :(" << endl;
	}

	delete [] v;
}

bool isBitonic (int *v, int n) {
	if (n <= 0) {
		return true;
	} else {
		if (v[n] < v[n - 1]) {
			return isBitonic (v, n - 1);
		} else { 
			return isCrescent (v, n);
		}
	}
}

bool isCrescent (int *v, int n) {
	if (n == 0) {
		return true;
	} else if (v[n] < v [n - 1]) {
		return false;
	} else { 
		return isCrescent (v, n - 1);
	}
}

int findPeak (int *v, int first, int last) {
	int k = (first + last) / 2;

	if (first == last) {
		return first;
	} else if (v[k] > v[k + 1] && v[k] > v[k - 1]) {
		return k;
	} else if (v[k] > v[k + 1] && v[k] < v[k - 1]) {
		return findPeak (v, first, k - 1);
	} else if (v[k] < v[k + 1] && v[k] > v[k - 1]) {
		return findPeak (v, k + 1, last);
	}
}

int bitonicBinarySearch (int *v, int first, int last, int x, int peak) {
	if (first > last) {
		return -1;
	} else if (x == v[peak]) {
		return peak;
	} else {
		int search = leftBinarySearch (v, first, peak - 1, x);
		if (search >= 0) {
			return search;
		} else {
			return rightBinarySearch (v, peak + 1, last, x);
		}
	}
}

int leftBinarySearch (int *v, int first, int last, int x) {
	if (first > last) {
		return -1;
	} else {
		int k = (first + last) / 2;

		if (v[k] == x) {
			return k;
		} else if (v[k] > x) {
			return leftBinarySearch (v, first, k - 1, x);
		} else {
			return leftBinarySearch (v, k + 1, last, x);
		}
	}
}

int rightBinarySearch (int *v, int first, int last, int x) {
	if (first > last) {
		return -1;
	} else {
		int k = (first + last) / 2;

		if (v[k] == x) {
			return k;
		} else if (v[k] < x) {
			return rightBinarySearch (v, first, k - 1, x);
		} else {
			return rightBinarySearch (v, k + 1, last, x);
		}
	}
} 
