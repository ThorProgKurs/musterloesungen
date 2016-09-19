#include "sort.h"

void sort(int *array, unsigned size) {
    unsigned i,j;
    int tmp;
    for (i=0; i<size; i++) {
        for (j=i+1;j<size;j++) {
            if (array[j]<array[i]) {
                tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
        }
    }
}