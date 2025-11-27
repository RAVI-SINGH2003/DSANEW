#include <bits/stdc++.h>
using namespace std;

// In prefix sum questions try to use 1 based indexing as l and r are also 1 based many times.
int main()
{
    int q , n;
    cin >> q >> n;
    vector<int> nums(n + 1);

    vector<int> pref(n+1);


    for (int i = 1; i <= n; i++)
    {
        cin >> nums[i];
        pref[i]= pref[i-1] + nums[i];
    }

    while(q--){
        int l , r;
        cin >> l >> r;
        cout  << pref[r] - pref[l-1] << endl;
    }
}