// activity_manager.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "activity_manager.h"

Nodo* aggiungi_attivita(Nodo* head, Attivita a) {
    Nodo* nuovo = (Nodo*)malloc(sizeof(Nodo));
    nuovo->attivita = a;
    nuovo->next = head;
    return nuovo;
}

void stampa_attivita(Nodo* head) {
    Nodo* curr = head;
    int i = 1;
    while (curr) {
        printf("\nAttività %d\n", i++);
        printf("Descrizione: %s\n", curr->attivita.descrizione);
        printf("Corso: %s\n", curr->attivita.corso);
        printf("Data Scadenza: %s\n", curr->attivita.dataScadenza);
        printf("Tempo Stimato: %d ore\n", curr->attivita.tempoStimato);
        printf("Tempo Effettivo: %d ore\n", curr->attivita.tempoEffettivo);
        printf("Priorità: %d\n", curr->attivita.priorita);
        printf("Completata: %s\n", curr->attivita.completata ? "Sì" : "No");
        curr = curr->next;
    }
}

void aggiorna_stato_attivita(Nodo* head) {
    char descrizione[100];
    printf("Inserisci descrizione attività da aggiornare: ");
    getchar(); // per pulire il buffer
    fgets(descrizione, sizeof(descrizione), stdin);
    descrizione[strcspn(descrizione, "\n")] = 0;

    Nodo* curr = head;
    while (curr) {
        if (strcmp(curr->attivita.descrizione, descrizione) == 0) {
            printf("Inserisci tempo effettivo speso: ");
            scanf("%d", &curr->attivita.tempoEffettivo);
            printf("Completata? (1 = sì, 0 = no): ");
            scanf("%d", &curr->attivita.completata);
            return;
        }
        curr = curr->next;
    }
    printf("Attività non trovata.\n");
}

void libera_lista(Nodo* head) {
    while (head) {
        Nodo* temp = head;
        head = head->next;
        free(temp);
    }
}
