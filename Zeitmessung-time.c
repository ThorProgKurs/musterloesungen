// Copyright © 2016 Martin Ueding <dev@martin-ueding.de>
// Licensed under The MIT License

/**
  Zeitmessung mit C-Standard Funktionen.

  Funktioniert mit jedem C-Compiler, ist aber ein klein wenig
  umständlich.

  gcc -Wall -Wpedantic Zeitmessung-time.c
  */

#include <stdio.h>
#include <time.h>

int main() {
    clock_t start = clock();
    // Die Anweisungen, die man messen möchte.
    clock_t end = clock();

    clock_t duration = end - start;
    double time = (double) duration / CLOCKS_PER_SEC;

    printf("Dauer: %g\n", time);
    printf("CLOCKS_PER_SEC: %lu\n", CLOCKS_PER_SEC);
}
