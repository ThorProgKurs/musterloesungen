#include <stdio.h>
#include <math.h>

double sqrt_to(double *p) { return *p=sqrt(*p); }

int solve_quadratic_equation(double a, double b, double c, double *x1, double *x2) {
    if (a) { /* in diesem Fall ist der Koeffizient von x^2 nicht 0 */
        double d;
        b /= a; c /= a;  /* Gleichung normieren */
        d = b*b/4.0 - c; /* Diskriminante ausrechnen */
        
        if (d<0) return 0;
        else if (d>0) {
            sqrt_to(&d);
            *x1 = -b/2 + d;
            *x2 = -b/2 - d;
            return 2;
        }
        else {
            *x1 = -b/2;
            return 1;
        }
        
    }
    else { /* in diesem Fall ist die Gleichung in Wirklichkeit nur linear */
        if (b) c /= b;
        
        if (c) {
            *x1 = -c;
            return 1;
        }
        else if (b) {
            *x1 = 0;
            return 1;
        }
        else {
            return 3;
        }
    }
}

int main() {
    int i, count;
    double x1, x2, val[5][3] = { {1,2,-8}, {0,3,0}, {0,3,-1}, {0,0,0}, {2,3,7}};
    for(i=0; i<5; i++) {
        printf("%f x^2 + %f x + %f = 0\n", val[i][0], val[i][1], val[i][2]);
        count = solve_quadratic_equation(val[i][0], val[i][1], val[i][2], &x1, &x2);
        if (count == 3) printf("Jede Zahl loest die Gleichung\n");
        else if (count == 2) printf("x_1 = %f, x_2 = %f\n", x1, x2);
        else if (count == 1) printf("x_1 = %f\n", x1);
        else printf("Die Gleichung hat keine reellen Loesungen\n");
        printf("\n");
    }
    return 0;
}
