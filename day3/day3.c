#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "day3.h"

void day3() {
    FILE *input = fopen("../day3/input.txt", "r");

    if (input == NULL) {
        printf("File not found\n");
        exit(-1);
    }

    char *line = NULL;
    size_t len = 0;

    Map map = {.x = 0, .y = 0};

    int index = 0;

    map.lines = malloc(sizeof(char *));

    while (getline(&line, &len, input) != -1) {
        // Resize the array with enough lines
        map.lines = realloc(map.lines, (index + 1) * sizeof(char *));

        // Allocate memory for the new line
        map.lines[index] = malloc(strlen(line));

        // Copy the string
        strcpy(map.lines[index], line);

        // Save the width
        map.width = ((int) strlen(line)) - 1;

        index++;
    }

    fclose(input);

    Point move = {.x = 3, .y = 1};

    int trees = 0;

    while (map.y < index) {
        if (map.lines[map.y][map.x] == '#') {
            trees++;
        }

        map.x += move.x;
        map.y += move.y;

        if (map.x > map.width) {
            map.x = map.x - map.width - 1;
        }
    }

    printf("Trees: %d\n", trees);
}
