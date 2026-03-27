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

