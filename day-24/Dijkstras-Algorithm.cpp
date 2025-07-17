#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Create adjacency list
    unordered_map<int, list<pair<int, int>>> adj;
    for (int i = 0; i < vec.size(); i++) {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w)); // For undirected graph
    }

    // Distance array
    vector<int> dist(vertices);
    for (int i = 0; i < vertices; i++) {
        dist[i] = INT_MAX;
    }

    // Set to store {distance, node}
    set<pair<int, int>> st;

    // Initialize source
    dist[source] = 0;
    st.insert(make_pair(0, source));

    while (!st.empty()) {
        // Fetch top record
        auto top = *(st.begin());
        int nodeDistance = top.first;
        int topNode = top.second;

        // Remove top record now
        st.erase(st.begin());

        // Traverse neighbors
        for (auto neighbour : adj[topNode]) {
            if (nodeDistance + neighbour.second < dist[neighbour.first]) {
                // Find record in set
                auto record = st.find(make_pair(dist[neighbour.first], neighbour.first));
                // If found, erase it
                if (record != st.end()) {
                    st.erase(record);
                }

                // Update distance
                dist[neighbour.first] = nodeDistance + neighbour.second;
                // Insert updated record
                st.insert(make_pair(dist[neighbour.first], neighbour.first));
            }
        }
    }

    return dist;
}

int main() {
    int vertices = 5;
    int edges = 6;

    vector<vector<int>> vec = {
        {0, 1, 2},
        {0, 2, 4},
        {1, 2, 1},
        {1, 3, 7},
        {2, 4, 3},
        {3, 4, 2}
    };

    int source = 0;
    vector<int> ans = dijkstra(vec, vertices, edges, source);

    cout << "Shortest distances from source " << source << ": ";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
