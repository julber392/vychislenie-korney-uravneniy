typedef double afunc(double);
double integral(afunc *f, double a, double b, double eps2);
double root(afunc *f, afunc *g, double a, double b, double eps1, int *iterations);
double abs_d(double x);
double f1(double x);
double f2(double x);
double f3(double x);
