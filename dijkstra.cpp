#include "city.h"
#include <bits/stdc++.h>
using namespace std;

void dijkstra(int source, int destination, int criterion, int path[], int &pathLength, int &total) {
    const int INF = INT_MAX;
    int n = 10; // Number of cities
    vector<int> dist(n, INF);
    vector<bool> visited(n, false);
    vector<int> prev(n, -1);
    dist[source] = 0;

    for (int i = 0; i < n - 1; i++) {
        int u = -1;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }

        if (dist[u] == INF) break;
        visited[u] = true;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && adjacencyMatrix[u][v][criterion] > 0) {
                int alt = dist[u] + adjacencyMatrix[u][v][criterion];
                if (alt < dist[v]) {
                    dist[v] = alt;
                    prev[v] = u;
                }
            }
        }
    }

    total = dist[destination];
    if (total == INF) {  // If there's no path to the destination
        pathLength = 0;  // No valid path found
        return;
    }
    pathLength = 0;
    for (int at = destination; at != -1; at = prev[at]) {
        path[pathLength++] = at;
    }
    reverse(path, path + pathLength);
}
