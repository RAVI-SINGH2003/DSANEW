//all syntax just like stack
#include <iostream>
#include <queue>
using namespace std;
int main()
{ // max heap
    priority_queue<int> maxi;

    // min heap
    priority_queue<int, vector<int>, greater<int>> mini;
    maxi.push(1);
    maxi.push(2);
    maxi.push(3);
    maxi.push(0);
    cout<<"size : "<<maxi.size()<<endl;
    int n=maxi.size();
    for(int i=0;i<n;i++)
    {
        cout<<maxi.top()<<endl;
        maxi.pop();
    }
    mini.push(10);
    mini.push(3);
    mini.push(32);
    mini.push(3);
    mini.push(1);
    int n1= mini.size();
    
 cout<<"MIN HEAP "<<endl;
 for(int i=0;i<n1;i++)
 {
     cout<<mini.top()<<endl;
     
     mini.pop();
 }
 cout<<"empty  ?  : "<<mini.empty(); // all elemets deleted in for loop
 

}

