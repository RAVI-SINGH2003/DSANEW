<<<<<<< HEAD
#include<iostream>
using namespace std;
class stack
{
    public :
   int data;
   stack * next;
   stack(int data){
    this->data = data;
    this->next = NULL;
   }
   ~stack(){
   int val = this->data;
    if (this->next != NULL)
    {
      delete next;
      this->next = NULL;
    }
    cout << "memory is free for stack with data " << val << endl;
   }
};
stack * head=NULL;
void push(int data)
{   stack * temp = new stack(data); 
    if(head==NULL)
    {
      head = temp;   
    }
    else{
        temp->next =head;
        head = temp;
    }
}
void pop()
{  
    if(head==NULL)
    {
      cout<<"Stack is empty";
    }
    else{
       stack *temp = head;
       head = head->next;
       temp->next = NULL;
       delete temp;
    }
}
void peek()
{   
    if(head==NULL)
    {
      cout<<"Stack is empty";
    }
    else{
        cout<<"Top element  : "<<head->data<<endl;
    }
}
void display()
{   
    if(head==NULL)
    {
      cout<<"Stack is empty";
    }
    else{
       cout<<"Element in the stack : ";
       stack * curr = head;
       while(curr!=NULL)
       {
        cout<<curr->data<<" ";
        curr=curr->next;
       }
       cout<<endl;
    }
}
int main()
{
 push(1);
 push(2);
 push(3);
 push(4);
 display();
 pop();
 peek();
 display();

=======
#include<iostream>
using namespace std;
class stack
{
    public :
   int data;
   stack * next;
   stack(int data){
    this->data = data;
    this->next = NULL;
   }
   ~stack(){
   int val = this->data;
    if (this->next != NULL)
    {
      delete next;
      this->next = NULL;
    }
    cout << "memory is free for stack with data " << val << endl;
   }
};
stack * head=NULL;
void push(int data)
{   stack * temp = new stack(data); 
    if(head==NULL)
    {
      head = temp;   
    }
    else{
        temp->next =head;
        head = temp;
    }
}
void pop()
{  
    if(head==NULL)
    {
      cout<<"Stack is empty";
    }
    else{
       stack *temp = head;
       head = head->next;
       temp->next = NULL;
       delete temp;
    }
}
void peek()
{   
    if(head==NULL)
    {
      cout<<"Stack is empty";
    }
    else{
        cout<<"Top element  : "<<head->data<<endl;
    }
}
void display()
{   
    if(head==NULL)
    {
      cout<<"Stack is empty";
    }
    else{
       cout<<"Element in the stack : ";
       stack * curr = head;
       while(curr!=NULL)
       {
        cout<<curr->data<<" ";
        curr=curr->next;
       }
       cout<<endl;
    }
}
int main()
{
 push(1);
 push(2);
 push(3);
 push(4);
 display();
 pop();
 peek();
 display();

>>>>>>> f8b8a2dcf8691bf61c6bc66fd4062749d41f17e1
}