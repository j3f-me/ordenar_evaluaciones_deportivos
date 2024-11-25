//
// Created by jan on 22.11.24.
//

#include "lector.h"

void check_and_open(char *path, FILE **txt) {
    if (!ends_with(path, ".txt")) {
        fprintf(stderr, "file is not a valid text file");
        exit(EXIT_FAILURE);
    }

    // read file
    // https://www.geeksforgeeks.org/read-a-file-line-by-line-in-c/
    *txt = fopen(path, "r");

    if (*txt == NULL) {
        fprintf(stderr, "file was not found");
        exit(EXIT_FAILURE);
    }
}


int get_entry_num(char *path) {
    FILE *txt;
    check_and_open(path, &txt);

    // buffer para almacenar cada palabra
    char linea[BUFFER_SIZE];
    int num_entries = 0;
    while (fgets(linea, sizeof(linea), txt)) {
        if (strlen(linea) < 2) {
            printf("Linea %d esta vacia %s\n", num_entries+1, linea);
            continue;
        }
        num_entries++;
    }
    fclose(txt);

    return num_entries;
}


void extract_data(atleta **array, char *path) {
    FILE *txt = NULL;
    check_and_open(path, &txt);

    char line[BUFFER_SIZE];
    int line_index = 0;

    int index_arr = 0;
    while (fgets(line, sizeof(line), txt)) {
        line_index++;
        // limpiar \n (remover saltos de line) y tambien \r carriage retorneos
        // fuente: https://www.geeksforgeeks.org/removing-trailing-newline-character-from-fgets-input/
        line[strcspn(line, "\r\n")] = '\0';

        // extraer extructura de datos
        char *line_copy = copy_str(line);
        // split line: https://www.geeksforgeeks.org/how-to-split-a-string-by-a-delimiter-in-c/
        char *arg = strtok(line, " ");
        int arg_count = 0;
        // determine number of args
        if (arg == NULL) {
            // skip line as it does not have at least one argument
            printf("skipped: %s\n", line);
            free(line_copy);
            continue;
        }
        while (arg != NULL) {
            arg_count++;
            arg = strtok(NULL, " ");
        }

        if (arg_count != ARGS) {
            printf("skipped: %s\n", line);
            free(line_copy);
            continue;
        }

        // now get the arguments
        char *args[ARGS + 1];
        args[ARGS] = NULL;
        int index = 0;
        arg = "";
        arg = strtok(line_copy, " ");
        args[index] = arg;
        while (arg != NULL) {
            index++;
            arg = strtok(NULL, " ");
            args[index] = arg;
        }

        // validation and determination which arg is which attribute
        if (DEBUG_MODE) {
            printf("new line     ID | EV | SC\n");
            for (int i = 0; i < ARGS; i++) {
                int isAthlete = is_athlete_id(args[i]);
                int isEvent = is_event_id(args[i]);
                int isScore = is_score(args[i]);
                printf("%s   %d | %d | %d \n", args[i], isAthlete, isEvent, isScore);
            }
            printf("---------------\n");
        }

        // create athlete
        int ordered_args[ARGS]; // 0: athlete id, 1: event id, 2: score, -1: invalid
        for (size_t i = 0; i < ARGS; i++) {
            ordered_args[i] = -1;
        }
        for (int i = 0; i < ARGS; i++) {
            char *temp = args[i];
            if (is_athlete_id(temp)) {
                ordered_args[0] = i;
            } else if (is_event_id(temp)) {
                ordered_args[1] = i;
            } else if (is_score(temp)) {
                ordered_args[2] = i;
            }
        }
        for (size_t i = 0; i < ARGS; i++) {
            if (ordered_args[i] == -1) {
                // after mapping which arg holds which information there are no invalid indexes left
                // if yes, then the input line is not valid
                printf("skip ln %d: input line is corrupted", line_index);
                free(line_copy);
                continue;
            }
        }

        // create athlete
        atleta *new = create_atleta(atoi(args[ordered_args[0]]), args[ordered_args[1]], args[ordered_args[2]]);

        array[index_arr] = new;
        index_arr++;
        free(line_copy);
    }

    fclose(txt);
}
