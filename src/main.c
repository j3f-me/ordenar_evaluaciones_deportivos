#ifndef _POSIX_C_SOURCE
#define _POSIX_C_SOURCE 200112L
#endif

#include <stdio.h>
#include <string.h>

#include "atleta.h"
#include "lector.h"
#include "utils.h"

int main(int argc, char **argv) {
    int verbose = 0;
    if (argc == 3 && strcmp(argv[2], "-v") == 0) {
        verbose = 1;
    } else if (argc != 2) {
        fprintf(stderr, "usage: ./main <path/to/*.txt>\n");
        return -1;
    }
    char* path = argv[1];
    // extraer arreglo con los datos -> lector
    int n_entries = get_entry_num(path);
    printf("init array with athlete size %d\n", n_entries);
    // create array structure
    atleta* atletas[n_entries];
    extract_data(atletas, path);



    return 0;
}
