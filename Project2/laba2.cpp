#include <iostream>
#include <ctime>
#include <cstdlib>
#include "func.h"
using namespace std;

int main() {
	srand(time(0));
	int n;
	cin >> n;
	cout << endl;
	double** a = new double* [n], ** b = new double* [n], * c = new double[n];
	for (int i = 0; i < n; i++) {
		a[i] = new double[n];
		b[i] = new double[n];
	}
	for (int i = 0; i < n; i++) {
		c[i] = 1 + rand() / (double)RAND_MAX * 4;
		cout << c[i] << endl;
		for (int j = 0; j < n; j++) {
			a[i][j] = 1 + rand() / (double)RAND_MAX * 4;
		}
	}
	cout << endl;
	Print(a, n);
	cout << endl;
	func(a, b, c, n);
	Print(b, n);
	return 0;
}