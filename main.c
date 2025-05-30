#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "attivita.h"
#include "lista.h"
#include "report.h"
#include "time.h"  // Include per data_corrente

int main() {
    Nodo* lista = NULL;
    int scelta;

    char data_oggi[11];
    data_corrente(data_oggi, sizeof(data_oggi)); // Ottieni data corrente

    // Se il file non esiste, crea con intestazione
    FILE* f = fopen("report_settimanale.txt", "r");
    if (!f) {
        genera_report_settimanale(NULL, "report_settimanale.txt", data_oggi);
    } else {
        fclose(f);
    }

    do {
        printf("\n1. Inserisci nuova attivita\n");
        printf("2. Aggiorna stato attivita\n");
        printf("3. Esci\n");
        printf("Scelta: ");
        scanf("%d", &scelta);
        getchar();

        if (scelta == 1) {
            Attivita a;
            printf("Nome attivita: ");
            fgets(a.nome, MAX_DESC, stdin);
            a.nome[strcspn(a.nome, "\n")] = 0;

            printf("Corso: ");
            fgets(a.corso, MAX_CORSO, stdin);
            a.corso[strcspn(a.corso, "\n")] = 0;

            printf("Data scadenza (DD-MM-YYYY): ");
            fgets(a.dataScadenza, MAX_DATA, stdin);
            a.dataScadenza[strcspn(a.dataScadenza, "\n")] = 0;

            printf("Tempo stimato (Ore): ");
            scanf("%d", &a.tempoStimato);
            getchar();

            a.tempoEffettivo = 0;
            a.completata = 0;

            int p;
            do {
                printf("Priorita (1=Alta, 2=Media, 3=Bassa): ");
                scanf("%d", &p);
                getchar();
            } while (p < 1 || p > 3);
            a.priorita = p;

            lista = aggiungi_attivita(lista, a);
            genera_report_settimanale(lista, "report_settimanale.txt", data_oggi);
        }

        else if (scelta == 2) {
            aggiorna_stato_attivita(lista);
            genera_report_settimanale(lista, "report_settimanale.txt", data_oggi);
        }

    } while (scelta != 3);

    libera_lista(lista);
    return 0;
}
