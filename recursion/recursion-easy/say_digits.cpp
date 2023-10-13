#include <bits/stdc++.h>
using namespace std;
string mapping[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
void print(int n)
{
    if (n / 10 == 0)
    {
        cout << mapping[n % 10] << " ";
        return;
    }
    print(n / 10);
    cout << mapping[n % 10] << " ";
}
int main()
{
    int n = 123;
    print(n);
    return 0;
}