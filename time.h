#ifndef TIME_H
#define TIME_H

#include <stddef.h> // Per size_t

void data_corrente(char* buffer, int len);
void converti_data_DDMMYYYY_in_YYYYMMDD(const char* input, char* output, size_t dim);

#endif
