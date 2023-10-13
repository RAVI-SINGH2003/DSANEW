#include <bits/stdc++.h>
using namespace std;

// SC : O(2m) = for undirected graph
// SC : O(4m) = for weighted undirected graph
// SC : O(m) = for directed graph
// SC : O(2m) = for weighted directed graph

// TC : O(m)
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];

    // for undirected graph
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        // edge from u to v
        adj[u].push_back(v);

        // edge from v to u
        adj[v].push_back(u);
    }

    // for directed graph
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        // edge from u to v only;
        adj[u].push_back(v);
    }

    // for weighted undirected graph
    vector<pair<int, int>> adjWithWeight[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        // edge from u to v
        adjWithWeight[u].push_back({v, w});

        // edge from v to u
        adjWithWeight[v].push_back({u, w});
    }
}
