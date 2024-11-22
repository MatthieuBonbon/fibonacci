#ifndef FIBONACCI_H
#define FIBONACCI_H

#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include <time.h>

// Algorithme naïf permettant de calculer la suite de fibonacci
unsigned long fibonacci_naif();

// Algorithme récursif permettant de calculer la suite de fibonacci
unsigned long fibonacci_recursive_master();
void fibonacci_recursive(mpz_t result, unsigned long n);

// Algorithme permettant de calculer la suite de fibonacci grâce à l'exponentiation rapide (matrices)
unsigned long fibonacci_matrix_master();
void fibonacci_matrix(mpz_t result, unsigned long n);
void matrix_mult(mpz_t result[2][2], mpz_t A[2][2], mpz_t B[2][2]);
void matrix_pow(mpz_t result[2][2], mpz_t base[2][2], unsigned long n);


#endif //FIBONACCI_H
