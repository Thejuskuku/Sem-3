#include <iostream>
#include <stack>
using namespace std;

#define MAX_V 100 // Maximum number of vertices

// Function for iterative Depth First Search
void DFSIterative(int start, int graph[MAX_V][MAX_V], int V) {
    bool visited[MAX_V] = {false};
    stack<int> s;
    s.push(start);

    while (!s.empty()) {
        int v = s.top();
        s.pop();

        if (!visited[v]) {
            cout << v << " ";
            visited[v] = true;
        }

        // Push all unvisited adjacent vertices of v to the stack
        for (int i = V - 1; i >= 0; i--) {
            if (graph[v][i] == 1 && !visited[i]) {
                s.push(i);
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
    cout << "Enter the starting vertex for DFS: ";
    cin >> startVertex;

    cout << "Depth First Traversal starting from vertex " << startVertex << ":\n";
    DFSIterative(startVertex, graph, V);

    return 0;
}
