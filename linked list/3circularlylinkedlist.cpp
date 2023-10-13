#include <iostream>
using namespace std;
class Node
{
public:
  int data;
  Node *next;
  Node(int d)
  {
    this->data = d;
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

void InsertNode(Node *&tail, int element, int d)
{
  Node *newnode = new Node(d);
  if (tail == NULL)
  {
    tail = newnode;
    tail->next = tail;
  }
  else
  {
    // non-empty list
    // assuming that the element is present in the list
    Node *temp = tail;

    while (temp->data != element)
    {
      temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
  }
}
void print(Node *tail)
{
  Node *curr = tail, *temp = tail;
  if (tail == NULL)
  {
    cout << "List is empty";
    return;
  }
  else
  {

    do
    {
      cout << temp->data << " ";
      temp = temp->next;

    } while (temp != curr);
  }
  cout << endl;
}
void deletenode(Node *&tail, int element)
{
  if (tail == NULL)
  {
    cout << "List is empty";
    return;
  }

  else
  {  
    //assuming that "value" is present in the linkedlist
    Node *prev = tail;
    Node *curr = prev->next;
    while (curr->data != element)
    {
      prev = curr;
      curr = curr->next;
    }

    //1 Node in linked list
    if(curr==prev)
    {
      tail=NULL;
    }

    //last node deletion
    else if(tail==curr)
    {
      tail=prev;

    }
    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
  }
}
int main()
{
  // Node *head=NULL;
  Node *tail = NULL;
  InsertNode(tail, 5, 3);
  print(tail);
  InsertNode(tail, 3, 5);
  print(tail);
  InsertNode(tail, 5, 7);
  print(tail);
  InsertNode(tail, 7, 9);
  print(tail);
  InsertNode(tail, 5, 6);
  print(tail);
  InsertNode(tail, 3, 10);
  print(tail);
  deletenode(tail,5);
  print(tail);
}