# Variables
SRC = ./src
BUILD = ./build
TEST = ./test

CC = gcc
CFLAGS = -Wall -g -I$(SRC)

# Cible par défaut
all: $(BUILD)/test_version

# Création des dossiers si nécessaire
$(BUILD):
	@mkdir -p $(BUILD)

# Compilation de messStacker.o
$(BUILD)/messStacker.o: $(SRC)/messStacker.c $(SRC)/messStacker.h | $(BUILD)
	$(CC) $(CFLAGS) -c $< -o $@

# Compilation de test_version.o
$(BUILD)/test_version.o: $(TEST)/test_version.c | $(BUILD)
	$(CC) $(CFLAGS) -c $< -o $@

# Édition de lien finale
$(BUILD)/test_version: $(BUILD)/test_version.o $(BUILD)/messStacker.o
	$(CC) $(CFLAGS) $^ -o $@

# Cible de nettoyage
clean:
	rm -f $(BUILD)/*.o $(BUILD)/test_version

.PHONY: all clean


run :$(BUILD)/test_version
	@$(BUILD)/test_version