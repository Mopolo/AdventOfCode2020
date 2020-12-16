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
//            printf("Passport (%d): ", lineNumber);

            unsigned fieldsNotCid = 0;
            unsigned quantity = size;

            unsigned valid_byr = 0;
            unsigned valid_iyr = 0;
            unsigned valid_eyr = 0;
            unsigned valid_hgt = 0;
            unsigned valid_hcl = 0;
            unsigned valid_ecl = 0;
            unsigned valid_pid = 0;
            unsigned valid_cid = 0;

            while (quantity > 0) {
//                printf("%s:%s ", fields[quantity].key, fields[quantity].val);

                if (strcmp(fields[quantity].key, "byr") == 0) {
                    long year = strtol(fields[quantity].val, (char **)NULL, 10);

                    if (year >= 1920 && year <= 2002) {
                        valid_byr++;
                    }
                }

                if (strcmp(fields[quantity].key, "iyr") == 0) {
                    long year = strtol(fields[quantity].val, (char **)NULL, 10);

                    if (year >= 2010 && year <= 2020) {
                        valid_iyr++;
                    }
                }

                if (strcmp(fields[quantity].key, "eyr") == 0) {
                    long year = strtol(fields[quantity].val, (char **)NULL, 10);

                    if (year >= 2020 && year <= 2030) {
                        valid_eyr++;
                    }
                }

                if (strcmp(fields[quantity].key, "hgt") == 0) {
                    size_t length = strlen(fields[quantity].val);

                    char s[3];
                    char v[length - 2];

                    memcpy(s, &fields[quantity].val[length - 2], 3);
                    s[2] = '\0';

                    memcpy(v, &fields[quantity].val[0], length - 2);
                    v[length - 2] = '\0';

                    long val = strtol(v, (char **)NULL, 10);

                    printf("HGT:%s %ld %lu\n", s, val, length);

                    unsigned min = 150;
                    unsigned max = 193;
                    if (strcmp(s, "in") == 0) {
                        min = 59;
                        max = 76;
                    }

                    if (val >= min && val <= max) {
                        valid_hgt++;
                    }
                }

                if (strcmp(fields[quantity].key, "hcl") == 0) {
                    if (fields[quantity].val[0] == '#'
                        && strlen(fields[quantity].val) == 7
                    ) {
                        valid_hcl++;
                    }
                }

                if (strcmp(fields[quantity].key, "ecl") == 0
                    && (
                        strcmp(fields[quantity].val, "amb") == 0
                        || strcmp(fields[quantity].val, "blu") == 0
                        || strcmp(fields[quantity].val, "brn") == 0
                        || strcmp(fields[quantity].val, "gry") == 0
                        || strcmp(fields[quantity].val, "grn") == 0
                        || strcmp(fields[quantity].val, "hzl") == 0
                        || strcmp(fields[quantity].val, "oth") == 0
                    )
                ) {
                    valid_ecl++;
                }

                if (strcmp(fields[quantity].key, "pid") == 0) {
                    if (strlen(fields[quantity].val) == 9) {
                        valid_pid++;
                    }
                }

                if (strcmp(fields[quantity].key, "cid") == 0) {
                    valid_cid++;
                }

                quantity--;
            }

            printf("\n");

            if (valid_byr == 1
                && valid_iyr == 1
                && valid_eyr == 1
                && valid_hgt == 1
                && valid_hcl == 1
                && valid_ecl == 1
                && valid_pid == 1
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
