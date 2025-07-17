#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPathDirected(vector<pair<int, int>> edges, int n, int m, int s, int t) {
    // Create adjacency list (Directed graph)
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);  // Only one direction
    }

    // Do BFS
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    queue<int> q;

    q.push(s);
    visited[s] = true;

    while (!q.empty()) {
        int front = q.front();
        q.pop();

        for (auto i : adj[front]) {
            if (!visited[i]) {
                visited[i] = true;
                parent[i] = front;
                q.push(i);
            }
        }
    }

    // If target not visited → no path
    if (!visited[t]) {
        return {}; // Return empty vector if no path exists
    }

    // Prepare shortest path
    vector<int> ans;
    int currentNode = t;
    ans.push_back(t);

    while (currentNode != s) {
        currentNode = parent[currentNode];
        ans.push_back(currentNode);
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    int n = 6, m = 7;
    vector<pair<int, int>> edges = {
        {0, 1}, {0, 2}, {1, 3}, {2, 4}, {3, 5}, {4, 5}, {1, 4}
    };

    int s = 0, t = 5;

    vector<int> path = shortestPathDirected(edges, n, m, s, t);

    if (path.empty()) {
        cout << "No path exists!" << endl;
    } else {
        cout << "Shortest Path: ";
        for (auto node : path) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
