// Node *removeDuplicates(Node *head)
// {
//    if(head==NULL || head->next==NULL) return head;
//    Node*curr=head;
//    while(curr->next!=NULL)
//    {
//        if(curr->data==curr->next->data) {
//            Node*temp=curr->next;
//            curr->next=curr->next->next;
//            temp->next=NULL;
//            delete temp;
           
//         }
//         else
//         curr=curr->next;
//    }
//    return head;
    
// }