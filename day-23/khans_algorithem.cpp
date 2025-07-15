#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e) {
    unordered_map<int, list<int>> adj;

    // Step 1: Create adjacency list
    for (int i = 0; i < e; i++) {
        int u = edges[i][0];
        int vtx = edges[i][1];
        adj[u].push_back(vtx);
    }

    // Step 2: Find all indegrees
    vector<int> indegree(v, 0);
    for (auto i : adj) {
        for (auto j : i.second) {
            indegree[j]++;
        }
    }

    // Step 3: Push all 0-indegree vertices to queue
    queue<int> q;
    for (int i = 0; i < v; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    // Step 4: Do BFS
    vector<int> ans;
    while (!q.empty()) {
        int front = q.front();
        q.pop();

        // Store in answer
        ans.push_back(front);

        // Decrease indegree of neighbours
        for (auto neighbour : adj[front]) {
            indegree[neighbour]--;
            if (indegree[neighbour] == 0) {
                q.push(neighbour);
            }
        }
    }

    return ans;
}

// Example usage
int main() {
    int v = 6;
    int e = 6;
    vector<vector<int>> edges = {
        {5, 0}, {5, 2},
        {4, 0}, {4, 1},
        {2, 3}, {3, 1}
    };

    vector<int> result = topologicalSort(edges, v, e);

    cout << "Topological Sort Order: ";
    for (int node : result) {
        cout << node << " ";
    }

    return 0;
}

