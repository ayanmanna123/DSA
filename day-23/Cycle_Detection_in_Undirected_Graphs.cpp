#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

// Function to check if a cycle exists using BFS
bool isCyclicBFS(int src, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj) {
    unordered_map<int, int> parent;
    parent[src] = -1;
    visited[src] = true;

    queue<int> q;
    q.push(src);

    while (!q.empty()) {
        int front = q.front();
        q.pop();

        for (auto neighbour : adj[front]) {
            if (visited[neighbour] && neighbour != parent[front]) {
                // Cycle detected
                return true;
            } else if (!visited[neighbour]) {
                q.push(neighbour);
                visited[neighbour] = true;
                parent[neighbour] = front;
            }
        }
    }

    return false;
}

// Main function to detect cycle in an undirected graph
string cycleDetection(vector<vector<int>> &edges, int n, int m) {
    unordered_map<int, list<int>> adj;

    // Create adjacency list
    for (int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, bool> visited;

    // Handle disconnected components
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            bool ans = isCyclicBFS(i, visited, adj);
            if (ans == true) {
                return "Yes";  // Cycle exists
            }
        }
    }

    return "No";  // No cycle found
}

// Example usage
int main() {
    int n = 5; // number of nodes
    int m = 5; // number of edges

    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {2, 3},
        {3, 4},
        {4, 0}  // This edge creates a cycle
    };

    cout << "Cycle present? " << cycleDetection(edges, n, m) << endl;

    return 0;
}
