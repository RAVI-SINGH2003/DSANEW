#include <iostream>
using namespace std;

// SC : O(n*n)
// TC : O(m)
int main()
{
    int n, m;
    //  n = no. of nodes
    //  m = no. of edges
    cin >> n >> m;
    // if nodes are 1 based indexed
    // int adj[n][n]; if 0 based indexing
    int adj[n + 1][n + 1];

    // for undirected graph
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        // edge from u to v
        adj[u][v] = 1;
        // edge from v to u
        adj[v][u] = 1;
    }

    // for directed graph
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        // edge from u to v;
        adj[u][v] = 1;
    }

    // for weighted graph and undirected graph

    int weight[n + 1][n + 1];

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        // edge from u to v
        adj[u][v] = 1;
        weight[u][v] = w;

        // edge from v to u
        adj[v][u] = 1;
        weight[v][u] = w;
    }
}