#include <stdio.h>

int main() {
    double sum = 0, last_sum = -1;
    int k = 1;
    
    while(sum - last_sum > 0.00001) {
        last_sum = sum;
        sum += 1. / (k * k);
        k++;
    }
    printf("%f\n", sum);
    
    return 0;
}
