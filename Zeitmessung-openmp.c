// Copyright © 2016 Martin Ueding <dev@martin-ueding.de>
// Licensed under The MIT License

/**
  Zeitmessung mit OpenMP.

  OpenMP ist ein Framework zum Nutzen aller Kerne in einem Computer. Braucht
  jedoch einen Compiler, der es unterstützt (z.B. GCC). Dies ist nicht
  Standard-C und sollte mit Vorsicht verwendet werden. Es braucht auch ein
  weiteres Compile-Flag.

  gcc -Wall -Wpedantic -fopenmp Zeitmessung-openmp.c
  */

#include <omp.h>

#include <stdio.h>

int main() {
    double start = omp_get_wtime();
    // Die Anweisungen, die man messen möchte.
    double end = omp_get_wtime();

    double duration = end - start;

    printf("Dauer: %g\n", duration);
}
