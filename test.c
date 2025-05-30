#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "attivita.h"
#include "lista.h"
#include "report.h"
#include "time.h"

void aggiungi_test_attivita(Nodo** lista) {
    Attivita a1 = {
        .tempoStimato = 5, .tempoEffettivo = 2, .completata = 0, .priorita = 2
    };
    strcpy(a1.nome, "Studiare C");
    strcpy(a1.corso, "Programmazione");
    strcpy(a1.dataScadenza, "2025-05-25");
    *lista = aggiungi_attivita(*lista, a1);

    assert(strcmp((*lista)->attivita.nome, "Studiare C") == 0);
    assert((*lista)->attivita.priorita == 2);

    Attivita a2 = {
        .tempoStimato = 3, .tempoEffettivo = 3, .completata = 1, .priorita = 1
    };
    strcpy(a2.nome, "Fare esercizi");
    strcpy(a2.corso, "Matematica");
    strcpy(a2.dataScadenza, "2025-06-10");
    *lista = aggiungi_attivita(*lista, a2);

    Attivita a3 = {
        .tempoStimato = 2, .tempoEffettivo = 0, .completata = 0, .priorita = 3
    };
    strcpy(a3.nome, "Leggere documentazione");
    strcpy(a3.corso, "Informatica");
    strcpy(a3.dataScadenza, "2025-07-01");
    *lista = aggiungi_attivita(*lista, a3);
}

int main() {
    Nodo* lista = NULL;
    aggiungi_test_attivita(&lista);

    char data_oggi[11];
    data_corrente(data_oggi, sizeof(data_oggi));
    genera_report_settimanale(lista, "test_automatico.txt", data_oggi);

    libera_lista(lista);
    printf("Tutti i test superati!\n");
    return 0;
}
