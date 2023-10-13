<<<<<<< HEAD
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v;
    cout << "capacity : " << v.capacity() << endl;
    v.push_back(1);
    cout << "capacity : " << v.capacity() << endl;
    v.push_back(2);
    cout << "capacity : " << v.capacity() << endl;
    v.push_back(3);
    cout << "capacity : " << v.capacity() << endl;
    cout << "size : " << v.size() << endl;
    cout << "element at position 2 : " << v.at(2) << endl;
    cout << "First element : " << v.front() << endl;
    cout << "last element : " << v.back() << endl;
    cout << "vector before pop : " << endl;
    for (auto i : v)
    {
        cout << i << endl;
    }
    v.pop_back();
    cout << endl
         << "vector after pop : " << endl;
    for (auto i : v)
    {
        cout << i << endl;
    }
    // clear operation clears all element in the array i.e size =0;
    cout << "Size before clear : " << v.size() << endl;
    v.clear();
    cout << "Size after clear : " << v.size() << endl;

    vector<int> a(5, 1);
    cout << "NEW VECTOR ELEMENTS  : " << endl;
    for (auto i : a)
    {
        cout << i << endl;
    }
    cout << endl;

    // copying vector
    //  vector<int> b=a;
    cout << "Copied array(b)  : " << endl;
    vector<int> b(a);

    for (auto i : b)
    {
        cout << i << endl;
    }
}
=======
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v;
    cout << "capacity : " << v.capacity() << endl;
    v.push_back(1);
    cout << "capacity : " << v.capacity() << endl;
    v.push_back(2);
    cout << "capacity : " << v.capacity() << endl;
    v.push_back(3);
    cout << "capacity : " << v.capacity() << endl;
    cout << "size : " << v.size() << endl;
    cout << "element at position 2 : " << v.at(2) << endl;
    cout << "First element : " << v.front() << endl;
    cout << "last element : " << v.back() << endl;
    cout << "vector before pop : " << endl;
    for (auto i : v)
    {
        cout << i << endl;
    }
    v.pop_back();
    cout << endl
         << "vector after pop : " << endl;
    for (auto i : v)
    {
        cout << i << endl;
    }
    // clear operation clears all element in the array i.e size =0;
    cout << "Size before clear : " << v.size() << endl;
    v.clear();
    cout << "Size after clear : " << v.size() << endl;

    vector<int> a(5, 1);
    cout << "NEW VECTOR ELEMENTS  : " << endl;
    for (auto i : a)
    {
        cout << i << endl;
    }
    cout << endl;

    // copying vector
    //  vector<int> b=a;
    cout << "Copied array(b)  : " << endl;
    vector<int> b(a);

    for (auto i : b)
    {
        cout << i << endl;
    }
}
>>>>>>> f8b8a2dcf8691bf61c6bc66fd4062749d41f17e1
