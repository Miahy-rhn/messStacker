
# messStacker

**messStacker** est une application de gestion de pile permettant de manipuler des structures de données de type LIFO (Last In, First Out). Le projet offre des fonctionnalités essentielles pour empiler et dépiler des éléments, tout en fournissant une interface simple et intuitive pour les opérations courantes.

## Arborescence du projet

```
messStacker/
├── src/              # Code source de la librairie
│   ├── messStacker.h
│   └── messStacker.c
├── test/             # Programmes de test
│   └── test_version.c 
├── build/            # Fichiers compilés
├── makefile          # Fichier de configuration de compilation
└── README.md         
```

## API de la librairie

### Gestion de la file de messages

#### `bool haveMessage(void)`
Vérifie s'il existe un message dans la file de messages.

**Paramètres:** Aucun

**Retour:**
- `true` si un message est disponible dans la file
- `false` si la file est vide

**Description:** Cette fonction permet de savoir s'il y a au moins un message en attente de traitement dans la pile. Elle est généralement utilisée pour tester la présence de messages avant d'effectuer d'autres opérations comme la récupération de la commande ou des données.

---

#### `bool sendMessage(uint8_t cmd, char *data, uint8_t size)`
Envoie un message avec une commande et des données.

**Paramètres:**
- `cmd` : Commande associée au message (uint8_t, 0-255)
- `data` : Pointeur vers les données du message (tableau de char)
- `size` : Taille des données en octets (uint8_t, max 57)

**Retour:**
- `true` si le message a été envoyé avec succès
- `false` en cas d'erreur

---

#### `bool nextMessage(void)`
Passe au message suivant dans la file.

**Paramètres:** Aucun

**Retour:**
- `true` si un message suivant existe
- `false` si on atteint la fin de la file

---

#### `uint8_t curMessageCmd(void)`
Récupère la commande du message courant.

**Paramètres:** Aucun

**Retour:** La commande (uint8_t) du message courant

---

#### `uint8_t curMessageSize(void)`
Récupère la taille des données du message courant.

**Paramètres:** Aucun

**Retour:** La taille en octets (uint8_t) des données du message courant

---

#### `uint8_t curMessageChecksum(void)`
Récupère la somme de contrôle du message courant.

**Paramètres:** Aucun

**Retour:** La checksum (uint8_t) calculée pour le message courant

---

#### `bool curMessageData(char *buff, uint8_t lengthMax)`
Copie les données du message courant dans un buffer.

**Paramètres:**
- `buff` : Pointeur vers le buffer destination (tableau de char)
- `lengthMax` : Taille maximale du buffer

**Retour:**
- `true` si les données ont été copiées avec succès
- `false` en cas d'erreur

---

#### `uint8_t checksumMessage(uint8_t cmd, char *data, uint8_t size)`
Calcule la somme de contrôle pour un ensemble de données.

**Paramètres:**
- `cmd` : Commande (uint8_t)
- `data` : Pointeur vers les données (tableau de char)
- `size` : Taille des données en octets (uint8_t)

**Retour:** La checksum calculée (uint8_t)

---

#### `const char* getMessStackerVersion(void)`
Récupère le numéro de version de la librairie.

**Paramètres:** Aucun

**Retour:** Chaîne de caractères indiquant la version (ex: "v0.0.01")

## Constantes

- `SIZE_MAX_DATA` : Taille maximale des données pour un message (57 octets)
- `MESS_STACKER_VERSION` : Numéro de version actuelle de la librairie


### Dépot distant

- **url** : `https://github.com/username/messStacker.git`