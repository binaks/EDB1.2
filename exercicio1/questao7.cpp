#include <iostream>

using namespace std;
		
int findK (int *v, int n, int k);

int main () {
	int n;
	int k;

	cout << "Digite o tamanho do vetor: " << endl;
	cin >> n;

	cout << "Digite um inteiro: " << endl;
	cin >> k;

	int *v = new int[n];

	for (int i = 0; i < n; i++) {
		cout << "Digite o elemento " << i << " do vetor." << endl;
		cin >> v[i];
	}

	cout <<	k << " está na posição " << findK (v, n - 1, k) << " do vetor." << endl;

	delete[] v;
}

int findK (int *v, int n, int k) {
	if (v[n] == k) {
		return n;
	} else {
		return findK (v, --n, k);
	}
}
