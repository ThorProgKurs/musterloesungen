// Copyright © 2016 Martin Ueding <dev@martin-ueding.de>

/**
 Wurzelverfahren nach Heron.

 Meist auf dem zweiten Aufgabenzettel.

 Beim Kompilieren muss manchmal die Option `-lm` am Ende gegeben werden.
 Ansonsten kann es zu Fehlermeldungen wie `undefined reference to fabs` kommen.
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
    // Anfangswert. Ich habe ihn hier als konstant gewählt, damit ich diesen
    // Wert nicht später im Programm ändern kann. Dabei ist es egal, ob man
    // `double const` oder `const double` schreibt. Das ist ein kleiner
    // Glaubenskrieg. In den Übungen habe ich manchmal gesehen, wie das
    // ursprüngliche $a$, das man in der Formel braucht, mit einem neuen $a_n$
    // überschrieben wird. Daher ist hier das `const` eine gute Hilfe.
    double const a0 = 2;

    // Diese Toleranz ist der Unterschied, den aufeinanderfolgende Elemente der
    // Reihe maximal haben dürfen, damit ich das Endergebnis als genau
    // einschätze. Man kann es auch unten direkt in das `if` schreiben, jedoch
    // mag ich es nicht, wenn Zahlen keinen Namen haben.
    double const tolerance = 1e-20;

    // Variablen für bisherigen und neuen Wert. `a_next` muss hier nicht
    // initialisiert werden, weil es vor dem ersten Auslesen mit einem neuen
    // Wert überschrieben wird.
    double a_now = a0;
    double a_next;

    // Endlosschleife …
    while (1) {
        // Berechne den neuen Wert für $a$.
        a_next = 0.5 * (a_now + a0 / a_now);

        // Gebe $a$ mit 20 Nachkommastellen aus. Das Format `g` anstelle von
        // `f` schreibt die Zahl, wenn nötig, auch mit der »e plus/minus«
        // Schreibweise, also dem »10 hoch«.
        printf("%.20lg\n", a_next);

        // Wenn der neue Wert sehr nah am alten Wert ist, brauchen wir nicht
        // mehr weiter zu rechnen. Die Schleife wird dann beendet. Die Funktion
        // `fabs` ist die »Floating point ABSolute value«, also der normale
        // »Betrag« für Kommazahlen. In C gibt es noch die Funktion `abs`, die
        // ist allerdings nur für `int` und `long` gedacht. Nutzt man hier
        // `abs`, so wird immer abgerundet und man hat die Toleranz viel zu
        // schnell unterschritten.
        //
        // Der Vorteil gegenüber einer festen Anzahl an Iterationen ist hier,
        // dass nur so lange gerechnet wird, bis die gewünschte Genauigkeit
        // erreicht ist. Man hat am Ende auch eine große Idee, wie genau das
        // Ergebnis ist. Bei einer festen Anzahl hat man keine Idee, wie genau
        // das Ergebnis ist.
        //
        // Ich teile hier noch durch `a_next`, damit ich das Verhältnis der
        // Änderung habe. Ansonsten würde man die Genauigkeit auf einen
        // bestimmten festen Wert legen. Wenn man die Wurzel aus `1e-50` ziehen
        // möchte, was `1e-25` ist, so wäre man mit einer festen Schranke von
        // `1e-20` nicht gut bedient. Durch die Quotientenbildung habe ich also
        // immer 20 signifikante Stellen, egal wie groß das $a$ gewählt worden
        // ist.
        if (fabs((a_now - a_next) / a_next) < tolerance) {
            break;
        }

        // Für den nächsten Durchlauf ist das neue $a$ das alte.
        a_now = a_next;
    }

    return 0;
}
