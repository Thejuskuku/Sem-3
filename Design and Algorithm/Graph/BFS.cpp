#include <iostream>
#include <queue>
using namespace std;

#define MAX_V 100 // Maximum number of vertices

// Function for Breadth-First Search
void BFS(int start, int graph[MAX_V][MAX_V], int V) {
    bool visited[MAX_V] = {false};
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v << " ";

        // Enqueue all unvisited adjacent vertices of v
        for (int i = 0; i < V; i++) {
            if (graph[v][i] == 1 && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    int graph[MAX_V][MAX_V];
    cout << "Enter the adjacency matrix (row by row):\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    int startVertex;
    cout << "Enter the starting vertex for BFS: ";
    cin >> startVertex;

    cout << "Breadth First Traversal starting from vertex " << startVertex << ":\n";
    BFS(startVertex, graph, V);

    return 0;
}
