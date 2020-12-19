#ifndef ADVENTOFCODE2020_STRINGS_H
#define ADVENTOFCODE2020_STRINGS_H

typedef struct {
    char** elements;
    int length;
} StringList;

char** split(char* input, char* separator);

char *trim(char *str);

#endif //ADVENTOFCODE2020_STRINGS_H
