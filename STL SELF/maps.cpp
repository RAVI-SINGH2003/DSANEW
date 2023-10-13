#include<bits/stdc++.h>
using namespace std;

//maps = red black trees = tc : logn
//unordered = hash table = tc: o(1) = average , o(n) = worst
map<int, int> mapInsert(int arr[], int n)
{
    map<int, int> mp;
    // Insert arr[i] as key and i as value
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]] = i;
    }
    return mp;
}

void mapDisplay(map<int, int> mp)
{
    // Print every key and value pair in a new line
    map<int, int>::iterator it;
    for (it = mp.begin(); it != mp.end(); it++)
    {
        cout << it->first << " " << it->second << "\n";
    }
}

void mapErase(map<int, int> &mp, int x)
{
    // Write the if and else condition to erase x from map
    auto it = mp.find(x);
    if (it != mp.end())
    {
        mp.erase(it);
        cout << "erased " << x;
    }
    else
    {
        // else condition
        cout << "not found";
    }

    cout << endl;
}
void other()
{
    map<int, int> mpp = {{1, 2}, {3, 4}};
    mpp[1] = 6;
    mpp.insert({{100, 101}, {7, 8}});
    for (auto p : mpp)
    {
        cout << p.first << " " << p.second << endl;
    }
}