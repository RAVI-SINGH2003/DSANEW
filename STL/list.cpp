<<<<<<< HEAD
// list implementation is using doubly linked list
#include <iostream>
#include <list>
using namespace std;
int main()
{
    list<int> l;
    list<int> k(l);  //copying of list
    list <int> j(5,100); //initialisation of list 
    for(int i :  j)
    {
        cout<<i<<endl;
    }
    cout<<l.front();
    cout<<l.back();
  // cout<<l[1]; not allowed
    l.push_back(1);
    l.push_front(2);
    for (int i : l)
    {
        cout << i << " ";
    }
    cout << endl;

    // l.pop_back();
    // l.pop_front();
    // for(int i : l)
    // {
    //     cout<<i<<" ";
    // }cout<<endl;

    l.erase(l.begin()); // O (n)
    cout << "list after the erase : " << endl;
    for (int i : l)
    {
        cout << i << " ";
    }
    cout << endl;
    cout<<"size : "<<l.size();
    
=======
// list implementation is using doubly linked list
#include <iostream>
#include <list>
using namespace std;
int main()
{
    list<int> l;
    list<int> k(l);  //copying of list
    list <int> j(5,100); //initialisation of list 
    for(int i :  j)
    {
        cout<<i<<endl;
    }
    cout<<l.front();
    cout<<l.back();
  // cout<<l[1]; not allowed
    l.push_back(1);
    l.push_front(2);
    for (int i : l)
    {
        cout << i << " ";
    }
    cout << endl;

    // l.pop_back();
    // l.pop_front();
    // for(int i : l)
    // {
    //     cout<<i<<" ";
    // }cout<<endl;

    l.erase(l.begin()); // O (n)
    cout << "list after the erase : " << endl;
    for (int i : l)
    {
        cout << i << " ";
    }
    cout << endl;
    cout<<"size : "<<l.size();
    
>>>>>>> f8b8a2dcf8691bf61c6bc66fd4062749d41f17e1
}