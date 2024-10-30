#include <iostream>
#include <stack>

using namespace std;

#define V 6 

void DFSIterative(int start, int graph[V][V]) {
    bool visited[V] = {false}; 
    stack<int> s;
    s.push(start);

    while (!s.empty()) {
        int v = s.top();
        s.pop();
        if (!visited[v]) {
            visited[v] = true;
            cout << v << " ";
        }
        for (int i = V - 1; i >= 0; i--) { 
            if (graph[v][i] == 1 && !visited[i]) {
                s.push(i);
            }
        }
    }
}

int main() {
    int graph[V][V] = {
        {0, 1, 1, 0, 0, 0}, 
        {1, 0, 0, 1, 1, 0}, 
        {1, 0, 0, 0, 0, 0}, 
        {0, 1, 0, 0, 0, 1}, 
        {0, 1, 0, 0, 0, 0}, 
        {0, 0, 0, 1, 0, 0}  
    };
    cout << "Depth First Traversal starting from vertex 0:\n";
    DFSIterative(0, graph);

    return 0;
}

