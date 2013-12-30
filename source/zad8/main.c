/**
 * Zadanie 8. Demony
 * a) Napisz program, który będzie działał jako demon.
 * Zadaniem programu jest wpisywanie znacznika czasu do pliku co jedną minutę.
 * Program ma przesyłać komunikat o uruchomieniu i ewentualnych błędach do demona syslogd.
 * Wskazówka: użyj funkcji bibliotecznej daemon() .
 *
 * b) Uzupełnij program o czytanie pliku konfiguracyjnego, w którym podawana jest częstotliwość
 * generowania znacznika czasu.
 *
 * c) Zmodyfikuj program tak, aby w trakcie działania programu możliwe było ponowne przeczytanie
 * pliku konfiguracyjnego. Wskazówka: wykorzystaj sygnał SIGHUP.
 */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {
    daemon(0, 0);

    printf("test");

    return 0;
}
