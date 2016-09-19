#include <stdio.h>

double power_recursive(double x, unsigned n) {
    if (!n) {
        return 1;
    } else {
        if (n%2) {
            return x * power_recursive(x*x, n/2); 
        } else {
            return power_recursive(x*x, n/2);
        }
    }
}

/* Diese Funktion implementiert die Potenzfunktion naiv,
   d.h. durch n-faches Multiplizieren einer Variablen mit
   dem Eingabewert. */
double power_naive(double x, unsigned n) {
    double r = 1.0;
    /* Zu Beginn der folgenden Schleife tuen wir nichts,
       sie läuft durch, solange n nicht gleich 0 ist und
       in jedem Schritt wird n um 1 verringert. Damit 
       hat die Schleife genau n Durchläufe. */
    for (; n; n--) r *= x;
    return r;
}


/* Dies ist die Implementierung der Square&Multiply-Methode
   als iterativer Algorithmus: */
double power_iterative(double x, unsigned n) {
    /* Der Wert r speichert die Vorfaktoren, die bei der rekursiven
       Variante entstehen, wenn n ungerade ist (siehe weiter unten) */
    double r = 1.0;

    /* Solange der Exponent nicht 1 ist, wollen wir ihn 
       weiter reduzieren: */
    while (n != 1) {
        if (n%2)     /* Im Falle n ungerade, */
            r *= x;  /* multipliziere den Vorfaktor mit x. */
        n /= 2;      /* Halbiere n. */
        x *= x;      /* Quadriere x. */
    }

    return r*x;
}

int main(int argc, char **argv) {
    printf("%f\n", power_recursive(0.9999999999, 2000000000));
    printf("%f\n", power_iterative(0.9999999999, 2000000000));
    printf("%f\n", power_naive(0.9999999999, 2000000000));
	return 0;
}

