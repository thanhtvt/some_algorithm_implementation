// Visualize: https://www.cs.usfca.edu/~galles/visualization/DFS.html

#include <iostream>
#include <vector>

using namespace std;

class Graph
{
private:
    // Number of vertices
    int V;
    vector<int> *adj;

    // A recursive function used by DFS
    void DFSUtil(int u, bool visited[]);

public:
    // Constructor
    Graph(int _V)
    {
        V = _V;
        adj = new vector<int>[V];
    }
    // Initialize edges
    void addEdge(int u, int v);

    void DFS(int u);
};

void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
}

void Graph::DFSUtil(int u, bool visited[])
{
    visited[u] = true;
    cout << u << " ";
    vector<int>::iterator itr;
    for (itr = adj[u].begin(); itr != adj[u].end(); itr++)
    {
        if (!visited[*itr])
        {
            DFSUtil(*itr, visited);
        }
    }
}

void Graph::DFS(int u)
{
    bool visited[V];
    for (int i = 0; i <= V; i++)
    {
        visited[i] = false;
    }
    DFSUtil(u, visited);
}

int main()
{
    int n, x, y;
    cin >> n;
    Graph g(n);
    while (cin >> x >> y)
    {
        g.addEdge(x, y);
    }
    g.DFS(0);
}
