#include <bits/stdc++.h>
using namespace std;

class DSU
{
    vector<int> parent, size, rank;

public:
    DSU(int n)
    {
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }
    int findUParent(int node)
    {
        if (parent[node] == node)
        {
            return node;
        }
        // this is path compression
        parent[node] = findUParent(parent[node]);
        return parent[node];
    }
    void unionByRank(int u, int v)
    {
        // 1. find the parent of node
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);

        if (ulp_u == ulp_v)
        {
            return;
        }
        // 2. find the rank of nodes
        // 3. connect node with smaller rank with bigger rank , if rank same connect anyone to anyone
        if (rank[ulp_u] == rank[ulp_v])
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
        else if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else
        {
            parent[ulp_v] = ulp_u;
        }
    }
    void unionBySize(int u, int v)
    {
        // 1. find the parent of node
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);

        if (ulp_u == ulp_v)
        {
            return;
        }
        // 2. find the rank of nodes
        // 3. connect node with smaller size with bigger size , if size same connect anyone to anyone
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

bool comp(pair<int,pair<int,int>> p1 , pair<int,pair<int,int>> p2){
    return p1.first < p2.first;
}

// TC : O(MLOGM) SC : O(M);
int main(){

// graph :
//        1
//    1-------2
//    | \     |
//  4 |   \ 3 | 2
//    |     \ |
//    3-------4
//        5  
   int n ,m;
   cin >> n >> m;
   // Take input of edges with weights

   vector<pair<int,pair<int,int>>> edges;

   //TC  : O(M) , SC : O(M)
   for(int i=0;i<m;i++){
    int u , v, w;
    cin >> u >> v >> w;
    edges.push_back({w,{u,v}});
    edges.push_back({w,{v,u}});
   }

    //sort the edges according to weight;
    //TC : O(MLOGM)
    sort(edges.begin(),edges.end(),comp);
    int mst_cost = 0;
    
    //SC :O(M)
    vector<pair<int,pair<int,int>>> MST;

    DSU dsu(n);

    //TC : O(M * 2* 4 *alpha )
    for(auto p : edges){
        int wt = p.first;
        int u = p.second.first;
        int v = p.second.second;
        int ulp_u = dsu.findUParent(u);
        int ulp_v = dsu.findUParent(v);
        //if ultimate parent of two nodes are same then they are part of same component and 
        // doing union will introduce a cycle
        if(ulp_u!=ulp_v){
            dsu.unionBySize(ulp_u,ulp_v);
            mst_cost+=wt;
            MST.push_back(p);
        }
    }
   cout << "MST COST  : " <<mst_cost<<"\n";
   cout << "MST :\n";
   for(auto p : MST){
        // format : u - weight - v
        cout << p.second.first << " " << p.first<<" " << p.second.second << "\n";
   }

}
