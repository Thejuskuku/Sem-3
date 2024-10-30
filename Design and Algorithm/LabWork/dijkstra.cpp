#include <iostream>
#include <limits.h>

using namespace std;

// Function to find the vertex with the minimum distance value from the set of vertices not yet included in the shortest path tree
int minDistance(int dist[], bool sptSet[], int V) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to print the constructed distance array
void printSolution(int dist[], int V) {
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++) {
        cout << i << " \t\t\t\t" << dist[i] << endl;
    }
}

// Dijkstra's algorithm to find the shortest path in a graph represented by an adjacency matrix
void dijkstra(int graph[][100], int src, int V) { // Adjusted to use a fixed size for simplicity
    int dist[100]; // Fixed size array for distances
    bool sptSet[100]; // Fixed size array for shortest path tree set

    // Initialize distances and shortest path tree set
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }
    dist[src] = 0; // Distance from source to itself is always 0

    // Main loop
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet, V);
        sptSet[u] = true; // Mark the picked vertex as processed

        // Update the distance value of the neighboring vertices of the picked vertex
        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist, V);
}

int main() {
    int V;
    cout << "Enter the size of the matrix (n x n): ";
    cin >> V;

    // Declare a fixed size array for the graph (adjust size as necessary)
    int matrix[100][100]; // Adjust the size as needed
    cout << "Enter the elements of the matrix (0 for no edge):" << endl;

    // Input the adjacency matrix
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            cout << "Element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }

    cout << "The entered matrix is:" << endl;
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Call Dijkstra's algorithm starting from the source vertex (0 in this case)
    dijkstra(matrix, 0, V);

    return 0;
}

