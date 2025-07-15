#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

bool checkCycleDFS(int node, unordered_map<int, bool>& visited,
                   unordered_map<int, bool>& dfsVisited,
                   unordered_map<int, list<int>>& adj) {
    visited[node] = true;
    dfsVisited[node] = true;

    for (auto neighbour : adj[node]) {
        if (!visited[neighbour]) {
            bool cycleDetected = checkCycleDFS(neighbour, visited, dfsVisited, adj);
            if (cycleDetected)
                return true;
        } else if (dfsVisited[neighbour]) {
            // Back edge found, cycle exists
            return true;
        }
    }

    dfsVisited[node] = false; // Backtrack
    return false;
}

bool detectCycleInDirectedGraph(int n, vector<pair<int, int>>& edges) {
    // Step 1: Create adjacency list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
    }

    // Step 2: Call DFS for all components
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            bool cycleFound = checkCycleDFS(i, visited, dfsVisited, adj);
            if (cycleFound)
                return true;
        }
    }

    return false;
}

// Driver Code Example
int main() {
    int n = 4; // number of nodes
    vector<pair<int, int>> edges = {
        {1, 2},
        {2, 3},
        {3, 4},
        {4, 2} // This edge creates a cycle
    };

    if (detectCycleInDirectedGraph(n, edges)) {
        cout << "Cycle Detected" << endl;
    } else {
        cout << "No Cycle Found" << endl;
    }

    return 0;
}
