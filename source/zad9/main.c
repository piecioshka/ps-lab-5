/**
 * Zadanie 9.
 * Napisz program, który pokazuje jak najwięcej atrybutów procesu
 * (identyfikatory, bieżący katalog, katalog główny, maskę plików,
 * ustalenia dotyczące obsługi sygnałów, otwarte pliki, inne).
 */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[]) {
    // 1) identyfikator procesu
    printf("* id procesu: %d\n", getpid());
    // 2) bieżący katalog
    // 3) katalog główny
    // 4) maskę plików
    // 5) ustalenia dotyczące obsługi sygnałów
    // 6) otwarte pliki
    // 7) inne...

    return 0;
}
