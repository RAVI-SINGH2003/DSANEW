#include <iostream>
using namespace std;
class Node
{
public:
  int data;
  Node *next;
  // constructor
  Node(int data)
  {
    this->data = data;
    this->next = NULL;
  }
  ~Node()
  {
    int val = this->data;
    if (this->next != NULL)
    {
      delete next;
      this->next = NULL;
    }
    cout << "memory is free for node with data " << val << endl;
  }
};
void InsertAtHead(Node *&head, Node *&tail, int d)
{
  // new node create

  Node *temp = new Node(d);
  if (head == NULL)
  {  
    head = tail = temp;
  }
  else
  {
    temp->next = head;
    head = temp;
  }
}
void InsertAtTail(Node *&head, Node *&tail, int d)
{
  Node *temp = new Node(d);
  if (tail == NULL)
  {
    head = tail = temp;
  }
  else
  {

    tail->next = temp;
    tail = temp;
  }
}
void print(Node *head)
{ 
   
     if(head==NULL)
     {
         cout<<"List is empty"<<endl;
         return;

     }
  Node *temp = head;
  while (temp != NULL)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}
void InsertAtposition(Node *&tail, Node *&head, int pos, int d)
{
  if (pos == 1)
  {
    InsertAtHead(head, tail, d);
    return;
  }

  Node *temp = head;
  int cnt = 1;
  while (cnt < pos - 1)
  {
    temp = temp->next;
    cnt++;
  }
  // Inserting at last position
  if (temp->next == NULL)
  {
    InsertAtTail(head, tail, d);
    return;
  }
  Node *nodeToInsert = new Node(d);
  nodeToInsert->next = temp->next;
  temp->next = nodeToInsert;
}
void deleteNode(int position, Node *&head, Node *&tail)
{ // deleting first or start node

  if (position == 1)
  {  Node *temp = head;
     if(head->next==NULL) //single node;
     {
       tail=NULL;
     }
    
    head = head->next;
    temp->next = NULL;
    // memory free for start node
    delete temp;
  }
  else
  {
    // deletion middle or last node
    Node *curr = head, *prev = NULL;
    int cnt = 1;
    while (cnt < position)
    {
      prev = curr;
      curr = curr->next;
      cnt++;
    }
    prev->next = curr->next;
    if(curr->next==NULL)
    {
     tail = prev; // when last node is deleted tail is updated
    }
    
    curr->next = NULL;
    delete curr; // delete use karne par destructor call.
  }
}
int main()
{ /// creating a new node
  Node *head = NULL;
  Node *tail = NULL;


  InsertAtHead(head, tail ,20);
  InsertAtHead(head, tail, 15);
  print(head);

  InsertAtTail(head,tail, 20);
  InsertAtTail(head,tail, 13);
  InsertAtTail(head,tail, 154);
  print(head);

  InsertAtposition(tail, head, 6, 190);
  print(head);
  cout << "Head " << head->data << endl;

  cout << "tail " << tail->data << endl;
  deleteNode(3, head, tail);

  InsertAtTail(head, tail, 123);
  InsertAtTail(head, tail, 18);
  print(head);
  deleteNode(1,head,tail);
  print(head);
  return 0;
}