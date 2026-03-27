#ifndef MESS_STACKER_VERSION_H
#define MESS_STACKER_VERSION_H

#include <stdint.h>

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

#endif // MESS_STACKER_VERSION_H