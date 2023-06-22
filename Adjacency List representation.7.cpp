#include <iostream>
#include <vector>

using namespace std;

// Function to check if the graph is a complete graph
bool isCompleteGraph(const vector<vector<int>>& graph) {
    int n = graph.size(); // Number of vertices

    // Check if every pair of distinct vertices is connected by an edge
    for (int u = 0; u < n; ++u) {
        for (int v = u + 1; v < n; ++v) {
            // If there is no edge between u and v, graph is not complete
            if (graph[u][v] == 0) {
                return false;
            }
        }
    }

    // All pairs of distinct vertices are connected by edges, graph is complete
    return true;
}

int main() {
    int numVertices;

    cout << "Enter the number of vertices: ";
    cin >> numVertices;

    vector<vector<int>> graph(numVertices, vector<int>(numVertices, 0)); // Graph representation as an adjacency matrix

    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            cin >> graph[i][j];
        }
    }

    bool isComplete = isCompleteGraph(graph);

    if (isComplete) {
        cout << "The graph is a complete graph.\n";
    } else {
        cout << "The graph is not a complete graph.\n";
    }

    return 0;
}
