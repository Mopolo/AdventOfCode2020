#ifndef ADVENTOFCODE2020_DAY2_H
#define ADVENTOFCODE2020_DAY2_H

typedef struct Line Line;
struct Line {
    char letter;
    int min;
    int max;
    char* password;
};

void day2();

#endif //ADVENTOFCODE2020_DAY2_H
