#ifndef _POSIX_C_SOURCE
#define _POSIX_C_SOURCE 200112L
#endif

#include <stdio.h>
#include <string.h>
#include <time.h>

#include "atleta.h"
#include "lector.h"
#include "ordenamiento.h"
#include "utils.h"

int main(int argc, char **argv) {
    int verbose = 0;
    if (argc == 3 && strcmp(argv[2], "-v") == 0) {
        verbose = 1;
    } else if (argc != 2) {
        fprintf(stderr, "usage: ./main <path/to/*.txt>\n");
        return -1;
    }
    char *path = argv[1];
    // 1) extraer arreglo con los datos -> lector
    int n_entries = get_entry_num(path);
    printf("init array with athlete size %d\n", n_entries);
    // create array structure
    atleta *atletas[n_entries];
    extract_data(atletas, path);

    if (verbose) {
        printf("unsorted ids:\n");
        for (int i = 0; i < n_entries; i++) {
            atleta *temp = atletas[i];
            printf("id: %d event: %s score: %s\n", temp->id, temp->event, temp->score);
        }
    }

    // copy data to have multiple trails for different complexities
    atleta *unsorted1[n_entries];
    atleta *unsorted2[n_entries];
    atleta *unsorted3[n_entries];

    for (int i = 0; i < n_entries; i++) {
        // Allocate memory for each atleta in unsorted1, unsorted2, and unsorted3
        unsorted1[i] = malloc(sizeof(atleta));
        unsorted2[i] = malloc(sizeof(atleta));
        unsorted3[i] = malloc(sizeof(atleta));

        // Deep copy for unsorted1
        unsorted1[i]->id = atletas[i]->id;
        char* event1 = copy_str(atletas[i]->event);
        char* score1 = copy_str(atletas[i]->score);
        strcpy(unsorted1[i]->event, event1);
        strcpy(unsorted1[i]->score, score1);
        free(event1);
        free(score1);

        // Deep copy for unsorted2
        unsorted2[i]->id = atletas[i]->id;
        strcpy(unsorted2[i]->event, atletas[i]->event);
        strcpy(unsorted2[i]->score, atletas[i]->score);

        // Deep copy for unsorted3
        unsorted3[i]->id = atletas[i]->id;
        strcpy(unsorted3[i]->event, atletas[i]->event);
        strcpy(unsorted3[i]->score, atletas[i]->score);
    }


    // 2) ordering with one of the three different complexity algorithms
    double times[3]; // 0: bubble, 1: quick, 2: radix (stored in us)

    struct timespec start, end;
    clock_gettime(CLOCK_REALTIME, &start);
    int comp_bubble = bubble_sort(atletas, n_entries);
    clock_gettime(CLOCK_REALTIME, &end);
    // calculate elapsed time in microseconds
    long seconds = end.tv_sec - start.tv_sec;
    long nanoseconds = end.tv_nsec - start.tv_nsec;
    double delta_ms = (double) seconds * 1e6 + (double) nanoseconds / 1e3;
    times[0] = delta_ms;
    if (verbose) {
        printf("Bubble Sort: %d comparisons %.3lf us\n", comp_bubble, delta_ms);
    }
    // 3) extraction of the ordered array into THE file: evaluaciones_ordenadas.txt
    const char *out_path = "evaluaciones_ordenadas.txt";
    FILE *out = fopen(out_path, "w");
    for (int i = 0; i < n_entries; i++) {
        atleta *temp = atletas[i];
        fprintf(out, "%d %s %s\n", temp->id, temp->event, temp->score);
    }
    fclose(out);
    printf("### %s generated \n", out_path);

    // 4) report of complexity (time measurement, count of comparisons, number of used memory, ...)
    clock_gettime(CLOCK_REALTIME, &start);
    int comp_quick = 0;
    quick_sort(unsorted1, 0, n_entries - 1, &comp_quick);
    clock_gettime(CLOCK_REALTIME, &end);
    seconds = end.tv_sec - start.tv_sec;
    nanoseconds = end.tv_nsec - start.tv_nsec;
    delta_ms = (double) seconds * 1e6 + (double) nanoseconds / 1e3;
    times[1] = delta_ms;
    if (verbose) {
        printf("Quick Sort: %.3lf us\n", delta_ms);
    }

    clock_gettime(CLOCK_REALTIME, &start);
    int comp_radix = radix_sort(unsorted2, n_entries);
    clock_gettime(CLOCK_REALTIME, &end);
    seconds = end.tv_sec - start.tv_sec;
    nanoseconds = end.tv_nsec - start.tv_nsec;
    delta_ms = (double) seconds * 1e6 + (double) nanoseconds / 1e3;
    times[2] = delta_ms;
    if (verbose) {
        printf("Radix Sort: %.3lf us\n", delta_ms);
    }

    // write file
    const char *log_path = "reporte.txt";
    FILE *log_file = fopen(log_path, "w");
    fprintf(log_file, "             |   TIME [us]  |  COMPARISONS  | \n");
    fprintf(log_file, "Bubble Sort  |   %.3lf     |      %d     |\n", times[0], comp_bubble);
    fprintf(log_file, "Quick Sort   |   %.3lf     |      %d     |\n", times[1], comp_quick);
    fprintf(log_file, "Radix Sort   |   %.3lf     |      %d     |\n", times[2], comp_radix);
    fclose(log_file);
    printf("### %s generated \n", log_path);

    // debug sorting algorithms
    if (verbose) {
        FILE *txt_quick = fopen("logs/quick_sort.txt", "w");
        for (int i = 0; i < n_entries; i++) {
            atleta *temp = unsorted1[i];
            fprintf(txt_quick, "%d %s %s\n", temp->id, temp->event, temp->score);
        }
        fclose(txt_quick);

        FILE *txt_radix = fopen("logs/radix_sort.txt", "w");
        for (int i = 0; i < n_entries; i++) {
            atleta *temp = unsorted2[i];
            fprintf(txt_radix, "%d %s %s\n", temp->id, temp->event, temp->score);
        }
        fclose(txt_radix);
    }

    // free allocated memory
    for (int i = 0; i < n_entries; i++) {
        if (atletas[i]) free(atletas[i]);
        if (unsorted1[i]) free(unsorted1[i]);
        if (unsorted2[i]) free(unsorted2[i]);
        if (unsorted3[i]) free(unsorted3[i]);
    }

    return 0;
}
