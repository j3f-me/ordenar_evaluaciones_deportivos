//
// Created by jan on 22.11.24.
//

#include "lector.h"

void check_and_open(char* path, FILE* txt) {
    if (!ends_with(path, ".txt")) {
        fprintf(stderr, "file is not a valid text file");
        exit(EXIT_FAILURE);
    }

    // read file
    // https://www.geeksforgeeks.org/read-a-file-line-by-line-in-c/
    txt = fopen(path, "r");

    if (txt == NULL) {
        fprintf(stderr, "file was not found");
        exit(EXIT_FAILURE);
    }

}


int get_entry_num(char* path) {

    FILE* txt = NULL;
    check_and_open(path, txt);

    // buffer para almacenar cada palabra
    char linea[BUFFER_SIZE];

    int num_entries = 0;
    while (fgets(linea, sizeof(linea), txt)) {
        num_entries++;
    }

    fclose(txt);

    return num_entries;
}





void extract_data(int* array, char* path) {

    FILE* txt = NULL;
    check_and_open(path, txt);

    char linea[BUFFER_SIZE];

    while (fgets(linea, sizeof(linea), txt)) {
        // limpiar \n (remover saltos de linea) y tambien \r carriage retorneos
        // fuente: https://www.geeksforgeeks.org/removing-trailing-newline-character-from-fgets-input/
        linea[strcspn(linea, "\r\n")] = '\0';

        // extraer extructura de datos
    }

    fclose(txt);
}
