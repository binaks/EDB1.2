#include <iostream>

using namespace std;

int findMin (int *v, int n, int min); 
		
int main () {
	int n;

	cout << "Digite o tamanho do vetor: " << endl;
	cin >> n;

	int *v = new int[n];

	for (int i = 0; i < n; i++) {
		cout << "Digite o elemento " << i << " do vetor." << endl;
		cin >> v[i];
	}
	
	cout << "O menor elemento do vetor é o " << findMin (v, n - 1, v[n - 1]) << "." << endl;

	delete[] v;
}

int findMin (int *v, int n, int min) {
	if (n == 0) {
		return min;
	} else {
		if (v[n] < min) {
			min = v[n];
		}
		return findMin (v, --n, min);
	}
}
