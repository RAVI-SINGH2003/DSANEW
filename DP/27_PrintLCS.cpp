#include<bits/stdc++.h>
using namespace std;
int main(void){
    string s = "abcde" , t = "bdgek";
    int n = s.length() , m = t.length();
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    for(int i = 0; i<=m; i++){
        dp[0][i] =0;
    }
    for(int i = 0 ; i<=n; i++){
        dp[i][0] = 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    cout << dp[n][m]<<endl;
    string lcs = "";
    int i = n , j = m;

    //O(n+m)
    while(i>0 && j>0){
        if(s[i-1]==t[j-1]){
            lcs += s[i-1];
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    reverse(lcs.begin(),lcs.end());
    cout << lcs;
}