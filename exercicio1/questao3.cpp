#include <iostream>

using namespace std;

int digitSum (int n, int sum);

int main () {
	int n;
	int sum = 0;	

	cout << "Enter a natural number: " << endl;
	cin >> n;
	cout << digitSum (n, sum) << endl;
}

int digitSum (int n, int sum) {
	if (n == 0) {
		return sum;
	} else {
		sum += n % 10;
		return digitSum (n / 10, sum);
	}
}
