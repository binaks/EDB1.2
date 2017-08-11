#include <iostream>

using namespace std;

string reverseString (string s, string reversed, int size);

int main () {
	string s;
	string reversed = "";

	cout << "Digite um texto: " << endl;
	getline (cin, s);

	int size = s.length();

	cout << reverseString (s, reversed, size) << endl; 
}

string reverseString (string s, string reversed, int size) {
	if (size < 0) {
		return reversed;
	} else {
		reversed += s[size];
		return reverseString (s, reversed, size - 1);
	}
}
