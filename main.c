#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "roots_integrals.h"

double ftesting(double x){
	return 100*x+123;
}

int main(int argc, char *argv[]) {

	if(argc == 1){
		double S1, S2, r1, r2;
		r1 = root(f1, f3, 2.1, 3, 1e-12, NULL);
		r2 = root(f2, f3, 3, 5, 1e-12, NULL);
		S1 = integral(f3, r1, r2, 1e-12) - integral(f1, r1, r2, 1e-12);
		r1  = root(f1, f2, 4, 8, 1e-12, NULL);
		S2 = integral(f2, r2, r1, 1e-12) - integral(f1, r2, r1, 1e-12);
		printf("\n%.12f\n\n", S1 + S2);
		return 0;
	}
	
	if(strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0){
		printf("\n\nДоступные команды:\n\n\n"
			"        --root (или -r)           вывод абсцисс точек пересечения кривых c точностью 1е-12\n\n\n"
			"        --iterations (или -i)     вывод количества итераций, требуемого\n"
			"                                  для нахождения точек пересечения с точностью 1е-12\n\n\n"
			"        --test-root (или -R)      позволяет протестировать функцию root, необходимые\n"
			"                                  параметры F1:F2:A:B:E:R, где F1, F2 - номера\n"
			"                                  используемых функций, A, B - диапазон поиска корня,\n"
			"                                  E - точность вычислений, R - значение корня,\n"
			"                                  вычисленное аналитически\n\n\n"
			"        --test-integral (или -I)  позволяет протестировать функцию integral,\n"
			"                                  необходимые параметры F:A:B:E:R,\n"
			"                                  аналогичные параметрам команды -R\n\n\n");
		return 0;
	}
	
	if(strcmp(argv[1], "-i") == 0 || strcmp(argv[1], "--iterations") == 0){
		int iterations;
		
		root(f1, f2, 4, 8, 1e-12, &iterations);
		printf("\nПотребовалось итераций для вычисления точки пересечения...\n\n"
			"    ln(x) и -2x+14:          %d      (исследуемый диапазон: 4, 8)\n\n", iterations);
		root(f1, f3, 2.1, 3, 1e-12, &iterations);
		printf("    ln(x) и 1/(2-x)+6:      %d      (исследуемый диапазон: 2.1, 3)\n\n", iterations);
		
		root(f2, f3, 3, 5, 1e-12, &iterations);
		printf("    -2x+14 и 1/(2-x)+6:     %d      (исследуемый диапазон: 3, 5)\n\n", iterations);
		
		return 0;
	}
	
	if(strcmp(argv[1], "-r") == 0 || strcmp(argv[1], "--root") == 0){
		double x;
		
		x = root(f1, f2, 4, 8, 1e-12, NULL);
		printf("\nАбсциссы точек пересечения...\n\n"
			"    ln(x) и -2x+14:          %.12f      (исследуемый диапазон: 4, 8)\n\n", x);
		x = root(f1, f3, 2.1, 3, 1e-12, NULL);
		printf("    ln(x) и 1/(2-x)+6:      %.12f      (исследуемый диапазон: 2.1, 3)\n\n", x);
		
		x = root(f2, f3, 3, 5, 1e-12, NULL);
		printf("    -2x+14 и 1/(2-x)+6:     %.12f      (исследуемый диапазон: 3, 5)\n\n", x);
		
		return 0;
	}
	
	if(argc == 2){
		return 0;
	}
	
	if(strcmp(argv[1], "-R") == 0 || strcmp(argv[1], "--test-root") == 0){
		double (*funcs[])(double) = {f1, f2, f3, ftesting};
		char* ptrEnd;
		int fnum1 = strtod(argv[2], &ptrEnd) - 1;
		int fnum2 = strtod(ptrEnd+1, &ptrEnd) - 1;
		double A = strtod(ptrEnd+1, &ptrEnd);
		double B = strtod(ptrEnd+1, &ptrEnd);
		double eps = strtod(ptrEnd+1, &ptrEnd);
		double R = strtod(ptrEnd+1, &ptrEnd);
		double x = root(funcs[fnum1], funcs[fnum2], A, B, eps, NULL);
		double abserr = abs_d(x - R);
		double relerr = abserr/R;
		printf("\n%f    %f    %f\n\n", x, abserr, relerr);
		return 0;
	}
	
	if(strcmp(argv[1], "-I") == 0 || strcmp(argv[1], "--test-integral") == 0){
		double (*funcs[])(double) = {f1, f2, f3};
		char* ptrEnd;
		int fnum = strtod(argv[2], &ptrEnd) - 1;
		double A = strtod(ptrEnd+1, &ptrEnd);
		double B = strtod(ptrEnd+1, &ptrEnd);
		double eps = strtod(ptrEnd+1, &ptrEnd);
		double R = strtod(ptrEnd+1, &ptrEnd);
		double ival = integral(funcs[fnum], A, B, eps);
		double abserr = abs_d(ival - R);
		double relerr = abserr/R;
		printf("\n%f    %f    %f\n\n", ival, abserr, relerr);
		return 0;
	}
}

