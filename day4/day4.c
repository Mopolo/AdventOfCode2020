#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "day4.h"
#include "../common/strings.h"

PairList parsePairs(char *string) {
    PairList list = {.size = 0};

    list.pairs = malloc(sizeof(Field));

    //char* trimed = trim(string);

    int index = 0;
    char **parts = split(string, " ");
    //return list;
    char **rawPair;

    for (char *c = *parts; c; c = *++parts) {
        list.pairs = realloc(list.pairs, (index + 1) * sizeof(Field));

        rawPair = split(*parts, ":");

        list.pairs[index].key = rawPair[0];
        list.pairs[index].val = rawPair[1];
        list.size++;

        index++;
    }

    return list;
}

void day4() {
    FILE *input = fopen("../day4/input.txt", "r");

    if (input == NULL) {
        printf("File not found\n");
        exit(-1);
    }

    PairList *passports = malloc(sizeof(PairList));

    passports[0].size = 0;
    passports[0].pairs = malloc(sizeof(Field));

    PairList loopList;

    Field *fields = malloc(sizeof(Field));
    unsigned size = 0;

    char *line = NULL;
    size_t len = 0;

    unsigned lineNumber = 0;
    unsigned quantityValid = 0;

    while (getline(&line, &len, input) != -1) {
        char *trimed = trim(line);

        if (*trimed == 0) {
            printf("Passport (%d): ", lineNumber);

            unsigned fieldsNotCid = 0;
            unsigned quantity = size;

            unsigned quantity_byr = 0;
            unsigned quantity_iyr = 0;
            unsigned quantity_eyr = 0;
            unsigned quantity_hgt = 0;
            unsigned quantity_hcl = 0;
            unsigned quantity_ecl = 0;
            unsigned quantity_pid = 0;
            unsigned quantity_cid = 0;

            while (quantity > 0) {
                printf("%s:%s ", fields[quantity].key, fields[quantity].val);

                if (strcmp(fields[quantity].key, "byr") == 0) {
                    quantity_byr++;
                }

                if (strcmp(fields[quantity].key, "iyr") == 0) {
                    quantity_iyr++;
                }

                if (strcmp(fields[quantity].key, "eyr") == 0) {
                    quantity_eyr++;
                }

                if (strcmp(fields[quantity].key, "hgt") == 0) {
                    quantity_hgt++;
                }

                if (strcmp(fields[quantity].key, "hcl") == 0) {
                    quantity_hcl++;
                }

                if (strcmp(fields[quantity].key, "ecl") == 0) {
                    quantity_ecl++;
                }

                if (strcmp(fields[quantity].key, "pid") == 0) {
                    quantity_pid++;
                }

                if (strcmp(fields[quantity].key, "cid") == 0) {
                    quantity_cid++;
                }

                quantity--;
            }

            printf("\n");

            if (quantity_byr == 1
                && quantity_iyr == 1
                && quantity_eyr == 1
                && quantity_hgt == 1
                && quantity_hcl == 1
                && quantity_ecl == 1
                && quantity_pid == 1
                && (quantity_cid == 1 || quantity_cid == 0)
            ) {
                quantityValid++;
            }

            fields = realloc(fields, sizeof(Field));
            size = 0;
            lineNumber++;

            continue;
        }

        loopList = parsePairs(trimed);

        for (int i = 0; i < loopList.size; i++) {
            size++;
            fields = realloc(fields, (size + 1) * sizeof(Field));

            fields[size] = loopList.pairs[i];
        }

        lineNumber++;
    }

    printf("\nValid: %d\n", quantityValid);

    fclose(input);
}
