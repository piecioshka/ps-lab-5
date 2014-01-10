/**
 *
 * Zadanie 5. Obsługa sygnałów
 * a) Zapoznaj się z programem sigcatch.c.
 * Jakie jest zadanie funkcji signal() oraz pause()? 
 * Jak program zachowa się w przypadku otrzymana sygnału INT,
 * a jak w przypadku innego sygnału, np. QUIT, TERM?
 */
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>

void catch_ctlc(int sig_num) {
    printf("Przechwycono Control-C\n"); /* 2 */
    fflush(stdout);
    return;
}

int main() {
    /* funkcja signal() pozwala na obsługę przechwyconego sygnału */
    signal(SIGINT, catch_ctlc);
    printf("Dzialam ...\n"); /* 1 */
    /* funkcja pause() zatrzymuje proces dopóki nie zostanie dostarczony sygnał, */
    /* program działa dalej gdy zakończy się działanie obsługi sygnału */
    pause();
    printf("Bye!\n"); /* 3 */
    return 0;
}
