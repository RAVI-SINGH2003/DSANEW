<<<<<<< HEAD
#include<iostream>
using namespace std;
class stack 
{
    int *arr;
    int size;
    int top1,top2;
    public :
    stack(int size)
    {
        this->size=size;
        arr= new int[size];
        top1 =-1;
        top2= size;

    }
    void push1(int data)
    {
        if(top1+1==top2){
            cout<<"stack1 is full"<<endl;
        }
        arr[++top1]= data;
    }
    void push2(int data)
    {
        if(top2-1==top1){
            cout<<"stack2 is full"<<endl;
        }
        arr[--top2]= data;
    }
    void pop1()
    {
        if(top1==-1){
            cout<<"stack1 is empty"<<endl;
        }
       cout<<"element deleted : "<<arr[top1--]<<endl;
    }
       void pop2()
    {
        if(top2==size){
            cout<<"stack2 is empty"<<endl;
        }
       cout<<"element deleted : "<<arr[top2++]<<endl;
    }
    void display()
    {
        if(top1==-1)
        {
            cout<<"stack1 are empty"<<endl;
        }
       else if(top2==size)
        {
            cout<<"stack2 are empty"<<endl;
        }
        cout<<"elements of stack1 are : ";
        for(int  i= 0 ;i<=top1;i++)
        {
           cout<<arr[i]<<" ";
        }
        cout<<"\nelements of stack2 are : ";
        for(int  i = size-1;i>=top2;i--)
        {
           cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main()
{
    stack st(6);
    st.push1(1);
    st.push1(2);
    st.push1(3);
    st.push2(4);
    st.push2(5);
    st.push2(6);
    st.display();
=======
#include<iostream>
using namespace std;
class stack 
{
    int *arr;
    int size;
    int top1,top2;
    public :
    stack(int size)
    {
        this->size=size;
        arr= new int[size];
        top1 =-1;
        top2= size;

    }
    void push1(int data)
    {
        if(top1+1==top2){
            cout<<"stack1 is full"<<endl;
        }
        arr[++top1]= data;
    }
    void push2(int data)
    {
        if(top2-1==top1){
            cout<<"stack2 is full"<<endl;
        }
        arr[--top2]= data;
    }
    void pop1()
    {
        if(top1==-1){
            cout<<"stack1 is empty"<<endl;
        }
       cout<<"element deleted : "<<arr[top1--]<<endl;
    }
       void pop2()
    {
        if(top2==size){
            cout<<"stack2 is empty"<<endl;
        }
       cout<<"element deleted : "<<arr[top2++]<<endl;
    }
    void display()
    {
        if(top1==-1)
        {
            cout<<"stack1 are empty"<<endl;
        }
       else if(top2==size)
        {
            cout<<"stack2 are empty"<<endl;
        }
        cout<<"elements of stack1 are : ";
        for(int  i= 0 ;i<=top1;i++)
        {
           cout<<arr[i]<<" ";
        }
        cout<<"\nelements of stack2 are : ";
        for(int  i = size-1;i>=top2;i--)
        {
           cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main()
{
    stack st(6);
    st.push1(1);
    st.push1(2);
    st.push1(3);
    st.push2(4);
    st.push2(5);
    st.push2(6);
    st.display();
>>>>>>> f8b8a2dcf8691bf61c6bc66fd4062749d41f17e1
}