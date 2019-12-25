#include <iostream>

#include "cube.h"
using namespace std;


int main() {
	double a(0), b(0);
	cin >> a;
	cube2(&a, &b);
	cout << b << endl;
	return 0;
}