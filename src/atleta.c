//
// Created by jan on 22.11.24.
//

#include "atleta.h"


int is_athlete_id(char* str) {
    if (str == NULL || *str == '\0') {
        return 0;
    }

    unsigned long len = strlen(str);

    if (len != ID_DIGITS) {
        return 0;
    }

    for (size_t i=0; i < len; i++) {
        if (!isdigit(*(str+i))) {
            return 0;
        }
    }

    return 1;
}
int is_event_id(char* str) {

    if (str == NULL || *str == '\0') {
        return 0;
    }

    unsigned long len = strlen(str);

    if (len != EVENT_DIGITS) {
        return 0;
    }

    for (size_t i=0; i < (EVENT_DIGITS / 2); i++) {
        if (!('A' <= *(str + i) && *(str + i) <= 'Z')) {
            return 0;
        }
    }
    for (size_t i=(EVENT_DIGITS / 2); i < EVENT_DIGITS; i++) {
        if (!isdigit(*(str+i))) {
            return 0;
        }
    }

    return 1;
}
int is_score(char* str) {

    if (str == NULL || *str == '\0') {
        return 0;
    }

    unsigned long len = strlen(str);

    if (len != SCORE_DIGITS) {
        return 0;
    }

    for (size_t i=0; i < len; i++) {
        if (!isdigit(*(str+i))) {
            return 0;
        }
    }

    return 1;
}

int get_score(atleta *atl) {
    return atoi(atl->score); // I make sure I do not store invalid digits as string
}

atleta* create_atleta(int id, char* event, char* score) {
    // do some data validation -> or do this in lector?

    atleta* new = (atleta*) malloc(sizeof(atleta));
    new->id = id;
    strcpy(new->event, event);
    strcpy(new->score, score);

    return new;
}