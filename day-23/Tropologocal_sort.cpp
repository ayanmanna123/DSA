#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <stack>
using namespace std;

// Helper DFS function for topological sort
void topoSort(int node, unordered_map<int, bool> &visited, stack<int> &s, unordered_map<int, list<int>> &adj) {
    visited[node] = true;

    for (auto neighbour : adj[node]) {
        if (!visited[neighbour]) {
            topoSort(neighbour, visited, s, adj);
        }
    }

    // Push to stack after visiting all neighbours (Postorder)
    s.push(node);
}

// Main function to perform topological sort
vector<int> topologicalSort(vector<vector<int>> &edges, int n, int e) {
    unordered_map<int, list<int>> adj;

    // Step 1: Create adjacency list
    for (int i = 0; i < e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }

    // Step 2: DFS Topo Sort for all components
    unordered_map<int, bool> visited;
    stack<int> s;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            topoSort(i, visited, s, adj);
        }
    }

    // Step 3: Store result from stack
    vector<int> ans;
    while (!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
}

// Example usage
int main() {
    int n = 6; // number of vertices
    int e = 6; // number of edges
    vector<vector<int>> edges = {
        {5, 0}, {5, 2},
        {4, 0}, {4, 1},
        {2, 3}, {3, 1}
    };

    vector<int> result = topologicalSort(edges, n, e);

    cout << "Topological Sort Order: ";
    for (int node : result) {
        cout << node << " ";
    }

    return 0;
}
