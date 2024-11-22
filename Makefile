# Compilateur
CC := gcc
# Options de compilation
CFLAGS := -std=c99 -Wall -Wextra -Wunused-parameter -pedantic -ggdb
# Liens avec la bibliothèque GMP
LDFLAGS := -lgmp

# Dossiers de sortie
OBJ_DIR := obj
BIN_DIR := bin

# Créer les dossiers si nécessaire
$(shell mkdir -p $(OBJ_DIR) $(BIN_DIR))

# Cibles
all : $(BIN_DIR)/fibonacci

$(BIN_DIR)/fibonacci : $(OBJ_DIR)/fibonacci.o $(OBJ_DIR)/main.o
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

# Compilation des fichiers objets
$(OBJ_DIR)/%.o : %.c
	$(CC) -o $@ -c $< $(CFLAGS)

# Exécuter le programme
run : $(BIN_DIR)/fibonacci
	./$(BIN_DIR)/fibonacci

# Nettoyer les fichiers objets et l'exécutable
clean :
	rm -rf $(BIN_DIR) $(OBJ_DIR)

# Vérification mémoire avec Valgrind
memoire : $(BIN_DIR)/fibonacci
	valgrind --leak-check=full ./$(BIN_DIR)/fibonacci
