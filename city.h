#ifndef CITY_H
#define CITY_H

#include <graphics.h>

struct City {
    int id;
    int x, y;
    char name[20];
};

extern City cities[];
extern int adjacencyMatrix[10][10][3]; // Max 10 cities, distance/time/cost

#endif
