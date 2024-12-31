#include "city.h"
#include <graphics.h>
#include <bits/stdc++.h>
using namespace std;

void dijkstra(int source, int destination, int criterion, int path[], int &pathLength, int &total);
void drawMap();
void animateBus(int path[], int pathLength);

City cities[] = {
    {0, 100, 100, "A"},
    {1, 200, 100, "B"},
    {2, 300, 100, "C"},
    {3, 100, 200, "D"},
    {4, 200, 200, "E"},
    {5, 300, 200, "F"},
    {6, 100, 300, "G"},
    {7, 200, 300, "H"},
    {8, 300, 300, "I"},
    {9, 400, 300, "J"}
};

int adjacencyMatrix[10][10][3] = {
    // Distance, Time, Cost
    {{0, 0, 0}, {50, 5, 10}, {100, 10, 20}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}}, // City 0
    {{50, 5, 10}, {0, 0, 0}, {30, 3, 8}, {70, 7, 15}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}}, // City 1
    {{100, 10, 20}, {30, 3, 8}, {0, 0, 0}, {50, 5, 12}, {60, 6, 14}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}}, // City 2
    {{0, 0, 0}, {70, 7, 15}, {50, 5, 12}, {0, 0, 0}, {40, 4, 12}, {80, 8, 18}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}}, // City 3
    {{0, 0, 0}, {0, 0, 0}, {60, 6, 14}, {40, 4, 12}, {0, 0, 0}, {90, 9, 22}, {30, 3, 7}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}}, // City 4
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {80, 8, 18}, {90, 9, 22}, {0, 0, 0}, {25, 2, 5}, {50, 5, 10}, {0, 0, 0}, {0, 0, 0}}, // City 5
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {30, 3, 7}, {25, 2, 5}, {0, 0, 0}, {50, 5, 10}, {0, 0, 0}, {0, 0, 0}}, // City 6
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {50, 5, 10}, {50, 5, 10}, {0, 0, 0}, {35, 3, 8}, {0, 0, 0}}, // City 7
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {35, 3, 8}, {0, 0, 0}, {45, 4, 10}}, // City 8
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {45, 4, 10}, {0, 0, 0}}  // City 9
};

int main() {
    int gd = DETECT, gm;
    int source, destination, criterion;

    cout << "Cities: " << endl;
    for (int i = 0; i < 10; i++) {
        cout << cities[i].id << ": " << cities[i].name << endl;
    }

    cout << "Enter Source City ID: ";
    cin >> source;
    cout << "Enter Destination City ID: ";
    cin >> destination;
    cout << "Optimize by (0: Distance, 1: Time, 2: Cost): ";
    cin >> criterion;

    int path[10], pathLength = 0, total = 0;
    dijkstra(source, destination, criterion, path, pathLength, total);

    if (pathLength == 0) {
        cout << "No valid path found!" << endl;
        return 0;
    }

    cout << "Shortest Path: ";
    for (int i = 0; i < pathLength; i++) {
        cout << cities[path[i]].name << " ";
    }
    cout << "\nTotal: " << total << endl;

    initgraph(&gd, &gm, nullptr);
    drawMap();
    animateBus(path, pathLength);
    closegraph();

    return 0;
}
