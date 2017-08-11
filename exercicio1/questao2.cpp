#include <iostream>

using namespace std;

string toBinary (int n, string binary);

int main () {
	int n;
	string binary = "";

	cout << "Enter a natural number: " << endl;
	cin >> n;

	cout << toBinary (n, binary) << endl;
}

string toBinary (int n, string binary) {
	if (n == 0) {
		return binary;
	} else {
		if (n % 2 == 0) {
			binary += "0";
		} else {
			binary += "1";
		}
		return toBinary (n / 2, binary);
	}
}
