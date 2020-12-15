#include <stdlib.h>
#include <string.h>
#include <printf.h>
#include "strings.h"

char **split(char *input, char *separator) {
    int partsIndex = 0;

    char **parts = malloc(sizeof(char *));
    char *token = strtok(input, separator);

    while (token) {
        parts = realloc(parts, (partsIndex + 1) * sizeof(char *));

        parts[partsIndex] = malloc(sizeof(token));

        strcpy(parts[partsIndex], token);

        token = strtok(NULL, separator);
        partsIndex++;
    }

    // We ann NULL as the last element to signal the array ending
    parts = realloc(parts, (partsIndex + 1) * sizeof(char *));
    parts[partsIndex] = NULL;

    return parts;
}

char *trim(char *str) {
    char *end;

    // Trim leading space
    while (isspace((unsigned char) *str)) {
        str++;
    }

    // All spaces?
    if (*str == 0) {
        return str;
    }

    // Trim trailing space
    end = str + strlen(str) - 1;

    while (end > str && isspace((unsigned char) *end)) {
        end--;
    }

    // Write new null terminator character
    end[1] = '\0';

    return str;
}
