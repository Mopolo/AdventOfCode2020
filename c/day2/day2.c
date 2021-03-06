#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "day2.h"
#include "../common/strings.h"

Line process(char* input) {
    Line line;

    char** parts = split(input, " ");

    char** numbers = split(parts[0], "-");

    line.letter = parts[1][0];

    char *end;
    line.min = (int)strtol(numbers[0], &end, 10);
    line.max = (int)strtol(numbers[1], &end, 10);

    line.password = parts[2];

    // To remove the ending \n
    if (line.password[strlen(line.password)-1] == '\n') {
        line.password[strlen(line.password)-1] = '\0';
    }

    return line;
}

int isValid(Line line) {
    int quantity = 0;

    for (int i = 0; i < strlen(line.password); i++) {
        if (line.password[i] == line.letter) {
            quantity++;
        }
    }

    return quantity >= line.min && quantity <= line.max;
}

int isValidPart2(Line line) {
    int quantity = 0;
    int positionMin = line.min - 1;
    int positionMax = line.max - 1;

    if (positionMin <= strlen(line.password)
        && line.password[positionMin] == line.letter
    ) {
        quantity++;
    }

    if (positionMax <= strlen(line.password)
        && line.password[positionMax] == line.letter
    ) {
        quantity++;
    }

    return quantity == 1;
}

void day2() {
    FILE *input = fopen("../day2/input.txt", "r");

    if (input == NULL) {
        printf("File not found\n");
        exit(-1);
    }

    int validPasswords = 0;
    char* line = NULL;
    size_t len = 0;

    while (getline(&line, &len, input) != -1) {
        Line l = process(line);

        printf(" Letter: %c", l.letter);
        printf(" Min: %d", l.min);
        printf(" Max: %d", l.max);
        printf(" Password: %s\n", l.password);

        if (isValidPart2(l) == 1) {
            validPasswords++;
        }
    }

    fclose(input);

    if (line) {
        free(line);
    }

    printf("Day 2: %d\n", validPasswords);
}
