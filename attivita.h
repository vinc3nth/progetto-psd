#ifndef ATTIVITA_H
#define ATTIVITA_H

#define MAX_DESC 100
#define MAX_CORSO 50
#define MAX_DATA 11

// Enum per la priorita dell'attivita
typedef enum {
    ALTA = 1,
    MEDIA = 2,
    BASSA = 3
} Priorita;

// Struttura che rappresenta un'attivita
typedef struct {
    char nome[MAX_DESC];
    char corso[MAX_CORSO];
    char dataScadenza[MAX_DATA];  // Formato atteso: YYYY-MM-DD
    int tempoStimato;
    int tempoEffettivo;
    Priorita priorita;
    int completata;  // 0 = No, 1 = Si
} Attivita;

#endif
