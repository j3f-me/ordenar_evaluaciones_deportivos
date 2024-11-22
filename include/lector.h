//
// Created by jan on 22.11.24.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "utils.h"

#ifndef LECTOR_H
#define LECTOR_H

#define BUFFER_SIZE 200

// functions called from main
int get_entry_num(char* path);

void extract_data(int* array, char* path);

// helper functions for extract data
void check_and_open(char* path, FILE* file);

#endif //LECTOR_H
