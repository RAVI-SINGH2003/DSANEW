#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 2;
    int ans;
    int s = 1, e = n / 2 + 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (mid * mid == n)
        {
            ans = mid;
            break;
        }
        else if (mid * mid > n)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
            ans = mid;
        }
    }
    double factor = 0.1;
    double finalAnswer = ans;
    for (int i = 0; i < 3; i++)
    {
        double tempAns = finalAnswer;
        for (double j = factor; j <= factor * 9.0; j = j + factor)
        {
            double tempo = tempAns + j;
            if(tempo*tempo<n)
            {
                finalAnswer = tempo;
            }
        }
        factor/=10;
    }
    cout << finalAnswer;
}