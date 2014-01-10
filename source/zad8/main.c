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
#include <time.h>
#include <string.h>
#include <syslog.h>

int get_current_timestamp() {
    time_t current;
    return time(&current);
}

int file_exists(char * filename) {
    return access(filename, F_OK) != -1;
}

void append_file_content(char * filename, char * cnt) {
    FILE *fp;
    if ((fp = fopen(filename, "a+")) == NULL) {
        /* domyslny komunikat, jesli nie jest demonem */
        /* fprintf(stderr, "Can't open file: %s\n", filename); */

        /* jesli program jest demonem to wszelkie bledy wysylamy do sysloga */
        syslog(LOG_ERR, "Can't open file: %s\n", filename);

        exit(1);
    }
    fputs(cnt, fp);
    fclose (fp);
}

void create_interval(int seconds, void (*func)()) {
    time_t start, end;
    time(&start);

    for(;;) {
        time(&end);
        if (difftime(end, start) >= seconds) {
            func();
            create_interval(seconds, func);
            break;
        }
    }
}

void save_time_to_file() {
    char timestamp[12];
    sprintf(timestamp, "%d\n", get_current_timestamp());
    append_file_content("test_file.dat", timestamp);
}

int main(int argc, char * argv[]) {
    /* 1) uruchamiamy demona */
    daemon(1, 1);

    /* 2) informujemy syslogd o uruchomieniu */
    openlog(argv[0], LOG_PID, 0);

    /* 3) zapisujemy do pliku co jedną minutę aktualny timestamp */
    create_interval(10, save_time_to_file);

    return 0;
}
