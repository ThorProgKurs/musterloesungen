#include <stdio.h>

int main() {

    int k,n;

    for (n=1; n<=15; n++) {  /* für alle n zwischen 1 und 15: */
        int sum = 0;         /* berechne die summe der ersten n ungeraden zahlen */
        for (k=0; k<n; k++) {
            sum += (2*k)+1;  /* addiere die k-te ungerade zahl */
        }
        printf("%i\n",sum);
    }

    return 0;
}
