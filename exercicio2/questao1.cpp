#include <iostream>

using namespace std;

bool findSum_1 (int *v, int n, int x);

bool findSum_2 (int *v, int n, int x);

bool buscaBinaria (int *v, int inicio, int fim, int a);

int main () {
	int x;
	int n;

	cout << "Digite um inteiro: " << endl;
	cin >> x;

	cout << "Digite o tamanho do vetor: " << endl;
	cin >> n;

	int *v = new int [n];

	for (int i = 0; i < n; i++) {
		cout << "Digite o elemento " << i << " do vetor." << endl;
		cin >> v[i];
	}

	if (findSum_2 (v, n, x)) {
		cout << "Existem dois elementos no vetor cuja soma eh igual a x." << endl;
	} else {
		cout << "Nao existem dois elementos no vetor cuja soma eh igual a " << x << "." << endl;
	}

	delete [] v;
}

bool findSum_1 (int *v, int n, int x) {
	for (int i = 0; i < n; i++){
		for (int j = 0; j < i; j++) {
			if (v[i] + v[j] == x) {
				return true;
			}
		}
	}

	return false;
}

bool findSum_2 (int *v, int n, int x) {
	for (int i = 0; i < n; i++) {
		if (buscaBinaria(v, 0, n - 1, x - v[i])) {
			return true;
		}
	}
	return false;
}

bool buscaBinaria (int *v, int inicio, int fim, int a) {
	if (fim < inicio) {
		return false;
	} else {
		int k = (inicio + fim)/2;

		if (v[k] == a) {
			return true;
		} else if (v[k] > a) {
			return buscaBinaria (v, inicio, k - 1, a);
		} else if (v[k] < a) {
			return buscaBinaria (v, k + 1, fim, a);
		}
	}
}
