#ifndef REPORT_H
#define REPORT_H

#include "attivita.h"
#include "lista.h"

const char* descrizione_priorita(int p);
void genera_report_settimanale(Nodo* head, const char* filename, const char* data_oggi);

#endif
