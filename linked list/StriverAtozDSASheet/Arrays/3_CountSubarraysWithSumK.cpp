#include <bits/stdc++.h>
using namespace std;
int subarraySum(vector<int> &a, int k)
{
    int n = a.size(); // size of the array.

    map<long long, int> preSumMap;
    long long sum = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];

        if (sum == k)
        {
            count++;
        }

        long long rem = sum - k;

        if (preSumMap.find(rem) != preSumMap.end())
        {
            int len = i - preSumMap[rem];
            count += preSumMap[rem];
        }
        preSumMap[sum]++;
    }

    return count;
}