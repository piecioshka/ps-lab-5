/**
 * Zadanie 6. Obsługa sygnałów
 * Napisz program, który co n sekund wypisuje na ekranie komunikat: "Działam dalej".
 * Naciśnięcie klawiszy CTRL+C (sygnał INT) wypisuje napis "Przechwycilem sygnal"
 * i program kontynuuje działanie.
 * > Jakiej funkcji użyjesz do odmierzania czasu?
 * Porównuje w pętli czas pomiędzy aktualnym czasem, a czasem pobranym przed rozpoczęciem zliczania
 *
 * > Jak zakończyć ten program?
 * Wysłać sygnał TERM, albo inny poprzez konsole:
 * $ ps aux | grep main.o
 * $ kill PID
 */
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <time.h>

void sigint_handler(int status) {
    printf("Przechwycilem sygnal\n");
    fflush(stdout);
    return;
}

void create_interval(int seconds, void (*func)()) {
    time_t start, end;
    time(&start);

    for (;;) {
        time(&end);
        if (difftime(end, start) >= seconds) {
            func();
            create_interval(seconds, func);
            break;
        }
    }
}

void print_message() {
    printf("Działam dalej\n");
}

int main(int argc, char * argv[]) {
    int seconds;

    /* parametr wymagany */
    if (argc != 2) {
        fprintf(stderr, "Podaj liczbe sekund\n");
        exit(1);
    }

    /* rzutujemy parametr na integera */
    seconds = atoi(argv[1]);

    /* dodanie handlera na SIGINT */
    signal(SIGINT, sigint_handler);

    /* co n sekund wyświetlamy napis */
    create_interval(seconds, print_message);

    return 0;
}
