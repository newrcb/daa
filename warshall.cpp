#include <iostream>
#include <vector>
using namespace std;

// Function to implement Warshall's algorithm
void warshallAlgorithm(vector<vector<int>>& graph, int n) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j]);
            }
        }
    }
}

// Function to print the matrix
void printMatrix(const vector<vector<int>>& graph, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));
    cout << "Enter the adjacency matrix (row by row):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    cout << "Original Graph (Adjacency Matrix):\n";
    printMatrix(graph, n);

    warshallAlgorithm(graph, n);

    cout << "Transitive Closure (Reachability Matrix):\n";
    printMatrix(graph, n);

    return 0;
}
