#include <stdio.h>
#include <string.h>
#include "report.h"
#include "time.h"

void formatta_data(const char* data_in, char* data_out, size_t dim) {
    if (strlen(data_in) < 10) {
        strncpy(data_out, data_in, dim);
        data_out[dim - 1] = '\0';
        return;
    }
    if (data_in[4] == '-') {
        // YYYY-MM-DD -> DD-MM-YYYY
        snprintf(data_out, dim, "%.2s-%.2s-%.4s", data_in + 8, data_in + 5, data_in);
    } else {
        strncpy(data_out, data_in, dim);
        data_out[dim - 1] = '\0';
    }
}

const char* descrizione_priorita(int p) {
    switch(p) {
        case 1: return "Alta";
        case 2: return "Media";
        case 3: return "Bassa";
        default: return "Sconosciuta";
    }
}

void genera_report_settimanale(Nodo* head, const char* filename, const char* data_oggi) {
    FILE* f = fopen(filename, "w");
    if (!f) {
        perror("Errore apertura file report");
        return;
    }

    fprintf(f, "--- Report Settimanale ---\n");
    fprintf(f, "Data generazione: %s\n\n", data_oggi);

    // Converte data_oggi da DD-MM-YYYY a YYYY-MM-DD per confronto
    char data_oggi_fmt[11];
    converti_data_DDMMYYYY_in_YYYYMMDD(data_oggi, data_oggi_fmt, sizeof(data_oggi_fmt));

    // === ATTIVITA COMPLETATE ===
    fprintf(f, "=== Attivita Completate ===\n\n");
    Nodo* curr = head;
    int trovate = 0;
    while (curr) {
        if (curr->attivita.completata) {
            char data_formattata[11];
            formatta_data(curr->attivita.dataScadenza, data_formattata, sizeof(data_formattata));
            fprintf(f, "Nome: %s\n", curr->attivita.nome);
            fprintf(f, "Corso: %s\n", curr->attivita.corso);
            fprintf(f, "Data Scadenza: %s\n", data_formattata);
            fprintf(f, "Priorita: %d (%s)\n", curr->attivita.priorita, descrizione_priorita(curr->attivita.priorita));
            fprintf(f, "Tempo stimato: %d ore\n", curr->attivita.tempoStimato);
            fprintf(f, "Tempo effettivo: %d ore\n", curr->attivita.tempoEffettivo);
            fprintf(f, "Completata: Si\n\n");
            trovate++;
        }
        curr = curr->next;
    }
    if (trovate == 0) fprintf(f, "Nessuna attivita completata.\n\n");

    // === ATTIVITA IN CORSO ===
    fprintf(f, "=== Attivita In Corso ===\n\n");
    curr = head;
    trovate = 0;
    while (curr) {
        if (!curr->attivita.completata) {
            char data_scadenza_fmt[11];
            converti_data_DDMMYYYY_in_YYYYMMDD(curr->attivita.dataScadenza, data_scadenza_fmt, sizeof(data_scadenza_fmt));
            if (strcmp(data_scadenza_fmt, data_oggi_fmt) >= 0) {
                char data_formattata[11];
                formatta_data(curr->attivita.dataScadenza, data_formattata, sizeof(data_formattata));
                fprintf(f, "Nome: %s\n", curr->attivita.nome);
                fprintf(f, "Corso: %s\n", curr->attivita.corso);
                fprintf(f, "Data Scadenza: %s\n", data_formattata);
                fprintf(f, "Priorita: %d (%s)\n", curr->attivita.priorita, descrizione_priorita(curr->attivita.priorita));
                fprintf(f, "Tempo stimato: %d ore\n", curr->attivita.tempoStimato);
                fprintf(f, "Completata: No\n\n");
                trovate++;
            }
        }
        curr = curr->next;
    }
    if (trovate == 0) fprintf(f, "Nessuna attivita in corso.\n\n");

    // === ATTIVITA IN RITARDO ===
    fprintf(f, "=== Attivita In Ritardo ===\n\n");
    curr = head;
    trovate = 0;
    while (curr) {
        if (!curr->attivita.completata) {
            char data_scadenza_fmt[11];
            converti_data_DDMMYYYY_in_YYYYMMDD(curr->attivita.dataScadenza, data_scadenza_fmt, sizeof(data_scadenza_fmt));
            if (strcmp(data_scadenza_fmt, data_oggi_fmt) < 0) {
                char data_formattata[11];
                formatta_data(curr->attivita.dataScadenza, data_formattata, sizeof(data_formattata));
                fprintf(f, "Nome: %s\n", curr->attivita.nome);
                fprintf(f, "Corso: %s\n", curr->attivita.corso);
                fprintf(f, "Data Scadenza: %s\n", data_formattata);
                fprintf(f, "Priorita: %d (%s)\n", curr->attivita.priorita, descrizione_priorita(curr->attivita.priorita));
                fprintf(f, "Tempo stimato: %d ore\n", curr->attivita.tempoStimato);
                fprintf(f, "Completata: No\n\n");
                trovate++;
            }
        }
        curr = curr->next;
    }
    if (trovate == 0) fprintf(f, "Nessuna attivita in ritardo.\n\n");

    fclose(f);
}
