#include<bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> &arr)
{
    int maj = arr[0];
    int k = 1;
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] == maj)
            k++;
        else
            k--;
        if (k == 0)
        {
            maj = arr[i];
            k = 1;
        }
    }
    int count = 0;
    //to check if it's a maj elem count its occurence
    for(int e : arr){
        if(e==maj) {
            count++;
        }
    }
    if(count <=arr.size()/2) {
        cout << "No majority element"; 
    }
   else  return maj;
}