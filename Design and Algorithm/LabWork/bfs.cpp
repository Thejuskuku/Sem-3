#include <iostream>
#include <queue>
using namespace std;
#define MAX_VERTICES 100 

void bfs(int start, int adj[MAX_VERTICES][MAX_VERTICES], int n) {
    bool visited[MAX_VERTICES] = {false}; 
    queue<int> q; 

    visited[start] = true; 
    q.push(start); 

    while (!q.empty()) {
        int node = q.front(); 
        q.pop();
        cout << node << " "; 
        for (int i = 0; i < n; i++) {
            if (adj[node][i] == 1 && !visited[i]) {
                visited[i] = true; 
                q.push(i); 
            }
        }
    }
}

int main() {
    int n = 5; 
    int adj[MAX_VERTICES][MAX_VERTICES] = {0};
    adj[0][1] = 1; adj[0][2] = 1;
    adj[1][0] = 1; adj[1][3] = 1; adj[1][4] = 1;
    adj[2][0] = 1;
    adj[3][1] = 1;
    adj[4][1] = 1;

    cout << "BFS starting from node 0: ";
    bfs(0, adj, n); 
    
    return 0;
}

