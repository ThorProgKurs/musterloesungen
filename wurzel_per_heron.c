// Copyright © 2016 Martin Ueding <dev@martin-ueding.de>

/**
 Wurzelverfahren nach Heron.

 Meist auf dem zweiten Aufgabenzettel.
 */

/*
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.
 */

#include <math.h>
#include <stdio.h>

int main(int argc, char **argv) {
    // Anfangswert.
    double const a0 = 2;

    // Variablen für bisherigen und neuen Wert.
    double a_now = a0;
    double a_next;

    // Endlosschleife …
    while (1) {
        // Berechne den neuen Wert für $a$.
        a_next = 0.5 * (a_now + a0 / a_now);

        // Wenn der neue Wert sehr nah am alten Wert ist, brauchen wir nicht
        // mehr weiter zu rechnen. Die Schleife wird dann beendet.
        if (fabs((a_now - a_next) / a_now) < 1e-20) {
            break;
        }

        // Für den nächsten Durchlauf ist das neue $a$ das alte.
        a_now = a_next;

        // Gebe $a$ aus.
        printf("%.20lf\n", a_now);
    }


    return 0;
}
