<<<<<<< HEAD
#include<iostream>
using namespace std;
class stack
{
   public :
   int *arr;
   int top;
   int size;
   stack(int size)
   {
       this->size =size;
       arr = new int[size];
       top=-1;

   }
void push(int x)
{
  if(top==size)
  {
     cout<<"Stack is full"<<"\n";
     return ;
  }
  else
  {
      top++;
      arr[top]=x;

  }
}
void pop()
{
if(top<0)
{
    cout<<"Stack is empty"<<"\n";
    return;
}
else{
    
cout<<"element deleted : "<<arr[top--]<<"\n";

}
}
void peek()
{
  if(top<0)
  {
      cout<<"Stack is empty"<<"\n";

  }
  else
  {
      cout<<arr[top];
  }
}

bool isEmpty()
{
   if(top<0)
   return true;
   else
   return false;
}
void display()
{
    for(int i=0 ; i<=top;i++)
    cout<<arr[i]<<" ";
    cout<<"\n";
}
};
int main()
{
    stack st(5);
    st.push(10);
    st.push(3);
    st.push(130);
    st.push(103);
    st.push(1043);
    st.display();
    st.pop();
    st.pop();
    st.peek();
    st.pop(); st.display();
    st.pop();

    cout<<st.isEmpty();
     

=======
#include<iostream>
using namespace std;
class stack
{
   public :
   int *arr;
   int top;
   int size;
   stack(int size)
   {
       this->size =size;
       arr = new int[size];
       top=-1;

   }
void push(int x)
{
  if(top==size)
  {
     cout<<"Stack is full"<<"\n";
     return ;
  }
  else
  {
      top++;
      arr[top]=x;

  }
}
void pop()
{
if(top<0)
{
    cout<<"Stack is empty"<<"\n";
    return;
}
else{
    
cout<<"element deleted : "<<arr[top--]<<"\n";

}
}
void peek()
{
  if(top<0)
  {
      cout<<"Stack is empty"<<"\n";

  }
  else
  {
      cout<<arr[top];
  }
}

bool isEmpty()
{
   if(top<0)
   return true;
   else
   return false;
}
void display()
{
    for(int i=0 ; i<=top;i++)
    cout<<arr[i]<<" ";
    cout<<"\n";
}
};
int main()
{
    stack st(5);
    st.push(10);
    st.push(3);
    st.push(130);
    st.push(103);
    st.push(1043);
    st.display();
    st.pop();
    st.pop();
    st.peek();
    st.pop(); st.display();
    st.pop();

    cout<<st.isEmpty();
     

>>>>>>> f8b8a2dcf8691bf61c6bc66fd4062749d41f17e1
}