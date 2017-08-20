#include <iostream>

using namespace std;

void quickSort (int *v, int left, int right); 

int ternarySearch (int *v, int k, int inicio, int fim);
 
int iTernarySearch (int *v, int k, int inicio, int fim); 

int main () {
	int n;
	int k;
	int pos;

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
		cout << v[i];
		if (i != (n - 1)) {
			cout << " ";
		}
	}
	cout << "]" << endl;

	cout << "Enter a number: " << endl;
	cin >> k;

	pos = iTernarySearch (v, k, 0, n - 1);

	if (pos < 0) {
		cout << k << " is not an element of your array." << endl;
	} else {
		cout << k << " is in the position " << pos << " of your array." << endl;
	}

	delete [] v;
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

int ternarySearch (int *v, int k, int inicio, int fim) {
	if (fim < inicio) {
		return -1;
	} else {
		int mid = (inicio + fim) / 2;
		int m1 = (inicio + mid) / 2;
		int m2 = (mid + fim) / 2;

		if (v[m1] == k) {
			return m1;
		} else if (v[m2] == k) {
			return m2;
		} else if (k < v[m1]) {
			return ternarySearch (v, k, inicio, m1 - 1);
		} else if (k > v[m2]) {
			return ternarySearch (v, k, m2 + 1, fim);
		} else {
			return ternarySearch (v, k, m1 + 1, m2 - 1);
		}
	}
}

int iTernarySearch (int *v, int k, int inicio, int fim) {
	while (inicio <= fim) {
		int mid = (inicio + fim) / 2;
		int m1 = (inicio + mid) / 2;
		int m2 = (mid + fim) / 2;

		if (v[m1] == k) {
			return m1;
		} else if (v[m2] == k) {
			return m2;
		} else if (k < v[m1]) {
			fim = m1 - 1;
		} else if (k > v[m2]) {
			inicio = m2 + 1;
		} else {
			inicio = m2 - 1;
			fim = m1 + 1;
		}
	}

	return -1;
}
