// Brute force  TC: O(N^2)
// Node *removeDuplicates(Node *head)
// {
//   if(head==NULL)
// 	  return NULL;
// 	Node* temp1=head;
// 	while(temp1!=NULL)
// 	{
// 		Node*temp2=temp1->next;
// 		Node*prev=temp1;
// 		while(temp2!=NULL)
// 		{
// 			if(temp1->data==temp2->data)
// 			{
// 				prev->next=temp2->next;

// 				Node* duplicate=temp2;
// 				temp2=temp2->next;
// 				delete duplicate;

// 			}

// 		 else
// 		 {     prev=temp2;
// 			   temp2=temp2->next;

// 		 }

// 		}
// 		temp1=temp1->next;
// 	}
// 	return head;
// }

// USING MAPS :TC = o(N) SC=O(n)
//  Node * removeDuplicates( Node *head) 
//     {
//      unordered_map<int ,bool> visited;
//      Node*curr=head,*prev=curr;
//      while(curr!=NULL)
//      {
//          if(visited[curr->data]==true)
//          {
//              prev->next=curr->next;
//              Node*temp= curr;
//              curr=curr->next;
//              temp->next=NULL;
//              delete temp;
             
//          }
//          else
//          {
//              visited[curr->data]=true;
//              prev=curr;
//              curr=curr->next;
//          }
//      }
//      return head;
//     }
