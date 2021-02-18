// Visualize: https://www.cs.usfca.edu/~galles/visualization/BFS.html

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph
{
private:
    int V;
    vector<int> *adj;
public:
    Graph(int _V);
    void addEdge(int u, int v);
    void BFS(int u);
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

void Graph::BFS(int u)
{
    bool visited[V];
    for(int i = 0; i < V; i++)
    {
        visited[i] = false;
    }
    queue<int> myQueue;
    visited[u] = true;
    myQueue.push(u);
    while (!myQueue.empty())
    {
        u = myQueue.front();
        cout << u << " ";
        myQueue.pop();
        vector<int>::iterator itr;
        for (itr = adj[u].begin(); itr != adj[u].end(); itr++)
        {
            if (!visited[*itr])
            {
                visited[*itr] = true;
                myQueue.push(*itr);
            }
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
    g.BFS(0);
}
