#include <iostream>
#include <climits>

using namespace std;

int** inputEdges(int V, int E)
{
    int** table = new int*[V + 1];
    for (int i = 0; i <= V; i++)
    {
        table[i] = new int[V + 1];
    }
    for (int i = 0; i <= V; i++)
    {
        for (int j = 0; j <= V; j++)
        {
            table[i][j] = 0;
        }
    }
    int u, v, w;
    for (int i = 0; i < E; i++)
    {
        cin >> u >> v >> w;
        table[u][v] = w;
        table[v][u] = w;
    }
    return table;
}

void free(int** p, int n)
{
    for (int i = 0; i <= n; i++)
    {
        delete [] p[i];
    }
    delete [] p;
}

int minVertex(int dist[], bool visited[], int V)
{
    int myMin = INT_MAX, minIndex;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i] && dist[i] <= myMin)
        {
            minIndex = i;
            myMin = dist[i];
        }
    }
    return minIndex;
}

void dijkstra (int** edges, int V, int src, int dest)
{
    int dist[V];
    bool visited[V];
    for (int i = 0; i <= V; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = false;
    }
    dist[src] = 0;
    for (int i = 0; i <= V; i++)
    {
        int u = minVertex(dist, visited, V);
        visited[u] = true;
        for (int v = 0; v <= V; v++)
        {
            if (!visited[v] && edges[u][v] != 0 && dist[u] != INT_MAX && dist[u] + edges[u][v] < dist[v])
            {
                dist[v] = dist[u] + edges[u][v];
            }
        }
    }
    cout << dist[dest];
}

int main()
{
    int V, E;
    cin >> V >> E;
    int src, dest;
    cin >> src >> dest;
    int** edges = inputEdges(V, E);
    dijkstra(edges, V, src, dest);
    free(edges, V);
}
