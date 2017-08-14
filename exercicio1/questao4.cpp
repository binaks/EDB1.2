#include <iostream>

using namespace std;

int fib (int n);
int t_fib (int a, int b, int res);
int r_fib (int n);

int main () {
	int a;

	cout << "Enter a natural number: " << endl;
	cin >> a;
	cout << t_fib (a, 1, 1) << endl;
}

int fib (int n) {
	int a = 1, b = 0, res = 0;
	
	for (int i = 1; i <= n; ++i) {
		res = a + b;
		b = a;
		a = res;
	}
	
	return res;
}

int t_fib (int a, int b, int res) {
	if (a <= 1) {
		return a;
	} else if (a == 2){
		return res;
	} else { 
		return t_fib (a - 1, res, b + res);
	}
}

int r_fib (int n) {
	if (n == 0) {
		return 0;
	} else if (n == 1) {
		return 1;
	} else {
		return fib (n - 1) + fib (n - 2);
	} 
}
