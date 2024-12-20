#include <bits/stdc++.h>
using namespace std;
int minDistance(int dist[], bool sptSet[], int V) {
    int min = INT_MAX, minIndex;
    for (int v = 0; v < V; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}
void dijkstra(int graph[][100], int V, int src) {
    int dist[V];        
    bool sptSet[V];   
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }
    dist[src] = 0;
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet, V);
        sptSet[u] = true;
        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++) {
        cout << i << " \t\t " << dist[i] << endl;
    }
}
int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;
    int graph[100][100];
    cout << "Enter the adjacency matrix (0 for no connection):" << endl;
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            cin >> graph[i][j];
        }
    }
    int src;
    cout << "Enter the source vertex: ";
    cin >> src;
    dijkstra(graph, V, src);
    return 0;
}
