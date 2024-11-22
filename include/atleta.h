//
// Created by jan on 22.11.24.
//

#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifndef ATLETA_H
#define ATLETA_H

#define ID_DIGITS 8
#define EVENT_DIGITS 6
#define SCORE_DIGITS 3

typedef struct atleta {
    int id;
    char event[EVENT_DIGITS+1]; // include null terminator for strings
    char score[SCORE_DIGITS+1];
} atleta;

int is_athlete_id(char* str);
int is_event_id(char* str);
int is_score(char* str);

int get_score(atleta* atl);

atleta* create_atleta(int id, char* event, char* score);

#endif //ATLETA_H
