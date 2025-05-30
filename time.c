#include "time.h"
#include <time.h>
#include <stdio.h>
#include <string.h> // Per strlen e strncpy

void data_corrente(char* buffer, int len) {
    time_t t = time(NULL);
    struct tm tm_info = *localtime(&t);
    strftime(buffer, len, "%Y-%m-%d", &tm_info);
}

void converti_data_DDMMYYYY_in_YYYYMMDD(const char* data_in, char* data_out, size_t dim) {
    // data_in deve essere in formato DD-MM-YYYY
    if (strlen(data_in) != 10 || data_in[2] != '-' || data_in[5] != '-') {
        strncpy(data_out, data_in, dim);
        data_out[dim - 1] = '\0';
        return;
    }
    snprintf(data_out, dim, "%.4s-%.2s-%.2s", data_in + 6, data_in + 3, data_in);
}