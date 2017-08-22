#include <iostream>

using namespace std;

bool isBitonic (int *v, int n);

bool isCrescent (int *v, int n); 

int findPeak (int *v, int first, int last);

int main () {
	int n;

	cout << "Enter the size of your array: " << endl;

	cin >> n;

	int *v = new int [n];

	for (int i = 0; i < n; i++) {
		cout << "Enter the element " << i << " of your array: " << endl;
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

	if (isBitonic(v, n - 1)) {
		cout << "Your array is bitonic! :)" << endl;
		cout << "Here's its peak: " << findPeak (v, 0, n - 1) << "." << endl;
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
		
		if (v[k] > v[k + 1] && v[k] > v[k - 1]) {
			return v[k];
		} else if (v[k] > v[k + 1] && v[k] < v[k - 1]) {
			return findPeak (v, first, v[k - 1]);
		} else if (v[k] < v[k + 1] && v[k] > v[k - 1]) {
			return findPeak (v, v [k - 1], last);
		}
}
