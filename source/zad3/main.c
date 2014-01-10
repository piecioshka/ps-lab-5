/**
 * Zadanie 3.
 * Procesy - użycie funkcji fork(), exec(), wait()
 * a) Napisz program, który tworzy jeden proces potomny.
 * Proces potomny ma wyświetlić tekst: „Today is:” Do wyświetlenia tekstu użyj polecenia /bin/echo.
 * Proces macierzysty ma wyświetlić datę. Użyj do tego polecenia /bin/date. Przykład:
 * Today is:
 * Saturday, November 5, 2005
 * b) Wykonaj kilka razy program. Czy zawsze tekst pojawi się przed datą?
 * Zmodyfikuj program tak, aby zawsze tekst pojawiał się przed datą.
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char * argv[]) {
    int child;

    /* utworzenie potomka */
    switch (child = fork()) {
        case -1: printf("error\n"); break;
        case 0:
            /* potomek */
            system("/bin/echo \"Today is:\"");
            break;
        default:
            /* macierzysty */
            wait(NULL);
            system("/bin/date");
    }

    return 0;
}
