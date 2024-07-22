#include "roots_integrals.h"

#define F(x) (f(x)-g(x))

typedef double afunc(double);

double root(afunc *f, afunc *g, double a, double b, double eps1, int *iterations) {
	int iters = 0;
	if (F(a) == 0) return a;
	if (F(b) == 0) return b;
	while (b - a >= eps1) {
		double c = (a + b)/2;
		if (F(a)*F(c) < 0) {
			b = c;
		} else if (F(b)*F(c) < 0) {
			a = c;
		} else {
			return c;
		}
		iters++;
	}
	if(iterations)
		*iterations = iters;
	return a;
}
