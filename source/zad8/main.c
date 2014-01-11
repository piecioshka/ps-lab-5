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

#define FILENAME "zad8.conf"

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
        fprintf(stderr, "Can't open file: %s\n", filename);
        syslog(LOG_ERR, "Can't open file: %s\n", filename);

        exit(1);
    }
    fputs(cnt, fp);
    fclose (fp);
}

static int x;

void create_interval(int seconds, void (*func)()) {
    time_t start, end;
    time(&start);

    for(x = 1;x == 1;) {
        time(&end);
        if (difftime(end, start) >= seconds) {
            func();
            create_interval(seconds, func);
            break;
        }
    }
}

void clear_interval() {
    x = 2;
}

void save_time_to_file() {
    char timestamp[12];
    sprintf(timestamp, "%d\n", get_current_timestamp());
    append_file_content("test_file.dat", timestamp);
}

int load_configuration_time(char * filename) {
    FILE * fd;
    int time = -1;

    if (!file_exists(filename)) {
        fprintf(stderr, "File not exists: %s\n", filename);
        syslog(LOG_ERR, "File not exists: %s\n", filename);
    }
    if ((fd = fopen(filename, "r")) == NULL) {
        fprintf(stderr, "Can't open file: %s\n", filename);
        syslog(LOG_ERR, "Can't open file: %s\n", filename);
    }

    if (fscanf(fd, "%d\n", &time) == EOF) {
        fprintf(stderr, "Can't scan file: %s\n", filename);
        syslog(LOG_ERR, "Can't scan file: %s\n", filename);
    }
    fclose(fd);

    return time;
}

void sig_hup_handler() {
    int time = load_configuration_time(FILENAME);
    clear_interval();
    create_interval(time, save_time_to_file);
}

int main(int argc, char * argv[]) {
    /* 1) pobieramy z konfiguracji time */
    int time = load_configuration_time(FILENAME);

    /* 2) odświeżamy czas w przypadku odpowiedniego sygnału */
    signal(SIGHUP, sig_hup_handler);

    /* 3) uruchamiamy demona */
    daemon(1, 1);

    /* 4) informujemy syslogd o uruchomieniu */
    openlog(argv[0], LOG_PID, 0);

    /* 5) zapisujemy do pliku co jedną minutę aktualny timestamp */
    create_interval(time, save_time_to_file);

    return 0;
}
