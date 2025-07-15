#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

// DFS Helper Function
bool isCyclicDFS(int node, int parent,
                 unordered_map<int, bool> &visited,
                 unordered_map<int, list<int>> &adj) {
    visited[node] = true;

    for (auto neighbour : adj[node]) {
        if (!visited[neighbour]) {
            bool cycleDetected = isCyclicDFS(neighbour, node, visited, adj);
            if (cycleDetected)
                return true;
        }
        else if (neighbour != parent) {
            // Cycle found
            return true;
        }
    }

    return false;
}

// Main Cycle Detection Function
string cycleDetection(vector<vector<int>> &edges, int n, int m) {
    // Create adjacency list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Handle disconnected components
    unordered_map<int, bool> visited;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            bool ans = isCyclicDFS(i, -1, visited, adj);
            if (ans)
                return "Yes";
        }
    }

    return "No";
}

// Driver Code
int main() {
    // Example 1: Contains a cycle (0-1-2-0)
    vector<vector<int>> edges1 = {
        {0, 1},
        {1, 2},
        {2, 0},
        {3, 4}
    };
    int n1 = 5; // number of nodes
    int m1 = edges1.size();

    cout << "Graph 1: " << cycleDetection(edges1, n1, m1) << endl; // Output: Yes

    // Example 2: No cycle
    vector<vector<int>> edges2 = {
        {0, 1},
        {1, 2},
        {3, 4}
    };
    int n2 = 5;
    int m2 = edges2.size();

    cout << "Graph 2: " << cycleDetection(edges2, n2, m2) << endl; // Output: No

    return 0;
}
