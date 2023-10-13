#include<bits/stdc++.h>
using namespace std;
void print(vector<int>&v)
{
    for(int i : v)
    cout<<i<<" ";
    cout<<"\n";
}
int main()
{
    vector<int> v={1,2,3,4};


    //insert
    v.insert(v.begin()+ 1, 10);
    print(v);

    // erase(it1,it2) removes elements b/w range [it1,it2)
    v.erase(v.begin() + 2,v.begin()+4);
    print(v);

    //emplace_back use this instead of push_back
    v.emplace_back(21);
    print(v);

}