#include <stdio.h>

int sgn(double x) {
    if (x<0) return -1;
    else if (x>0) return 1;
    else return 0;
}

double betrag(double x) {
    if (x>0) return x;
    else return -x;
}

double wurzel(double a) {
    double x, y=1;
    do {
        x = y;          /* x ist das letzte Folgenglied */
        y = (x+a/x)/2;  /* Berechne das nächste Folgenglied, damit ist */
    }                   /* x wieder das vorletzte */
    while ( x-y >= 1e-10 || y-x >= 1e-10 );
    return x;
}

int main() {
    printf("sgn(%f) = %i\n", 0., sgn(0.));
    printf("sgn(%f) = %i\n", -3., sgn(-3.));
    printf("sgn(%f) = %i\n", 4., sgn(4.));

    printf("betrag(%f) = %f\n", 0., betrag(0.));
    printf("betrag(%f) = %f\n", -3., betrag(-3.));
    printf("betrag(%f) = %f\n", 4., betrag(4.));

    printf("wurzel(%f) = %f\n", 0., wurzel(0.));
    printf("wurzel(%f) = %f\n", 3., wurzel(3.));
    printf("wurzel(%f) = %f\n", 4., wurzel(4.));

    return 0;
}
