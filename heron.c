#include <stdio.h>

int main() {
    /* Dies ist die Zahl, aus der wir die Wurzel ziehen wollen. */
    double a = 7;

    /* Diese Variablen sind die letzten beiden Folgenglieder der Folge, die
       gegen die Wurzel aus a konvergiert. Zu beginn setzen wir x auf 2, damit
       die Schleife überhaupt beginnt (der Abstand von 2 und 1 ist größer als
       1e-10). */
    double x=2, y=1;

    /* Der Abstand von x und y ist genau dann kleiner als 1e-10, wenn entweder
       x-y oder y-x kleiner als 1e-10 ist. */
    while ( x-y >= 1e-10 || y-x >= 1e-10 ) {
        x = y;          /* x ist das letzte Folgenglied */
        y = (x+a/x)/2;  /* Berechne das nächste Folgenglied, damit ist */
    }                   /* x wieder das vorletzte Folgenglied. */

    /* Die Wurzel aus a (mit einer gewissen Genauigkeit) sollte nun in y
       gespeichert sein. Gebe y aus. */
    printf("%f\n",y);

    return 0;
}
