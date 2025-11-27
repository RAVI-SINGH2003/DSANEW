#include <iostream>
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

typedef pair<ll, ll> PII;
typedef vector<ll> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<ll,ll> MPII;
typedef set<ll> SETI;
typedef multiset<ll> MSETI;
#define MP make_pair
#define PB push_back
#define INF (int)1e9

ll mod=1000000007;
// vector<int,int> fact(2 * 1e5 + 1);
ll MOD = 998244353;


ll power(ll a,ll b,ll mod){
    if(b == 0){
        return 1;
    }
    ll ans = power(a,b/2,mod);
    ans *= ans;
    ans %= mod;
    if(b % 2){
        ans *= a;
    }
    return ans % mod;
}

ll ncr(ll n,ll r)
{
    vector<vector<ll>>c(5001,vector<ll>(5001,0));
    for(int i=1;i<=5000;i++)
    {
        c[i][0]=1;
        
    }
    c[1][1]=1;
    for(int i=1;i<=5000;i++)
    {
        for(int j=1;j<=i && j<=5000;j++)
        {
            if(i==1 && j==1)continue;
            else
            {
                c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
            }
        }
    }
    return c[n][r];
    
}


//prime factor in log(N) using seive -->loglog(n);
vector<ll> primefact(ll n)
{
    vector<ll>arr(100001);
    for(int i=0;i<100001;i++)arr[i]=i;
    for(int i=2;i*i<100001;i++)
    {
        if(arr[i]==i)
        {
            for(int j=i*i;j<100001;j+=i)
            {
                if(arr[j]==j)
                {
                    arr[j]=i;
                }
            }
        }
    }
    //seive will be ready in loglog(n);
    //now our seive is rready we now nedd too log(n) operatoin to find the all fromt factor
    vector<ll>ans;
    while(n>1)
    {
        ans.push_back(arr[n]);
        n=n/arr[n];
    }
    return ans;
    
    
    
    
    
    
}

//all prime factor 
//all factor in sqrt(n)
// {
    
//     vector<pair<ll,ll>>v;
//     for(ll i=2;i*i<=n;i++)
//     {
//         ll cnt=0;
//         while(n%i==0)
//         {
//             cnt++;
//             n=n/i;
//         }
//         if(cnt>0)
//         {
//             v.push_back({cnt,i});
//             cnt=0;
//         }
        
//     }
//     if(n>0)v.push_back({1,n});
// }



// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


void solve()
{
  
  ll n;
  cin >> n;
  
  vector<ll> divi;
  
  for(ll i = 1; i*i<=n; i++){
    if(n%i==0){
      divi.push_back(i);
      if(n/i!=i){
          divi.push_back(i);
      }
    }
   
  }
  
  ll count = 0;
  
  sort(divi.begin(),divi.end());
  
  ll ans = 1;
  for(int i = 1; i<n; i++){
    if(i<n && divi[i] == divi[i-1]+1){
      count++;
    }else{
      ans = max(ans,count);
      count  = 1;
    }
  }
  
  cout << ans;
  cout<<"\n";
   
}




int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    
    // solve();

    
	return 0;
}
