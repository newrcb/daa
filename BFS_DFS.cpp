#include <bits/stdc++.h>
using namespace std;
void bfs(char start, unordered_map<char, vector<char>>& graph) {
    unordered_map<char, bool> visited;
    queue<char> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        char current = q.front();
        q.pop();
        cout << current << " ";
        for (char neighbor : graph[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}
void dfs(char start, unordered_map<char, vector<char>>& graph, unordered_map<char, bool>& visited) {
    visited[start] = true;
    cout << start << " ";
    for (char neighbor : graph[start]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited);
        }
    }
}
int main() {
    unordered_map<char, vector<char>> graph;
    int edges;
    cout << "Enter the no.of edges: ";
    cin >> edges;
    cout << "Enter the edges :" << endl;
    for (int i = 0; i < edges; ++i) {
        char u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    char startNode;
    cout << "Enter the starting node: ";
    cin >> startNode;
    cout << "BFS from node " << startNode << ": ";
    bfs(startNode, graph);                                    
    cout << "DFS from node " << startNode << ": ";
    unordered_map<char, bool> visited;
    dfs(startNode, graph, visited);
    return 0;
}
