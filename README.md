# Fibonacci
Quelques algorithmes permettant de calculer la suite de Fibonacci.

# Pré-requis
## Dépendances
Librairie GMP (GNU Multiple Precision Arithmetic Library) permettant le calcul de nombres importants.

## Installation
1. Décompiler l'archive gmp-6.3.0.tar.xz
2. Se réferrer à la documentation https://gmplib.org/manual/Installing-GMP

# Exécution
- make / make all : compilation
- make run : compilation (si nécessaire) + exécution
- make clean : suppression des fichiers objets et de l'exécutable
- make memoire : exécution avec vérification des potentiels memory leak

# Résultats obtenus
- L'algorithme naïf est bien plus performant que les deux autres.
- L'algorithme utilisant les matrices a une meilleure complexité O(log(n)) que l'algorithme récursif simple ((1+√5)/2)^n.

1. Algorithme naïf (environ 420000 itérations)
2. Algorithme utilisant l'exponentiation rapide/les matrices (environ 15000 itérations)
3. Algorithme récursif (environ 30 itérations)

# Améliorations possibles
Une piste d'amélioration possible est l'utilisation de la programmation multi-coeurs. Nous pourrions par exemple utiliser des librairies comme OpenMP ou MPI afin d'accélerer les temps de calculs dans le but d'obtenir un indice plus élevé. Il faudrait cependant faire attention à l'utilisation des différents threads et aux dépendances entre les calculs. Par exemple, l'utilisation de la programmation parallèle sur l'algorithme récursif simple ne ferait qu'accroître le manque de performance de cet algorithme à cause des transmissions d'information nécessaires entre les différents threads.