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

    Point moves[] = {
            {.x = 1, .y = 1},
            {.x = 3, .y = 1},
            {.x = 5, .y = 1},
            {.x = 7, .y = 1},
            {.x = 1, .y = 2},
    };

    int trees;
    long total = 1;

    for (int i = 0; i < 5; i++) {
        map.x = 0;
        map.y = 0;
        trees = 0;

        while (map.lines[map.y]) {
            if (map.lines[map.y][map.x] == '#') {
                trees++;
            }

            map.x += moves[i].x;
            map.y += moves[i].y;

            if (map.x > map.width) {
                map.x = map.x - map.width - 1;
            }
        }

        total = total * trees;
    }

    printf("Total: %ld\n", total);
}
