#include "roots_integrals.h"

typedef double afunc(double);

double abs_d(double x) {
	if (x < 0) {
		return -x;
	}
	return x;
}

double integral(afunc *f, double a, double b, double eps2) {
	int n = 2;
	double cap = f(a) + f(b), prevsum = 0, sum = f((a + b)/2), h = (b - a)/n;
	double I_n = 0, I_2n = h*(cap + 4*sum)/3;
	while (abs_d(I_n - I_2n)/15 >= eps2) {
		prevsum += sum;
		sum = 0;
		n *= 2;
		h /= 2;
		I_n = I_2n;
		for (int i = 1; i < n; i = i + 2) {
			sum += f(a + i*h);
		}
		I_2n = h*(cap + 4*sum + 2*prevsum)/3;
	}
	return I_2n;
}
