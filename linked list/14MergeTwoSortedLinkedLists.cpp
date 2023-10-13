// Approach -1 TC: O(N+M) SC : O(1)
// Node* sortedMerge(Node* left, Node* right)  
// {
//     if (left == NULL)
//         return right;
//     if (right == NULL)
//         return left;
//     Node *head = new Node(-1);
//     Node *tail = head;
//     while (left != NULL && right != NULL)
//     {
//         if (left->data > right->data)
//         {
//             tail->next = right;
//             tail = right;
//             right = right->next;
//         }
//         else
//         {
//             tail->next = left;
//             tail = left;
//             left = left->next;
//         }
//     }
//     while (left != NULL)
//     {
//         tail->next = left;
//         tail = left;
//         left = left->next;
//     }
//     while (right != NULL)
//     {
//         tail->next = right;
//         tail = right;
//         right = right->next;
//     }
//     head = head->next;
//     return head;
// } 

//Approach -2 TC:  O(M+N) SC : O(1)
// Node* sortedMerge(Node* head1, Node* head2)  
// {  
//     if(head1 == NULL) return head2; 
//     if(head2==NULL) return head1;  
//     Node* curr1=head1,*prev=NULL,*curr2=head2;
//     while(curr2!=NULL && curr1!=NULL){      
//         if(prev== NULL && curr2->data <= curr1->data){    
//             Node * temp = curr2;
//             curr2= curr2->next;
//             temp->next = curr1;
//             head1=prev=temp;       
//         }
//         else if(prev!=NULL && curr2->data >=prev->data && curr2->data<=curr1->data){
//             Node* temp = curr2;
//             curr2= curr2->next;
//             prev->next=temp;
//             temp->next=curr1;
//             prev= temp;
//         }      
//         else
//         {
//         prev=curr1;
//         curr1 = curr1 ->next;
//         }              
//     }
//    list1 finished and we could not insert all nodes of list 2 in 1stt list
//     while(curr2!=NULL){  
//             Node*temp= curr2;
//             curr2=curr2->next;
//             prev->next =temp;
//             temp->next=curr1;
//             prev= temp;
        
//     }
//     return head1;
// }  