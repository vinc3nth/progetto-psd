# Progetto Gestione Attività di Studio

## Descrizione

Questo progetto in C aiuta uno studente a gestire e monitorare le proprie attività di studio.  
Il programma permette di inserire attività con dati rilevanti (nome, corso, scadenza, priorità, tempo stimato), aggiornare lo stato di completamento, e generare report settimanali dettagliati che evidenziano attività completate, in corso o in ritardo.

---

## Requisiti del Progetto

- Inserimento di attività di studio con: descrizione, corso, data di scadenza, tempo stimato.
- Assegnazione di priorità (Alta, Media, Bassa).
- Monitoraggio del progresso in base al completamento e al tempo effettivo.
- Generazione di report settimanali che mostrano lo stato delle attività.
- Interfaccia testuale semplice.

---

## ADT e Progettazione

### 1. `Attivita`

- **Descrizione**: Rappresenta una singola attività di studio.
- **Campi**:
  - `nome` (stringa)
  - `corso` (stringa)
  - `dataScadenza` (stringa, formato `DD-MM-YYYY`)
  - `tempoStimato` (int, ore)
  - `tempoEffettivo` (int, ore)
  - `priorita` (int: 1=Alta, 2=Media, 3=Bassa)
  - `completata` (int booleano)

- **Operazioni**: creazione, aggiornamento stato, stampa.

### 2. Lista Collegata (`Nodo`)

- **Descrizione**: Implementa una lista dinamica di attività.
- **Struttura**: ogni nodo contiene un `Attivita` e un puntatore al nodo successivo.
- **Operazioni**:
  - Inserimento (`aggiungi_attivita`)
  - Aggiornamento (`aggiorna_stato_attivita`)
  - Liberazione della memoria (`libera_lista`)
  - Iterazione per stampa e report.

---

## Scelta del Design

- Ho scelto una lista collegata per flessibilità di inserimento e aggiornamento senza limiti fissi.
- Le date sono gestite come stringhe in formato `DD-MM-YYYY` per semplicità, con funzioni di confronto e conversione interna.
- La data "odierna" è inserita manualmente all'avvio, per evitare dipendenze da librerie di sistema (`time.h`) e rendere il programma portabile e semplice.
- La generazione del report usa la data inserita per classificare le attività in "Completate", "In Corso" e "In Ritardo".

---

## Specifica Sintattica e Semantica

### `aggiungi_attivita(lista, attivita)`

- **Input**: puntatore alla testa della lista e struttura `Attivita`.
- **Output**: nuova testa della lista con attività inserita in coda.
- **Precondizioni**: `attivita` valida.
- **Postcondizioni**: attività aggiunta senza perdita dati.

### `aggiorna_stato_attivita(lista)`

- **Input**: lista di attività.
- **Output**: stato e tempo effettivo aggiornati per un’attività scelta.
- **Precondizioni**: lista non vuota.
- **Postcondizioni**: attività modificata in modo coerente.

### `genera_report_settimanale(lista, filename, data_oggi)`

- **Input**: lista, nome file output, data odierna (stringa).
- **Output**: file di report aggiornato.
- **Effetti collaterali**: crea o sovrascrive file di testo con dati corretti.

---

## Istruzioni di Compilazione

- Assicurarsi di avere GCC e Make installati (es. MinGW su Windows).
- Nella cartella del progetto, eseguire:

```bash
mingw32-make clean
mingw32-make
