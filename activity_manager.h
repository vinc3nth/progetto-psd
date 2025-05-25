#ifndef ACTIVITY_MANAGER_H
#define ACTIVITY_MANAGER_H

#define MAX_DESC 100
#define MAX_CORSO 50
#define MAX_DATA 11

// Enumerazione per la priorità
typedef enum {
    ALTA = 1,
    MEDIA = 2,
    BASSA = 3
} Priorita;

// Struttura per rappresentare un'attività
typedef struct {
    char descrizione[MAX_DESC];
    char corso[MAX_CORSO];
    char dataScadenza[MAX_DATA]; // formato "YYYY-MM-DD"
    int tempoStimato;            // in ore
    int tempoEffettivo;          // in ore
    Priorita priorita;           // ALTA = 1, MEDIA = 2, BASSA = 3
    int completata;              // 0 = no, 1 = sì
} Attivita;

// Nodo per lista collegata
typedef struct Nodo {
    Attivita attivita;
    struct Nodo* next;
} Nodo;

// Prototipi delle funzioni
Nodo* aggiungi_attivita(Nodo* head, Attivita a);
void stampa_attivita(Nodo* head);
void aggiorna_stato_attivita(Nodo* head);
void libera_lista(Nodo* head);

#endif
