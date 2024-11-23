//
// Created by jan on 22.11.24.
//

#ifndef _POSIX_C_SOURCE
#define _POSIX_C_SOURCE 200112L
#endif


#ifndef LECTOR_H
#define LECTOR_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "utils.h"
#include "atleta.h"

#define BUFFER_SIZE 200
#define ARGS 3
#define DEBUG_MODE 0

// functions called from main
int get_entry_num(char* path);

void extract_data(atleta** array, char* path);

// helper functions for extract data
void check_and_open(char* path, FILE** file);

#endif //LECTOR_H
