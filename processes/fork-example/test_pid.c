#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char ** argv) {

    int pid = fork();

    printf("Forking...the pid: %d\n", pid);
    for (int i=0; i<5; i++) {
        printf(" %d\t%d\n", i, getpid());
    }
    if (pid) {
        wait(NULL);
    }

    return EXIT_SUCCESS;
}
