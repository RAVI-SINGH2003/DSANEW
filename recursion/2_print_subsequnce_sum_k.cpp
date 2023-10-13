#include <iostream>
#include <vector>
using namespace std;
void print(vector<int> &temp)
{
    for (int num : temp) 
    {
        cout << num;
    }
    cout << endl;
}
void printSubsequencesWithSumk(vector<int> &v, vector<int> temp, int k, int idx)
{
    if (idx >= v.size())
    {
        if (k == 0)
        {
            print(temp);
        }
        return;
    }
    temp.push_back(v[idx]);
    printSubsequencesWithSumk(v, temp, k - v[idx], idx + 1);
    temp.pop_back();
    printSubsequencesWithSumk(v, temp, k, idx + 1);
}

bool printOneSubsequnceWithSumk(vector<int> &v, vector<int> temp, int k, int idx)
{
    if (idx >= v.size())
    {
        if (k == 0)
        {
            print(temp);
            return true;
        }
        return false;
    }
    temp.push_back(v[idx]);
    bool check1 =printOneSubsequnceWithSumk(v, temp, k - v[idx], idx + 1);
    if (check1 == true){
        return true;
    }
    else{
        temp.pop_back();
        bool check2  = printOneSubsequnceWithSumk(v, temp, k, idx + 1);
        return check2 ? true : false;
    }

}

int main()
{
    vector<int> v = {1, 2, 1};
    int k = 2;
    vector<int> temp;
    printSubsequencesWithSumk(v, temp, k, 0);
    printOneSubsequnceWithSumk(v, temp, k, 0);
}
// TC: O(2^N)