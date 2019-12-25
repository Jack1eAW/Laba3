#include "cube.h"

#include <iostream>
#include <cstdlib>
using namespace std;

void cube(double a, double b) {
	b = a * a * a;
}
/*
void cube1(const double a, const double b){
	b=a*a*a;
}
*/
void cube2(double* a, double* b) {
	*b = (*a) * (*a) * (*a);
}
/*
void cube3(const double* a,const double* b){
	*b=(*a)*(*a)*(*a);
}
*/
void cube4(double& a, double& b) {
	b = a * a * a;
}
/*
void cube5(const double& a, const double& b){
	b=a*a*a;
}
*/