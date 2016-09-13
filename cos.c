#include <stdio.h>

int main() {

    double pi = 3.14159265359;
    double x = 1.645;   /* Wir berechnen cos(x) */
    double sum = 0;     /* Die bisher berechnete Summe */
    double summand = 1; /* Der derzeitige Summand */
    unsigned long k;    /* Zählvariable */

    /* Da die angegebene Reihenentwicklung besonders genau in der
       Nähe von 0 ist und der Cosinus 2pi-Periodisch ist können
       wir solange 2Pi abziehen oder addieren, bis wir uns im
       Interval [-pi; pi] befinden */
    while(x<-pi) x += 2*pi;
    while(x>pi) x -= 2*pi;

    /* Der summand ist gleich dem ersten Reihenglied. Wir fangen
       daher bei k=2 an und erhöhen k in jedem Schritt um 2. Wir
       iterieren so lange, bis die Reihenglieder betragsmäßig
       kleiner als 1e-17 sind. */
    for (k=2; summand >= 1e-17 || summand <= -1e-17; k += 2) {
        /* Addiere den nächsten Summanden auf die Summe: */
        sum += summand;
        /* Berechne den nächsten Summanden aus dem bisherigen. */
        summand *= x * x * (-1);
        summand /= k;
        summand /= k - 1;
    }

    /* Der Cosinus ist (mit einer gewissen Genauigkeit) nun der
       Wert der bisher aufsummierten Reihenglieder. */
    printf("%f\n", sum);

    return 0;
}
