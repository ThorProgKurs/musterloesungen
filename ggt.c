#include <stdio.h>

int main() {

    /* Dies sind die beiden Zahlen, deren ggT wir berechnen wollen. */
    unsigned int
        a = 120,
        b = 12;

    /* Nach dem folgenden if-else-Befehl soll der größte gemeinsame Teiler von
       a und b in a stehen. Sofern a gleich 0 ist, setzen wir also a auf b. */
    if (!a) a = b;
    /* Andernfalls führen wir den Algorithmus aus. */
    else {
        while (b) {
            if(a>b) a %= b;
            else    b %= a;
        }
    }

    printf("%i\n",a);
    return 0;
}
