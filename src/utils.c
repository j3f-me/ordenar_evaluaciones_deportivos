//
// Created by jan on 22.11.24.
//

#include "utils.h"

// Function to check if a string ends with a given suffix
bool ends_with(const char* str, const char* suffix) {
    if (!str || !suffix) {
        return false; // Handle null pointers
    }

    size_t str_len = strlen(str);
    size_t suffix_len = strlen(suffix);

    if (suffix_len > str_len) {
        return false; // Suffix is longer than the string
    }

    // Compare the end of the string with the suffix
    return strcmp(str + str_len - suffix_len, suffix) == 0;
}

char* copy_str(const char* str) {
    // Allocate memory for the string copy
    size_t len = strlen(str) + 1; // note null terminator
    char* copy = (char*)malloc(len); // Allocate memory
    if (!copy) {
        return NULL;
    }

    strcpy(copy, str);

    return copy;
}