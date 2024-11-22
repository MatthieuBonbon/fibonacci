#include "fibonacci.h"

unsigned long fibonacci_naif(){
    // Init variables
    mpz_t a, b, result;
    mpz_init_set_ui(a, 0); // a = 0
    mpz_init_set_ui(b, 1); // b = 1
    mpz_init(result);
    unsigned long cpt = 0;

    // Start timer
    clock_t start_time = clock();


    // Algo
    while ((clock() - start_time) < CLOCKS_PER_SEC) {
        mpz_add(result, a, b);
        mpz_set(a, b);
        mpz_set(b, result);
        cpt++;
    }

    // Print res
    gmp_printf("Last value : %Zd\n", result);
    printf("Nb iterations : %lu\n", cpt);

    // Memory clear
    mpz_clear(a);
    mpz_clear(b);
    mpz_clear(result);

    return cpt;
}


unsigned long fibonacci_recursive_master(){
    // Init variables
    unsigned long cpt = 0;
    mpz_t result;
    mpz_init(result);

    // Start timer
    clock_t start_time = clock();

    // Recursive Algo
    while ((clock() - start_time) < CLOCKS_PER_SEC) {
        fibonacci_recursive(result, cpt);
        cpt++;
    }

    // Print res
    gmp_printf("Last value : %Zd\n", result);
    printf("Nb iterations : %lu\n", cpt);

    // Memory clear
    mpz_clear(result);

    return cpt;
}

void fibonacci_recursive(mpz_t result, unsigned long n) {
    if (n == 0) {
        mpz_set_ui(result, 0);
    }
    else if (n == 1) {
        mpz_set_ui(result, 1);
    }
    else {
        // Init previous variables
        mpz_t prev1, prev2;
        mpz_init(prev1);
        mpz_init(prev2);

        // Recursion
        fibonacci_recursive(prev1, n - 1);
        fibonacci_recursive(prev2, n - 2);

        mpz_add(result, prev1, prev2);

        // Memory clear
        mpz_clear(prev1);
        mpz_clear(prev2);
    }
}


unsigned long fibonacci_matrix_master(){
    // Init variables
    unsigned long cpt = 0;
    mpz_t result;
    mpz_init(result);

    // Start timer
    clock_t start_time = clock();

    // Recursive Algo
    while ((clock() - start_time) < CLOCKS_PER_SEC) {
        fibonacci_matrix(result, cpt);
        cpt++;
    }

    // Print res
    gmp_printf("Last value : %Zd\n", result);
    printf("Nb iterations : %lu\n", cpt);

    // Memory clear
    mpz_clear(result);

    return cpt;
}

void fibonacci_matrix(mpz_t result, unsigned long n) {
    if (n == 0) {
        mpz_set_ui(result, 0);
    }
    else if (n == 1) {
        mpz_set_ui(result, 1);
    }
    else {
        // Init base matrix
        mpz_t base_matrix[2][2];
        mpz_init_set_ui(base_matrix[0][0], 1);
        mpz_init_set_ui(base_matrix[0][1], 1);
        mpz_init_set_ui(base_matrix[1][0], 1);
        mpz_init_set_ui(base_matrix[1][1], 0);

        // Init result matrix
        mpz_t result_matrix[2][2];
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                mpz_init(result_matrix[i][j]);
            }
        }

        // Exponentiation rapide
        matrix_pow(result_matrix, base_matrix, n - 1);

        // Get result
        mpz_set(result, result_matrix[0][0]);

        // Memory clear
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                mpz_clear(base_matrix[i][j]);
                mpz_clear(result_matrix[i][j]);
            }
        }
    }
}

void matrix_mult(mpz_t result[2][2], mpz_t A[2][2], mpz_t B[2][2]) {
    //Init variables
    mpz_t temp[2][2];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            mpz_init(temp[i][j]);
        }
    }
    
    // mult
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            mpz_set_ui(temp[i][j], 0);
            for (int k = 0; k < 2; k++) {
                mpz_addmul(temp[i][j], A[i][k], B[k][j]);
            }
        }
    }

    // Set result
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            mpz_set(result[i][j], temp[i][j]);
        }
    }
    
    // Memory clear
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            mpz_clear(temp[i][j]);
        }
    }
}

void matrix_pow(mpz_t result[2][2], mpz_t base[2][2], unsigned long n) {
    // Init identity matrix
    mpz_t identity[2][2];
    mpz_init_set_ui(identity[0][0], 1);
    mpz_init_set_ui(identity[0][1], 0);
    mpz_init_set_ui(identity[1][0], 0);
    mpz_init_set_ui(identity[1][1], 1);

    // Set result with identity
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            mpz_set(result[i][j], identity[i][j]);
        }
    }

    // Init temp matrix
    mpz_t temp[2][2];
    mpz_init(temp[0][0]);
    mpz_init(temp[0][1]);
    mpz_init(temp[1][0]);
    mpz_init(temp[1][1]);

    // Exponentiation rapide (cf. https://fr.wikipedia.org/wiki/Exponentiation_rapide)
    while (n > 0) {
        if (n % 2 == 1) {
            matrix_mult(temp, result, base);
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    mpz_set(result[i][j], temp[i][j]);
                }
            }
        }
        matrix_mult(temp, base, base);
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                mpz_set(base[i][j], temp[i][j]);
            }
        }
        n /= 2;
    }

    // Memory clear
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            mpz_clear(temp[i][j]);
            mpz_clear(identity[i][j]);
        }
    }
}