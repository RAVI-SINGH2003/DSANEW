#include <bits/stdc++.h>
using namespace std;

// SC : O(n + n + n) = O(n); ( n for recursion stack space , visted , ans)
// TC : O(N) + O(2E) for undirected graph since we are visiting each nodes and then all neighbouring nodes
// TC : O(N) + O(E) for directed graph

void dfs(int node, vector<int> *adj, vector<int> &dfsAns, vector<int> visited)
{

    dfsAns.push_back(node);
    visited[node] = 1;
    for (int child : adj[node])
    {
        if (!visited[child])
        {
            dfs(child, adj, dfsAns, visited);
        }
    }
}
int main()
{
    int n, m;
    cout << "Enter no of nodes and edges : ";
    cin >> n >> m;
    vector<int> adj[n + 1];

    // for undirected graph
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cout << "u" << i + 1 << ", v" << i + 1 << " : ";
        cin >> u >> v;
        // edge from u to v
        adj[u].push_back(v);

        // edge from v to u
        adj[v].push_back(u);
    }
    cout << "DFS : ";
    int stNode = 1;
    vector<int> dfsAns;
    vector<int> visited(n + 1);
    dfs(stNode, adj, dfsAns, visited);
}