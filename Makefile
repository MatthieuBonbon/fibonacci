# Compilateur
CC := gcc
# Options de compilation
CFLAGS := -std=c99 -Wall -Wextra -Wunused-parameter -pedantic -ggdb
# Liens avec la bibliothèque GMP
LDFLAGS := -lgmp

# Cibles
all : fibonacci

fibonacci : fibonacci.o main.o
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

# Compilation des fichiers objets
%.o : %.c
	$(CC) -o $@ -c $< $(CFLAGS)

# Exécuter le programme
run : fibonacci
	./fibonacci

# Nettoyer les fichiers objets et l'exécutable
clean :
	rm -f *.o fibonacci

# Vérification mémoire avec Valgrind
memoire : fibonacci
	valgrind --leak-check=full ./fibonacci
