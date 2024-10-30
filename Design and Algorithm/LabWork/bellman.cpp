#include <iostream>
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

    void bellmanFord(int src) {
        int* distance = new int[V];
        for (int i = 0; i < V; i++) {
            distance[i] = numeric_limits<int>::max();
        }
        distance[src] = 0;
        for (int i = 1; i <= V - 1; i++) {
            for (int j = 0; j < E; j++) {
                int u = edges[j].u;
                int v = edges[j].v;
                int weight = edges[j].weight;

                if (distance[u] != numeric_limits<int>::max() && 
                    distance[u] + weight < distance[v]) {
                    distance[v] = distance[u] + weight;
                }
            }
        }
        for (int j = 0; j < E; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int weight = edges[j].weight;

            if (distance[u] != numeric_limits<int>::max() && 
                distance[u] + weight < distance[v]) {
                cout << "Graph contains negative weight cycle\n";
                delete[] distance;
                return;
            }
        }
        cout << "Vertex Distance from Source\n";
        for (int i = 0; i < V; i++) {
            if (distance[i] == numeric_limits<int>::max()) {
                cout << i << "\t\t" << "Infinity\n";
            } else {
                cout << i << "\t\t" << distance[i] << "\n";
            }
        }

        delete[] distance;
    }
};

int main() {
    int V = 5; // Number of vertices
    int E = 8; // Number of edges
    Graph g(V, E);

    // Adding edges
    g.addEdge(0, 1, -1, 0);
    g.addEdge(0, 2, 4, 1);
    g.addEdge(1, 2, 3, 2);
    g.addEdge(1, 3, 2, 3);
    g.addEdge(1, 4, 2, 4);
    g.addEdge(3, 2, 5, 5);
    g.addEdge(3, 1, 1, 6);
    g.addEdge(4, 3, -3, 7);

    g.bellmanFord(0); // Starting from vertex 0

    return 0;
}

