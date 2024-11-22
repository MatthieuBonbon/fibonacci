#include "fibonacci.h"

int main() {

  unsigned long res_fibonacci_naif = fibonacci_naif();
  unsigned long res_fibonacci_rec = fibonacci_recursive_master();
  unsigned long res_fibonacci_matrix = fibonacci_matrix_master();

  printf("\n=== Nombre d'itérations par algorithme ===\n");
  printf("Algorithme naïf : %lu\n", res_fibonacci_naif);
  printf("Algorithme récursif : %lu\n", res_fibonacci_rec);
  printf("Algorithme avec exponentiation rapide (matrices) : %lu\n", res_fibonacci_matrix);
  printf("==========================================\n");


  return EXIT_SUCCESS;
}
