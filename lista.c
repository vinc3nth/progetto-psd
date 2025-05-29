#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

// Inserisce in coda (ordine di creazione)
Nodo* aggiungi_attivita(Nodo* head, Attivita a) {
    Nodo* nuovo = malloc(sizeof(Nodo));
    if (!nuovo) return head;
    nuovo->attivita = a;
    nuovo->next = NULL;

    if (head == NULL) {
        return nuovo;
    }

    Nodo* curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = nuovo;
    return head;
}

void stampa_attivita(Nodo* head) {
    Nodo* curr = head;
    int i = 1;
    while (curr) {
        printf("\nAttivita %d\n", i++);
        printf("Nome: %s\n", curr->attivita.nome);
        printf("Corso: %s\n", curr->attivita.corso);
        printf("Data Scadenza: %s\n", curr->attivita.dataScadenza);
        printf("Tempo stimato: %d ore\n", curr->attivita.tempoStimato);
        printf("Tempo effettivo: %d ore\n", curr->attivita.tempoEffettivo);
        printf("Priorita: %d\n", curr->attivita.priorita);
        printf("Completata: %s\n", curr->attivita.completata ? "Si" : "No");
        curr = curr->next;
    }
}

void aggiorna_stato_attivita(Nodo* head) {
    char nome[100];
    printf("Inserisci nome attivita da aggiornare: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = 0;

    Nodo* curr = head;
    while (curr) {
        if (strcmp(curr->attivita.nome, nome) == 0) {
            printf("Inserisci tempo effettivo speso: ");
            if (scanf("%d", &curr->attivita.tempoEffettivo) != 1) {
                printf("Input non valido per tempo effettivo.\n");
                while (getchar() != '\n');
                return;
            }

            printf("Completata? (1 = si, 0 = no): ");
            if (scanf("%d", &curr->attivita.completata) != 1) {
                printf("Input non valido per completamento.\n");
                while (getchar() != '\n');
                return;
            }

            while (getchar() != '\n'); // Pulisci il buffer
            return;
        }
        curr = curr->next;
    }
    printf("Attivita non trovata.\n");
}

void libera_lista(Nodo* head) {
    while (head) {
        Nodo* temp = head;
        head = head->next;
        free(temp);
    }
}
