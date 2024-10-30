#include <iostream>
#include <algorithm>
#include <limits>

using namespace std;

struct Edge {
    int u, v, weight;
};

class Graph {
public:
    int V, E;
    Edge* edges;

    Graph(int V, int E) {
        this->V = V;
        this->E = E;
        edges = new Edge[E];
    }

    ~Graph() {
        delete[] edges;
    }

    void addEdge(int u, int v, int weight, int index) {
        edges[index].u = u;
        edges[index].v = v;
        edges[index].weight = weight;
    }

    int find(int parent[], int i) {
        if (parent[i] == -1) {
            return i;
        }
        return find(parent, parent[i]);
    }

    void unionSet(int parent[], int x, int y) {
        int xset = find(parent, x);
        int yset = find(parent, y);
        if (xset != yset) {
            parent[xset] = yset;
        }
    }

    void kruskalMST() {
        Edge* result = new Edge[V - 1]; // To store the resultant MST
        int* parent = new int[V];
        for (int i = 0; i < V; i++) {
            parent[i] = -1;
        }

        // Sort edges based on weight
        sort(edges, edges + E, [](Edge a, Edge b) {
            return a.weight < b.weight;
        });

        int e = 0; // Count of edges in MST
        int i = 0; // Initial index of sorted edges
        while (e < V - 1) {
            Edge next_edge = edges[i++];
            int x = find(parent, next_edge.u);
            int y = find(parent, next_edge.v);

            // If including this edge doesn't cause a cycle
            if (x != y) {
                result[e++] = next_edge;
                unionSet(parent, x, y);
            }
        }

        // Print the edges of the MST
        cout << "Edges in the Minimum Spanning Tree:\n";
        for (i = 0; i < e; i++) {
            cout << result[i].u << " -- " << result[i].v << " == " << result[i].weight << endl;
        }

        delete[] result;
        delete[] parent;
    }
};

int main() {
    int V = 4; // Number of vertices
    int E = 5; // Number of edges
    Graph g(V, E);

    // Adding edges
    g.addEdge(0, 1, 10, 0);
    g.addEdge(0, 2, 6, 1);
    g.addEdge(0, 3, 5, 2);
    g.addEdge(1, 3, 15, 3);
    g.addEdge(2, 3, 4, 4);

    g.kruskalMST(); // Finding MST

    return 0;
}

