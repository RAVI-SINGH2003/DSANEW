<<<<<<< HEAD
#include <iostream>
#include <map>
using namespace std;
int main()
{
    map<int, string> m;
    m[1] = "babbar";
    m[2] = " love ";
    m[3] = "kumar";
    m.insert({5, "bheem"});
    m.insert({4, "raju"});
    m.insert({6, "hello"});
    cout << "Before erase : " << endl;
    for (auto i : m)
    {
        cout << i.first << " : " << i.second << endl;
    }
    m.erase(1);
    cout << endl;
    cout << "after erase : " << endl;
    for (auto i : m)
    {
        cout << i.first << " : " << i.second << endl;
    }
    cout << endl;
    auto it = m.find(5);
    for (auto i = it; i != m.end(); i++)
    {
        cout << i->first << endl;
    }

    cout << m.count(10);
}
// just like set just .first .second otherwise same syntax;
=======
#include<iostream>
#include<map>
using namespace std;
int main()
{
   map<int ,string> m;
   m[1]="babbar";
   m[2]=" love ";
   m[3]="kumar";
   m.insert({5,"bheem"});
   m.insert({4,"raju"});
   m.insert({6,"hello"});
   cout<<"Before erase : "<<endl;
   for(auto i : m)
   {
       cout<<i.first<<" : "<<i.second<<endl;
   }

   cout<<"finding 13 : "<<m.count(6)<<endl;
   m.erase(1);
   cout<<endl;
   cout<<"after erase : "<<endl;
   for(auto i : m)
   {
       cout<<i.first<<" : "<<i.second<<endl;
   }
   cout<<endl;
auto it =m.find(5);
for(auto i =  it;i!=m.end();i++ )
{
    cout<<(*i).first<<endl;
}

cout<<m.count(10);  
 }
 //just like set just .first .second otherwise same syntax;
>>>>>>> f8b8a2dcf8691bf61c6bc66fd4062749d41f17e1
