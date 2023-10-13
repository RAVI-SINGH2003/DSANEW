#include <bits/stdc++.h>
using namespace std;
void print(vector<int>&v)
{
    for(int i : v)
    cout<<i<<" ";
    cout<<"\n";

}
int main()
{
    vector<int>  v = {1, 2, 3, 4};

    //insert
    v.insert(v.begin()+ 1, {10,11});
    v.insert(v.end(), {12,13});
    print(v);
    int idx = v.front();
    int idx1= v.back();
    cout<<idx << " " << idx1<<"\n";
    // erase(it1,it2) removes elements b/w range [it1,it2)
    v.erase(v.begin() + 2,v.begin()+4);
    print(v);
    cout<<"Capacity : " << v.capacity()<<"\n";

    //emplace_back use this instead of push_back
    v.emplace_back(21);
    print(v);

}

//for cheking the working of clear and erase
//clear makes size = 0;
//erase also reduces size
//capacity in both the cases will not change , but all indexes from size to capacity-1 will have garbage values
int main()
{
    vector<int> v = {1, 2, 3, 4};
    cout << "Capacaity : " << v.capacity() << "size : " << v.size() << "\n";
    v.erase(v.begin());
    // v.clear();
    cout << "Capacaity : " << v.capacity() << "size : " << v.size() << "\n";
    print(v);
}