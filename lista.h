// lista.h
#ifndef LISTA_H
#define LISTA_H

#include "attivita.h"

typedef struct Nodo {
    Attivita attivita;
    struct Nodo* next;
} Nodo;

Nodo* aggiungi_attivita(Nodo* head, Attivita a);
void stampa_attivita(Nodo* head);
void aggiorna_stato_attivita(Nodo* head);
void libera_lista(Nodo* head);

#endif
