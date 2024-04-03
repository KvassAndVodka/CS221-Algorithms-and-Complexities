#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>
#include <utility>
using namespace std;

const int INF = INT_MAX;

struct Edge {
    char dest;
    int weight;
    Edge(char d, int w) : dest(d), weight(w) {}
};

void dijkstra(const unordered_map<char, vector<Edge>>& graph, char source) {
    unordered_map<char, int> distance;
    unordered_map<char, char> parent;
    priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> pq;

    for (const auto& pair : graph) {
        char vertex = pair.first;
        distance[vertex] = INF;
        parent[vertex] = '\0';
    }

    distance[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        char u = pq.top().second;
        int dist_u = pq.top().first;
        pq.pop();

        if (dist_u > distance[u]) continue;

        for (const auto& edge : graph.at(u)) {
            char v = edge.dest;
            int w = edge.weight;
            if (distance[v] > distance[u] + w) {
                distance[v] = distance[u] + w;
                parent[v] = u;
                pq.push({distance[v], v});
            }
        }
    }

    cout << "Shortest paths (source: " << source << "):" << endl;
    for (const auto& pair : distance) {
        if (pair.first != source) {
            cout << source << "-" << pair.first << ": ";
            if (pair.second == INF) {
                cout << "No path exists" << endl;
            } else {
                cout << pair.second << " (via ";
                char current = pair.first;
                while (parent[current] != '\0') {
                    cout << parent[current];
                    if (parent[parent[current]] != '\0') {
                        cout << ", ";
                    }
                    current = parent[current];
                }
                cout << ")" << endl;
            }
        }
    }
}

int main() {
    unordered_map<char, vector<Edge>> graph = {
        {'A', {{'B', 2}, {'C', 4}}},
        {'B', {{'D', 3}}},
        {'C', {{'D', 1}, {'E', 7}}},
        {'D', {}},
        {'E', {}}
    };

    dijkstra(graph, 'A');

    return 0;
}
