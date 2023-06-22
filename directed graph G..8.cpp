#include <iostream>
#include <vector>

using namespace std;


void computeDegrees(const vector<vector<int>>& graph, vector<int>& inDegree, vector<int>& outDegree) {
    int n = graph.size(); 

    
    inDegree.assign(n, 0);
    outDegree.assign(n, 0);

    
    for (int u = 0; u < n; ++u) {
        for (int v : graph[u]) {
            ++outDegree[u];     
            ++inDegree[v];      
        }
    }
}

int main() {
    int numVertices, numEdges;

    cout << "Enter the number of vertices: ";
    cin >> numVertices;

    cout << "Enter the number of edges: ";
    cin >> numEdges;

    vector<vector<int>> graph(numVertices); 

    cout << "Enter the edges (source -> destination):\n";
    for (int i = 0; i < numEdges; ++i) {
        int source, destination;
        cin >> source >> destination;
        graph[source].push_back(destination);
    }

    vector<int> inDegree, outDegree;
    computeDegrees(graph, inDegree, outDegree);

    
    cout << "\nVertex\tIn-Degree\tOut-Degree\n";
    for (int u = 0; u < numVertices; ++u) {
        cout << u << "\t" << inDegree[u] << "\t\t" << outDegree[u] << "\n";
    }

    return 0;
}
