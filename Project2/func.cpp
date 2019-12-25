#include <iostream>
#include <ctime>
#include <cstdlib>
#include "func.h"
using namespace std;
void func(double** a, double** b, double* v, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			b[i][j] = a[i][j] * v[j];
		}
	}
}
void Print(double** a, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}