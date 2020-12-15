#ifndef ADVENTOFCODE2020_DAY4_H
#define ADVENTOFCODE2020_DAY4_H

typedef struct {
    char* key;
    char* val;
} Field;

typedef struct {
    Field* pairs;
    unsigned size;
} PairList;

void day4();

#endif //ADVENTOFCODE2020_DAY4_H
