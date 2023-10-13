// int solve(int x,int n)
// {
//     if(n==0) return 1;
//     int temp=solve(x,n-1);
//     return x*temp;
// }
// int solve(int x,int n)
// {
//     if(n==0) return 1;
//     in t temp=solve(x,n/2);
//     temp*=temp;
//     if(n%2==0)
//     return temp;
//     else
//     return x*temp;
// }