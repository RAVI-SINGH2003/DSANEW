#include<iostream>
#include<vector>
using namespace std;

void print(vector<int>&temp){
    if(temp.size()==0){
        cout<<"{}";
    }
    else{
         for(int num : temp){
        cout<<num;
        }
    }
     
    cout<<endl;

}
void printSubsequnces(vector<int>&v,vector<int>temp,int idx){
    if(idx>=v.size()){
        print(temp);
        return ;
    }
    temp.push_back(v[idx]);
    printSubsequnces(v,temp,idx+1);
    temp.pop_back();
    printSubsequnces(v,temp,idx+1);
}
int main(){
    vector <int> v ={3,1,2};
    vector<int> temp;
    printSubsequnces(v,temp,0);
}

// TC: O(2^N)
