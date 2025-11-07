#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

// Function to implement Dijkstra's Algorithm
void dijkstra(int V, vector<vector<pair<int, int>>> &adj, int src) {
    // Create a distance vector and initialize all distances as infinity
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    // Min-heap priority queue: {distance, vertex}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Push the source vertex with distance 0
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        // Skip if we already found a better path
        if (d > dist[u]) continue;

        // Explore all adjacent vertices
        for (auto &edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            // Relaxation step
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    // Print shortest distances
    cout << "\nVertex\tDistance from Source (" << src << ")\n";
    for (int i = 0; i < V; i++)
        cout << i << "\t" << dist[i] << "\n";
}

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<pair<int, int>>> adj(V);

    cout << "Enter edges (u v w) -> edge from u to v with weight w:\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // comment this line if graph is directed
    }

    int src;
    cout << "Enter source vertex: ";
    cin >> src;

    dijkstra(V, adj, src);

    return 0;
}
