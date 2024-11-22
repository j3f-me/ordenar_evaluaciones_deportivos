#include <stdio.h>
#include <string.h>



int main(int argc, char **argv) {
    int verbose = 0;
    if (argc == 3 && strcmp(argv[2], "-v") == 0) {
        verbose = 1;
    } else if (argc != 2) {
        fprintf(stderr, "usage: ./main <path/to/*.txt>\n");
        return -1;
    }

    // extraer arreglo con los datos -> lector




    printf("Hello World!\n");
    return 0;
}
