#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100; // Maximum number of vertices
int graph[MAXN][MAXN];
int numVertices, numColors;
int color[MAXN];

bool isSafe(int v, int c) {
    for (int i = 0; i < numVertices; i++) {
        if (graph[v][i] && color[i] == c) {
            return false;
        }
    }
    return true;
}

bool graphColoring(int v) {
    if (v == numVertices) {
        return true;
    }
    for (int c = 1; c <= numColors; c++) {
        if (isSafe(v, c)) {
            color[v] = c;
            if (graphColoring(v + 1)) {
                return true;
            }
            color[v] = 0;
        }
    }
    return false;
}

int main() {
    cout << "Enter the number of vertices: ";
    cin >> numVertices;
    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            cin >> graph[i][j];
        }
    }
    cout << "Enter the number of colors: ";
    cin >> numColors;

    for (int i = 0; i < numVertices; i++) {
        color[i] = 0;
    }

    if (graphColoring(0)) {
        cout << "Graph can be colored with " << numColors << " colors:\n";
        for (int i = 0; i < numVertices; i++) {
            cout << "Vertex " << i << " is colored with color " << color[i] << "\n";
        }
    } else {
        cout << "Graph cannot be colored with " << numColors << " colors.\n";
    }

    return 0;
}
