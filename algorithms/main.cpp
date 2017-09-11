#include <iostream>
#include "search.h"
#include "sort.h"

using namespace std;

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

	quick_sort (v, 0, n - 1);

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
