<<<<<<< HEAD
//stl array implementation normal static array ki tarah hi hoti hai
#include<iostream>
#include<array>
using namespace std;
int main()
{
    int basic[3]={1,2,3};
    array<int,4> a ={1,2,3,4};
    // array<int ,4 >b=a;
    // for(int i=0;i<b.size();i++)
    // {    
    //     cout<<b[i]<<endl;
    // }

    int size=a.size();
    
    for(int i=0;i<size;i++)
    {
        cout<<a[i]<<endl;
    }
    cout<<"Element at 2nd Index : "<<a.at(2)<<endl;
    cout<<"empty or not ?  : "<<a.empty()<<endl;
    cout<<"first element  : "<<a.front()<<endl;
    cout<<"empty or not ?  : "<<a.back()<<endl;

=======
//stl array implementation normal static array ki tarah hi hoti hai
#include<iostream>
#include<array>
using namespace std;
int main()
{
    int basic[3]={1,2,3};
    array<int,4> a ={1,2,3,4};
    // array<int ,4 >b=a;
    // for(int i=0;i<b.size();i++)
    // {    
    //     cout<<b[i]<<endl;
    // }

    int size=a.size();
    
    for(int i=0;i<size;i++)
    {
        cout<<a[i]<<endl;
    }
    cout<<"Element at 2nd Index : "<<a.at(2)<<endl;
    cout<<"empty or not ?  : "<<a.empty()<<endl;
    cout<<"first element  : "<<a.front()<<endl;
    cout<<"empty or not ?  : "<<a.back()<<endl;

>>>>>>> f8b8a2dcf8691bf61c6bc66fd4062749d41f17e1
}