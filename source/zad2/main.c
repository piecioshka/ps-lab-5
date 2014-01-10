/**
 * Zadanie 2.
 * Procesy - użycie funkcji fork()
 * Napisz program, który tworzy jeden proces potomny. 
 * Proces potomny wyświetla n razy zestaw małych liter alfabetu (czyli litery od a do z), 
 * proces macierzysty wyświetla n razy zestaw wielkich liter alfabetu (czyli litery od A do Z.
 * Wartość n jest podawana w wierszu wywołania programu. 
 * Sprawdź, czy każde wykonanie programu będzie przebiegało tak samo? 
 * Spróbuj uruchomić program na różnych komputerach, na przykład na oceanic. Wybierz duże n.
 */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {
    int i, n, child;

    if (argc < 2) {
        fprintf(stderr, "Podac liczbę\n");
        exit(1);
    }

    n = atoi(argv[1]);

    /* tworzymy nowy proces */
    switch (child = fork()) {
        case -1: printf("error"); break;
        case 0:
            /* potomny */
            for(i = 0; i < n; ++i) {
                printf("a");
            }
            break;
        default:
            /* macierzysty */
            for(i = 0; i < n; ++i) {
                printf("A");
            }
    }

    exit(0);
}
