// 3 stl functions

// 1.binary_search(strating_iterator ,ending_iterator(not_included),search_value)=> return true if element is present otherwise false
// 2.lower_bound() =>returns an iterator pointing to  first element >= to the element we are searching for
// 3.upper_bound() => returns an iterator pointing to the first element that is > than the element we are searching

// what is lower bound ?
// Ans :  It is the first index such that arr[i] >= x , where x is any given number

// what is upper bound ?
// Ans :  It is the first index such that arr[i] > x , where x is any given number

#include <bits/stdc++.h>
using namespace std;
int main()
{

    vector<int> vec = {1, 2, 3, 4, 5};
    cout << binary_search(vec.begin(), vec.end(), 4) << endl;
    cout << binary_search(vec.begin(), vec.begin() + 3, 4) << endl;
    cout << binary_search(vec.begin(), vec.begin() + 4, 4) << endl;
    cout << "//////////////////////////" << endl;

    cout << lower_bound(vec.begin(), vec.end(), 6) - vec.begin() << endl;
    cout << lower_bound(vec.begin(), vec.begin() + 3, 6) - vec.begin() << endl;
    cout << lower_bound(vec.begin(), vec.begin() + 4, 6) - vec.begin() << endl;
    cout << vec.end() - vec.begin() << endl;
    cout << "//////////////////////////" << endl;

    vector<int> vec1 = {1, 1, 2, 3};

    cout << lower_bound(vec1.begin(), vec1.end(), 1) - vec1.begin() << endl;
    cout << upper_bound(vec1.begin(), vec1.end(), 1) - vec1.begin() << endl;
    cout << "//////////////////////////" << endl;

    vector<int> vec2 = {0, 0, 2, 3};

    cout << lower_bound(vec2.begin(), vec2.end(), 1) - vec2.begin() << endl;
    cout << upper_bound(vec2.begin(), vec2.end(), 1) - vec2.begin() << endl;

    cout << "//////////////////////////" << endl;
    vector<int> vec3 = {0, 0, 2, 3};

    cout << lower_bound(vec3.begin(), vec3.end(), 4) - vec3.begin() << endl;
    cout << upper_bound(vec3.begin(), vec3.end(), 4) - vec3.begin() << endl;

    return 0;
}