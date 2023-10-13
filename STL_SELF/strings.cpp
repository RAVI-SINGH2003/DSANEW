#include <bits/stdc++.h>
using namespace std;
int main()
{
    string name;
    name = "ravi";
    cout << name << endl;

    string name1(2, 'n');
    cout << name1 << endl;

    string name2 = "hello";
    cout << name2 << endl;

    // string temp;
    // getline(cin, temp);

    // methods
    // 1. size/length
    string name3 = "rainy";
    cout << name3.size() << " " << name3.length() << endl;

    // 2.append
    string name4 = "ravi", name5 = " singh";
    name4.append(name5); // or  string name6 = name5 = name4.append(name5);
    cout << name4 << endl;

    // 3.compare = s1.compare(s2) , 0 when s1=s2 , -ve when s1<s2 ,+ve when s1>s2
    string name7 = "ravi", name8 = "ravi";
    cout << name7.compare(name8) << endl;

    // 4.empty return 1 if empty else 0
    string name9 = "";
    cout << name9.empty() << endl;

    // 5.push_back and pop_back =>same as vector

    // 6. insert()
    string name10 = "ravi";
    name10.insert(4, " hello");
    cout << name10 << endl;

    // 7.erase(index,no_of_characters)
    string name11 = "nincompoop";
    // name11.erase(3); //delete from idx3 till end 
    // name11.erase(3,1);
    // name11.erase(name11.begin()+3, name11.begin()+6);
    cout << name11 << endl;

    // 8.find()=return index otherwise -1
    string name12 = "rai ravi";
    int idx = name12.find("av");
    cout << idx << endl;

    // 9. substr(int idx,int no of characters)
    string name13 = "It's sunny ";
    cout << name13.substr(2) << endl; // retruns string from idx= 2 till end
    cout << name13.substr(2, 4) << endl;

    // 10.stoi
    string num = "-14";
    cout << stoi(num) + 5 << endl;

    // 11.to_string()
    int number = 23;
    string hello = to_string(number)+" is a number";
    cout<<hello<<endl;
}