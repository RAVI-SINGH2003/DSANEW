// In this question we can pick an element multiple times.example arr[0] can be picked only many times for a combination.
// There are duplicates also
// we want to generate all unique combinations such that the elements in the combination sum to target_sum.

#include <bits/stdc++.h>
using namespace std;
void print(auto s, auto i, auto ds, auto sum, int cursum)
{
    if (cursum == sum)
    {
        for (int e : ds)
        {
            cout << e << " ";
        }
        cout << endl;
        return;
    }
    if (cursum > sum || i == s.size())
    {
        return;
    }

    for (int j = i; j < s.size(); j++)
    {
        if (j > i && s[j] == s[j - 1])
            continue;
        if (cursum + s[j] > sum)
            break;
        else
        {
            ds.push_back(s[j]);
            print(s, j, ds, sum, cursum + s[j]);
            ds.pop_back();
        }
    }
    return;
}
int main()
{
    vector<int> v = {1, 2, 2, 2, 3};
    vector<int> ds;
    int sum = 4;
    sort(v.begin(), v.end());
    print(v, 0, ds, sum, 0);
    return 0;
}

// TC : O(2^N *K)  //k is the aveage length of combinations  *k for storing temp in ans
// SC: O(k*x) x=no of combinations and k = average length of combinations
//  AS = O(N)