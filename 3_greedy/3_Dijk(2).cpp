#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii; // (cost, node)

// Function to implement Dijkstra's algorithm
void dijkstra(int src, int V, vector<vector<pii>> &adj) {
    vector<int> dist(V, INT_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq; // Min-heap

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int currDist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        for (auto &neighbor : adj[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (dist[v] > currDist + weight) {
                dist[v] = currDist + weight;
                pq.push({dist[v], v});
            }
        }
    }

    // Display shortest distances from source
    cout << "Vertex\tDistance from Source " << src << "\n";
    for (int i = 0; i < V; ++i)
        cout << i << "\t\t" << dist[i] << "\n";
}

int main() {
    int V = 5; // Number of vertices
    vector<vector<pii>> adj(V); // adjacency list (node, weight)

    // Sample undirected weighted graph
    adj[0].push_back({1, 10});
    adj[0].push_back({4, 5});
    adj[1].push_back({0, 10});
    adj[1].push_back({2, 1});
    adj[1].push_back({4, 2});
    adj[2].push_back({1, 1});
    adj[2].push_back({3, 4});
    adj[3].push_back({2, 4});
    adj[3].push_back({4, 2});
    adj[4].push_back({0, 5});
    adj[4].push_back({1, 2});
    adj[4].push_back({3, 2});

    int source = 0;
    dijkstra(source, V, adj);

    return 0;
}
