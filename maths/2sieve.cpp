<<<<<<< HEAD
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
=======
// int n;
// vector<bool> is_prime(n+1, true);
// for (int i = 2; i * i <= n; i++) {
//     if (is_prime[i]) {
//         for (int j = i * i; j <= n; j += i)
//             is_prime[j] = false;
//     }
// }
//for(int i =;i<=n;i++){
    //if(is_prime[i]) cout<<i;
//}
>>>>>>> f8b8a2dcf8691bf61c6bc66fd4062749d41f17e1
