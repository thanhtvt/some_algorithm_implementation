#include <iostream>
#include <vector>

using namespace std;

class Graph
{
private:
    // Number of vertices
    int V;
    vector<int> *adj;
    void DFSUtil(int u, bool visited[]);

public:
    Graph(int _V);
    void addEdge(int u, int v);
    void DFS();
};

Graph::Graph(int _V)
{
    V = _V;
    adj = new vector<int>[V];
}

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

void Graph::DFS()
{
    bool visited[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            DFSUtil(i, visited);
        }
    }
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
    g.DFS();
}
