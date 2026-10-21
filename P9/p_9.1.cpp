#include <iostream>
#include <queue>
using namespace std;

int graph[10][10], visited[10], n;

void DFS(int v) {
    visited[v] = 1;
    cout << v << " ";

    for (int i = 0; i < n; i++) {
        if (graph[v][i] && !visited[i])
            DFS(i);
    }
}

void BFS(int start) {
    queue<int> q;
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    q.push(start);
    visited[start] = 1;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v << " ";

        for (int i = 0; i < n; i++) {
            if (graph[v][i] && !visited[i]) {
                visited[i] = 1;
                q.push(i);
            }
        }
    }
}

int main() {
    int edges, u, v, start;
    cin >> n >> edges;

    for (int i = 0; i < edges; i++) {
        cin >> u >> v;
        graph[u][v] = graph[v][u] = 1;
    }

    cin >> start;

    cout << "DFS: ";
    for (int i = 0; i < n; i++)
        visited[i] = 0;
    DFS(start);

    cout << "\nBFS: ";
    BFS(start);
    cout << "\n";

    return 0;
}
