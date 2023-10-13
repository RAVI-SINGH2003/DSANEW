//check if a given string is palindrome or not
#include<iostream>
bool isPalindrome(string str,int i=0)
{
    if(i>=str.size()/2)
    return true;
    if(str[i]!=str[str.size()-1-i])
    return false;
    return isPalindrome(str,++i);


}
using namespace std;
int main()
{
    string str;
    cin>>str;
    cout<<isPalindrome(str);
}