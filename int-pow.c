#include <stdio.h>
#include <time.h>

#define PRECISION 1e-17

/* Funktion, welche die n-te Potenz einer Gleitkommazahl
   rekursiv mit der Square&Multiply-Methode berechnet. Wir
   merken an, dass n/2 für ungerades n das gleiche Ergebnis
   wie (n-1)/2 liefert aufgrund der Art und Weise, mit
   der Ganzzahlen dividiert werden (das Ergebnis wird immer
   abgerundet). */

double ipower_recursive(double x, unsigned n) {
    if (!n) {
        return 1;
    } else {
        if (n%2) {
            return x * ipower_recursive(x*x, n/2);
        } else {
            return ipower_recursive(x*x, n/2);
        }
    }
}

/* Diese Funktion implementiert die Potenzfunktion naiv,
   d.h. durch n-faches Multiplizieren einer Variablen mit
   dem Eingabewert. */
double ipower_naive(double x, unsigned n) {
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
double ipower_iterative(double x, unsigned n) {
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

int main() {
    double a = 0.9999999999;
    unsigned n = 2000000000;
    double timestamp, value;

    printf("Square&Multiply: ");
    timestamp = clock();
    value = ipower_recursive(a,n);
    timestamp = (clock()-timestamp)/CLOCKS_PER_SEC;
    printf("%f\n",value);
    printf("Took:            ");
    printf("%f\n",timestamp);

    printf("Iterativ Sq&Mul: ");
    timestamp = clock();
    value = ipower_iterative(a,n);
    timestamp = (clock()-timestamp)/CLOCKS_PER_SEC;
    printf("%f\n",value);
    printf("Took:            ");
    printf("%f\n",timestamp);

    timestamp = clock();
    printf("Naive Variante:  ");
    timestamp = clock();
    value = ipower_naive(a,n);
    timestamp = (clock()-timestamp)/CLOCKS_PER_SEC;
    printf("%f\n",value);
    printf("Took:            ");
    printf("%f\n",timestamp);

    return 0;
}
