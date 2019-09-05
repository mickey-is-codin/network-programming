#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

/*
Goal:
Generate

graph G {
    main -- parse -- execute;
    main -- init;
    main -- cleanup;
    execute -- make_string;
    execute -- printf
    init -- make_string;
    main -- printf;
    execute -- compare;
}
*/

int main(int argc, char ** argv) {

    return EXIT_SUCCESS;
}
