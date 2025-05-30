CC = gcc
CFLAGS = -Wall -Wextra -std=c11
REPORT = report_settimanale.txt

all: programma test $(REPORT)

programma: main.o lista.o report.o time.o
	$(CC) $(CFLAGS) -o programma main.o lista.o report.o time.o

test: test.o lista.o report.o time.o
	$(CC) $(CFLAGS) -o test test.o lista.o report.o time.o

main.o: main.c lista.h report.h time.h
	$(CC) $(CFLAGS) -c main.c

test.o: test.c lista.h report.h time.h
	$(CC) $(CFLAGS) -c test.c

lista.o: lista.c lista.h
	$(CC) $(CFLAGS) -c lista.c

report.o: report.c report.h lista.h
	$(CC) $(CFLAGS) -c report.c

time.o: time.c time.h
	$(CC) $(CFLAGS) -c time.c

$(REPORT):
	@echo --- Report Settimanale --- > $(REPORT)

clean:
	del /Q *.o programma.exe test.exe $(REPORT) 2> NUL || exit 0
