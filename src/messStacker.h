#ifndef MESS_STACKER_VERSION_H
#define MESS_STACKER_VERSION_H

#include <stdint.h>
#include <stdbool.h>

#define MESS_STACKER_VERSION "v0.0.01"
#define SIZE_MAX_DATA 57

const char* getMessStackerVersion(void);

/* Structure principale pour un message */
typedef struct Message{
	uint8_t cmd;                    /* Commande : entier non signé 8 bits */
	char data[SIZE_MAX_DATA];       /* Données : tableau d'octets */
	uint8_t size;                   /* Taille utile des données */
    uint8_t checksum;
} Message;

/* Déclarations des fonctions de gestion des messages */

/*
 * Envoie un message avec la commande, données et taille spécifiées
 * cmd Commande (uint8_t)
 * data Données (tableau de char)
 * size Taille des données (uint8_t)
 * retourne true si succès, false sinon
 */
bool sendMessage(uint8_t cmd, char *data, uint8_t size);

/*
 * Vérifie s'il y a un message disponible
 * retourne true si message disponible, false sinon
 */
bool haveMessage(void);

/*
 * Passe au message suivant
 * retourne true si succès, false sinon
 */
bool nextMessage(void);

/*
 * Retourne la commande du message courant
 * retourne La commande (uint8_t)
 */
uint8_t curMessageCmd(void);

/*
 * Retourne la taille du message courant
 * retourne La taille (uint8_t)
 */
uint8_t curMessageSize(void);

/*
 * Retourne la somme de contrôle du message courant
 * @return La checksum (uint8_t)
 */
uint8_t curMessageChecksum(void);

/**
 * Copie les données du message courant dans un buffer
 * buff Buffer destination (tableau de char)
 * lengthMax Taille maximale du buffer
 * @return true si succès, false sinon
 */
bool curMessageData(char *buff, uint8_t lengthMax);

/**
 * Calcule la somme de contrôle pour des données
 * cmd Commande (uint8_t)
 * data Données (tableau de char)
 * size Taille des données (uint8_t)
 * @return La checksum calculée (uint8_t)
 */
uint8_t checksumMessage(uint8_t cmd, char *data, uint8_t size);

#endif // MESS_STACKER_VERSION_H