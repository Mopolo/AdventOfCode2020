#ifndef ADVENTOFCODE2020_DAY3_H
#define ADVENTOFCODE2020_DAY3_H

typedef struct Point {
    int x;
    int y;
} Point;

typedef struct Map {
    int x;
    int y;
    int width;
    char **lines;
} Map;

void day3();

#endif //ADVENTOFCODE2020_DAY3_H
