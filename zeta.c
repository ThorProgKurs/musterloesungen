#include <float.h>
#include <stdio.h>
#include <math.h>

double zeta(double s) {
    if (s <= 1) {
        double t = 2, s = 4;
        while (s != t) {
            s *= 2;
            t *= 2;
        }
        return s;
    } else {
        double sum = 1.0, summand = 1.0;
		unsigned k;
        for (k = 2; summand >= 1e-10; k++) {
			summand = 1.0/pow(k, s);
			sum += summand;
		}
        return sum;
    }
}

int main() {
    printf("%f\n", zeta(4));
    printf("%f\n", zeta(3));
    printf("%f\n", zeta(2.5));
    printf("%f\n", zeta(2));
    printf("%f\n", zeta(1.8));
    printf("%f\n", zeta(1.5)); 
    return 0;
}