#include <iostream>

using namespace std;
		
int sumArray (int *v, int n, int sum);

int main () {
	int n;

	cout << "Digite o tamanho do vetor: " << endl;
	cin >> n;

	int *v = new int[n];

	for (int i = 0; i < n; i++) {
		cout << "Digite o elemento " << i << " do vetor." << endl;
		cin >> v[i];
	}
	
	cout << "A soma dos elementos do vetor é " << sumArray (v, n - 1, 0) << "." << endl;

	delete[] v;
}

int sumArray (int *v, int n, int sum) {
	if (n == 0) {
		return sum;
	} else {
		sum += v[n];
		return sumArray (v, --n, sum);
	}
}
