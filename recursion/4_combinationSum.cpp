// In this question we can pick an element multiple times.example arr[0] can be picked only many times for a combination.
// There are no duplicates.
// we want to generate all unique combinations such that the elements in the combination sum to target_sum.

#include <bits/stdc++.h>
using namespace std;
void print(auto s, auto i, auto ds, auto sum, int cursum)
{
    if (i == s.size())
    {
        if (cursum == sum)
        {
            for (int e : ds)
            {
                cout << e << " ";
            }
            cout << endl;
        }
        return;
    }

    // pick
    if (cursum + s[i] <= sum)
    {
        ds.push_back(s[i]);
        print(s, i, ds, sum, cursum + s[i]);
        ds.pop_back();
    }
    // non-pick
    print(s, i + 1, ds, sum, cursum);
}
int main()
{
    vector<int> v = {1,2,2,2,3};
    vector<int> ds;
    int sum = 4;
    print(v, 0, ds, sum, 0);
    return 0;
}

// TC : O(2^N *K)  //k is the aveage length of combinations  *k for storing temp in ans
// SC: O(k*x) x=no of combinations and k = average length of combinations
// AS = O(N)