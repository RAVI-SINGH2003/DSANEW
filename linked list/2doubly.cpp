#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
    ~Node()
    {
        int val = this->data;
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "memory free for node with data" << val << endl;
    }
};
// traversal
void print(Node *&head)
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
// gives length of Linked lisy
int getlength(Node *&head)
{
    int len = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}
void InsertAtHead(Node *&head, Node *&tail, int d)
{
    Node *newnode = new Node(d);
    /// empty linkedlist

    if (head == NULL)
    {
        head = tail = newnode;
    }
    else
    {
        head->prev = newnode;
        newnode->next = head;
        head = newnode;
    }
}
void InsertAtTail(Node *&head, Node *&tail, int d)
{
    Node *newnode = new Node(d);
    /// empty linkedlist
    if (tail == NULL)
    {
        head = tail = newnode;
    }
    else
    {
        newnode->prev = tail;
        tail->next = newnode;
        tail = newnode;
    }
}
void InsertAtposition(Node *&head, Node *&tail, int pos, int d)
{
    if (pos == 1)
    {
        InsertAtHead(head, tail, d);
        return;
    }
    int cnt = 1;
    Node *temp = head;

    while (cnt < pos - 1)
    {
        temp = temp->next;

        cnt++;
    }
    // if insert at last
    if (temp->next == NULL)
    {
        InsertAtTail(head, tail, d);
        return;
    }
    Node *newnode = new Node(d);

    newnode->next = temp->next;
    temp->next->prev = newnode;
    temp->next = newnode;
    newnode->prev = temp;
}
void deleteNode(int position, Node *&head, Node *&tail)
{ // deleting first or start node

    if (position == 1)
    {

        Node *temp = head;
        if (head->next == NULL && head->prev == NULL) // single node
        {
            head = tail = NULL;
            delete temp;
        }
        else
        {
            head = head->next;
            head->prev = NULL;
            temp->next = NULL;
            delete temp;
        }
    }
    else
    {
        // deletion middle or last node
        Node *curr = head;
        int cnt = 1;
        while (cnt < position)
        {
            curr = curr->next;
            cnt++;
        }
        curr->prev->next = curr->next; 

        if (curr->next != NULL)
        {
            curr->next->prev = curr->prev;
        }
        else  // when last node is deleted;
        {
            tail = curr->prev;
        }
        curr->prev = NULL;
        curr->next = NULL;
        delete curr; // delete use karne par destructor call.
    }
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    // print(head);
    cout << getlength(head) << endl;
    InsertAtHead(head, tail, 11);
    print(head);
    cout << getlength(head) << endl;
    InsertAtTail(head, tail, 191);
    print(head);
    InsertAtposition(head, tail, 2, 122);
    print(head);
    deleteNode(3, head, tail);
    print(head);
    InsertAtTail(head, tail, 200);
    print(head);
   
    return 0;
}