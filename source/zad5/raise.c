/**
 * Zadanie 5. Obsługa sygnałów
 * b) Zapoznaj się z programem raise.c. Jakie jest zadanie funkcji signal(), pause(), kill()?
 */
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>

void usr1_handler(int sig_num) {
    printf("Rodzic (%d) otrzymal sygnal SIGUSR1\n", getpid());
}

int main() {
    pid_t ret;
    int status;
    int role = -1;

    ret = fork();

    if (ret > 0) {		
        printf("Rodzic: to jest proces macierzysty (pid %d)\n", getpid());
        // proces rodzica dodaje obsługę na sygnał customowy: SIGUSR1
        signal(SIGUSR1, usr1_handler);
        role = 0;
        // wtrzymuje proces rodzica, w tym czasie wykonuje się proces potomka
        pause();
        printf("Rodzic: czekam na zakonczenie potomka\n");
        ret = wait(&status);
    } else if (ret == 0) {	
        printf("Potomek: to jest proces potomny (pid %d)\n", getpid());
        role = 1;
        sleep(1);
        printf("Potomek: Wysylam SIGUSR1 do pid %d\n", getppid());
        // proces potomka wysyła do procesu macierzystego customowy sygnał: SIGUSR1
        kill(getppid(), SIGUSR1);
        sleep(2);
    } else {			
        printf("Rodzic: Blad podczas proby wykonania fork() (%d)\n", errno);
    }

    printf("%s: Koncze ...\n", ((role == 0) ? "Rodzic" : "Potomek"));

    return 0;
}
