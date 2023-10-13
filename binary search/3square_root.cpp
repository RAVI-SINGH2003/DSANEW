 #include<iostream>
 using namespace std;

 int floorSqrt(int x) 
    {
       if(x==1)
       return 1;
       int low = 1,high = x/2;
       int ans =x;
       while(low<=high){
           
           int mid = low+(high -low)/2;
          
           if(mid*mid==x){
               ans = mid;
               break;
           }
           else if(mid*mid <x){
               low = mid+1;
               ans = mid;
               
           }
           else {
               high = mid -1;
           }
           
       }
       return ans;
 }
double morePrecision(int n ,int intPart ,int Precision)
{
    double factor = 0.1;
    double ans = intPart;

    for(int i =0;i<Precision;i++)
    {
        for(double j=ans; j*j <n ;j=j+factor)
        {
           ans = j;
        }
        factor/=10;
                                                 
    }
    return ans;
} 
 int main()
 {
    int n;   
    cout<<"Enter a number : ";
    cin>>n;
    int intPart = floorSqrt(n);
    cout<<"Answer is"<< morePrecision(n,intPart ,3);

 }