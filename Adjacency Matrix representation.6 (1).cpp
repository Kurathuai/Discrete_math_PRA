#include <iostream>
#include <vector>

using namespace std;


bool isCompleteGraph(const vector<vector<int>>& graph) {
    int n = graph.size(); // Number of vertices


    for (int u = 0; u < n; ++u) {
        for (int v = u + 1; v < n; ++v) {
        
            if (graph[u][v] == 0) {
                return false;
            }
        }
    }


    return true;
}

int main() {
    int numVertices;

    cout << "Enter the number of vertices: ";
    cin >> numVertices;

    vector<vector<int>> graph(numVertices, vector<int>(numVertices, 0)); 

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
