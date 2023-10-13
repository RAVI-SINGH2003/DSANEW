#include<bits/stdc++.h>
using namespace std;
// TC : 4*alpha where alpha~1 so constant time compexity O(4)
class DSU{
    vector<int> parent,size,rank;
    public :
    DSU(int n){
        rank.resize(n+1,0);
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }
    int findUParent(int node){
        if(parent[node]==node){
            return node;
        }
        //this is path compression
         parent[node] = findUParent(parent[node]);
         return parent[node];
    }
    void unionByRank(int u , int v){
        //1. find the parent of node
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);

        if(ulp_u==ulp_v){
            return;
        }
        //2. find the rank of nodes
        //3. connect node with smaller rank with bigger rank , if rank same connect anyone to anyone
        if (rank[ulp_u] == rank[ulp_v])
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
        else if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else{
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

int main(){

    //Union by rank
    DSU dsu(7);
    dsu.unionByRank(1,2);
    dsu.unionByRank(2,3);
    dsu.unionByRank(3,4);
    dsu.unionByRank(5,6);
    cout << "Parent of 4 : " << dsu.findUParent(4)<<"\n";
    cout << "Parent of 5 : " << dsu.findUParent(5) << "\n" ;
    if (dsu.findUParent(4) == dsu.findUParent(5))
    {
        cout << "Same\n";
    }
    else cout << "Not Same\n";
    dsu.unionByRank(4,5);
    if (dsu.findUParent(4) == dsu.findUParent(5))
    {
        cout << "Same\n";
    }
    else
        cout << "Not Same\n";

    //Union by size

    DSU dsu2(7);
    dsu2.unionBySize(6,7);
    dsu2.unionBySize(1,2);
    dsu2.unionBySize(2,3);
    dsu2.unionBySize(3,4);
    dsu2.unionBySize(5,6);
    cout << "Parent of 4 : " << dsu2.findUParent(4)<<"\n";
    cout << "Parent of 5 : " << dsu2.findUParent(5) << "\n" ;
    if (dsu2.findUParent(4) == dsu2.findUParent(5))
    {
        cout << "Same\n";
    }
    else cout << "Not Same\n";
    dsu2.unionBySize(4,5);
    if (dsu2.findUParent(4) == dsu2.findUParent(5))
    {
        cout << "Same\n";
    }
    else
        cout << "Not Same\n";
    dsu2.unionBySize(6,7);
}