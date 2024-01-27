#include<bits/stdc++.h>
using namespace std;
//TC : O(N*Logn)
//SC : O(1)
int longestConsecutive(vector<int> &a)
{

    int n = a.size();
    if (n == 0)
    
        return 0;
    int len = 1;
    int maxi = 1;
    int prevIdx = 0;
    sort(a.begin(), a.end());
    for (int i = 1; i < n; i++)
    {
        if (a[i] - a[prevIdx] == 1)
        {
            len++;
            prevIdx = i;
        }
        else if (a[i] != a[prevIdx])
        {
            len = 1;
            prevIdx = i;
        }
        maxi = max(maxi, len);
    }
    return maxi;
}

//TC :O(N)
//SC : O(N)

int longestConsecutive(vector<int> &a)
{
    if (a.size() == 0)
        return 0;
    unordered_set<int> sett;
    for (int e : a)
        sett.insert(e);
    int maxi = 1;
    for (int e : sett)
    {
        //if it is the first element in the consecutive sequence 
        // then check the longest consecutive sequence we can make
        if (!sett.count(e - 1))
        {
            int count = 1;
            int num = e + 1;
            while (sett.count(num))
            {
                count++;
                num++;
            }
            maxi = max(maxi, count);
        }
    }
    return maxi;
}