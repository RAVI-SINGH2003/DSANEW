#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a = 1, b = 100;
    vector<bool> primeArr(b + 1, true);
    primeArr[1] = false;
    for (int i = 2; i*i <= b; i++)
    {
        if (primeArr[i] == true)
        {
            for (int j = i * i; j <= b; j += i)
            {
                primeArr[j] = false;
            }
        }
    }
    for (int i = a; i <= b; i++)
    {
        if (primeArr[i] == true)
        {
            cout << i << "\n";
        }
    }
}
