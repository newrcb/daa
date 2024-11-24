#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Function to find the root of a vertex (with path compression)
int find(vector<int>& parent, int v) {
    if (parent[v] != v)
        parent[v] = find(parent, parent[v]);
    return parent[v];
}

// Function to perform the union of two sets
void unionSets(vector<int>& parent, vector<int>& rank, int u, int v) {
    int rootU = find(parent, u);
    int rootV = find(parent, v);

    if (rootU != rootV) {
        if (rank[rootU] > rank[rootV]) parent[rootV] = rootU;
        else if (rank[rootU] < rank[rootV]) parent[rootU] = rootV;
        else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
}

int kruskal(vector<Edge>& edges, int n) {
    int mstWeight = 0;
    vector<int> parent(n), rank(n, 0);

    // Initialize parent array (each vertex is its own parent)
    for (int i = 0; i < n; i++) parent[i] = i;

    // Sort edges by weight
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) { return a.weight < b.weight; });

    int edgeCount = 0;

    // Process edges in increasing weight
    for (const auto& edge : edges) {
        int rootSrc = find(parent, edge.src);
        int rootDest = find(parent, edge.dest);

        // If they belong to different sets, include the edge in MST
        if (rootSrc != rootDest) {
            unionSets(parent, rank, rootSrc, rootDest);
            mstWeight += edge.weight;
            edgeCount++;
            cout << "Edge included in MST: (" << edge.src << ", " << edge.dest << ") with weight " << edge.weight << endl;

            if (edgeCount == n - 1) break; // MST is complete
        }
    }

    return mstWeight;
}

int main() {
    int n, e;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> e;

    vector<Edge> edges(e);
    cout << "Enter the edges (source, destination, weight):" << endl;
    for (int i = 0; i < e; i++) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
        // Convert to 0-based indexing
        edges[i].src--;
        edges[i].dest--;
    }

    cout << "Finding Minimum Spanning Tree using Kruskal's Algorithm:" << endl;
    int mstWeight = kruskal(edges, n);

    if (mstWeight != -1) {
        cout << "Total weight of MST: " << mstWeight << endl;
    }

    return 0;
}
