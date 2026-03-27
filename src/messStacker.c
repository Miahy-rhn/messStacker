#include "messStacker.h"


const char* getMessStackerVersion(void) {
	return MESS_STACKER_VERSION;
}


/* Constante de taille de la pile de messages */
#define SIZE_STACK 30

/* Variables globales internes */
Message stackMess[SIZE_STACK];  /* File de messages circulaire */
int lastPos = -1;               /* Position du dernier message posté */
int curPos = 0;                 /* Position du message courant */
int messCount = 0;              /* Nombre de messages dans la pile */


/**
 * Vérifie s'il y a un message disponible dans la file
 * retourne true si au moins un message existe, false sinon
 */
bool haveMessage(void) {
	return messCount > 0;
}

/**
 * Calcule la somme de contrôle (checksum) pour un ensemble de données
 * Somme de cmd + somme de tous les octets de data
 * Chaque octet du tableau data est casté en uint8_t avant ajout
 */
uint8_t checksumMessage(uint8_t cmd, char *data, uint8_t size) {
	uint8_t checksum = cmd;  /* Initialiser avec la commande */
	
	/* Ajouter tous les octets du tableau data */
	for (uint8_t i = 0; i < size; i++) {
		checksum += (uint8_t)data[i];  /* Cast en uint8_t avant d'ajouter */
	}
	
	return checksum;
}

/**
 * Envoie un message dans la file circulaire
 * Vérifie que la file n'est pas pleine avant d'ajouter
 * Gère le wrap-around circulaire avec l'opérateur modulo
 */
bool sendMessage(uint8_t cmd, char *data, uint8_t size) {
	/* Vérifier que la file n'est pas pleine */
	if (messCount >= SIZE_STACK) {
		return false;
	}
	
	/* Calculer la position du nouveau message (circulaire) */
	int newPos = (lastPos + 1) % SIZE_STACK;
	
	/* Remplir la structure Message */
	stackMess[newPos].cmd = cmd;
	
	/* Copier les données */
	for (uint8_t i = 0; i < size; i++) {
		stackMess[newPos].data[i] = data[i];
	}
	
	stackMess[newPos].size = size;
	
	/* Calculer et stocker le checksum */
	stackMess[newPos].checksum = checksumMessage(cmd, data, size);
	
	/* Mettre à jour les variables internes */
	lastPos = newPos;
	messCount++;
	
	return true;
}