#include <iostream>
#include <vector>
using namespace std;

int countSubsequencesWithSumk(vector<int> &v, int k, int idx)
{
    if (idx >= v.size())
    {
        if (k == 0)
        {
           return 1;
        }
        return 0;
    }
    int count1 = countSubsequencesWithSumk(v, k - v[idx], idx + 1);
    int count2 = countSubsequencesWithSumk(v, k, idx + 1);
    return count1+count2; 
}

int main()
{
    vector<int> v = {1, 2, 1};
    int k = 2;
    cout<<countSubsequencesWithSumk(v, k, 0);
    
}
// TC: O(2^N)