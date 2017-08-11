#include <iostream>

using namespace std;

void toBinary (int n);

int main () {
	int n;

	cout << "Enter a natural number: " << endl;
	cin >> n;

	toBinary (n);
	cout << endl;
}

void toBinary (int n) {
	if (n != 0) {
		toBinary (n / 2);

		if (n % 2 == 0) {
			cout << "0";
		} else {
			cout << "1";
		}

	}
}
