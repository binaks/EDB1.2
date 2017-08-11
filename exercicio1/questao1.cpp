#include <iostream>

using namespace std;

string reverseString (string s, int size);

int main () {
	string s;

	cout << "Digite um texto: " << endl;
	getline (cin, s);

	int size = s.length();

	cout << reverseString (s, size) << endl; 
}

string reverseString (string s, int size) {
	if (size < 0) {
		return "";
	} else {
		return s[size] + reverseString (s, size - 1);
	}
}
