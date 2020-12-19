//
// Created by Nathan Boiron on 04/12/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include "day1.h"

int findResult(int index, int *numbers) {
    int i, j, k;

    for (i = 0; i < index; i++) {
        for (j = 0; j < index; j++) {
            for (k = 0; k < index; k++) {
                if (numbers[i] + numbers[j] + numbers[k] == 2020) {
                    return numbers[i] * numbers[j] * numbers[k];
                }
            }
        }
    }

    return 0;
}

void day1() {
    printf("Day 1\n");

    FILE *input = fopen("../day1/input.txt", "r");

    if (input == NULL) {
        printf("File not found\n");
        exit(-1);
    }

    int *numbers = malloc(sizeof(int));

    if (numbers == NULL) {
        printf("Malloc failed\n");
        exit(-1);
    }

    int index = 0;

    int number;

    while (fscanf(input, "%d", &number) == 1) {
        numbers[index++] = number;

        numbers = realloc(numbers, sizeof(numbers) + sizeof(number));

        if (numbers == NULL) {
            printf("Malloc failed\n");
            exit(-1);
        }
    }

    printf("Result: %d", findResult(index, numbers));

    fclose(input);
    free(numbers);
}
