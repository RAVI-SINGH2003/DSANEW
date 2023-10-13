#include <bits/stdc++.h>
using namespace std;
// SC : O(n + n + n) = O(n); (for queue , visted , ans)

// TC : O(N)  + O(2E) for undirected graph since we are visiting each nodes and then all neighbouring nodes
// TC : O(N) + O(E) for directed graph
void bfs(int n, vector<int> *adj)
{
    queue<int> q;
    q.push(2);
    vector<bool> visited(n + 1);
    visited[2] = true;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for (int child : adj[node])
        {
            if (!visited[child])
            {
                q.push(child);
                visited[child] = true;
            }
        }
    }
    return;
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
    cout << "BFS : ";
    bfs(n, adj);
}