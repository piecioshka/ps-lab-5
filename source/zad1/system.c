#include <stdlib.h>
#include <stdio.h>

struct {
    char *abbrev;
    char *fullname;
} days[] = {
    { "Mon", "Monday" },
    { "Tue", "Tuesday" },
    { "Wed", "Wednesday" },
    { "Thu", "Thursday" },
    { "Fri", "Friday" },
    { "Sat", "Saturday" },
    { "Sun", "Sunday" },
    { 0, 0 }
};

int main(void) {
    int i;
    int status;
    char command[BUFSIZ];

    /* save current value of LANG variable */
    char * cache_lang = getenv("LANG");

    /* set LANG to english version */
    setenv("LANG", "en_EN", 1);

    for (i=0; days[i].abbrev != NULL; i++) {
        sprintf(command, "date | grep %s > /dev/null", days[i].abbrev);
        status = system(command);
        switch ((status >> 8) & 0xff) {
            case 0: printf("Today is %s.\n", days[i].fullname); break;
            case 1: printf("Today is not %s.\n", days[i].fullname); break;
            case 2: printf("Error in pattern specification.\n"); exit(1);
        }
    }

    /* restore default value */
    setenv("LANG", cache_lang, 1);

    exit(0);
}
