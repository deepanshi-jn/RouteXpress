#include "city.h"
#include <graphics.h>
#include <bits/stdc++.h>
using namespace std;

void drawMap() {
    setcolor(WHITE);
    for (int i = 0; i < 10; i++) {
        circle(cities[i].x, cities[i].y, 20);
        outtextxy(cities[i].x - 10, cities[i].y - 10, cities[i].name);

        for (int j = 0; j < 10; j++) {
            if (adjacencyMatrix[i][j][0] > 0) {
                line(cities[i].x, cities[i].y, cities[j].x, cities[j].y);
            }
        }
    }
}

void animateBus(int path[], int pathLength) {
    setcolor(RED);
    drawMap();
    for (int i = 0; i < pathLength - 1; i++) {
        int x1 = cities[path[i]].x;
        int y1 = cities[path[i]].y;
        int x2 = cities[path[i + 1]].x;
        int y2 = cities[path[i + 1]].y;
        for (float t = 0; t <= 1; t += 0.01) {
            int x = x1 + t * (x2 - x1);
            int y = y1 + t * (y2 - y1);
            // Clear the previous bus position (this is optional but will avoid leaving traces of the bus)
            setcolor(BLACK);
            rectangle(x1 - 5, y1 - 5, x1 + 5, y1 + 5); // Clear previous bus position

            // Draw the bus at the new position
            setcolor(RED);
            rectangle(x - 5, y - 5, x + 5, y + 5); // Draw the bus

            // Delay for a smooth animation
            delay(50);
        }
    }
}
