//  Approach - 1 TC:O(N) SC : O(1)
// We can use vector also then SC : O(N)
//  bool isPalindrome(ListNode* head) {
//         if(head==NULL || head->next==NULL) return true;
//         string str = "";
//         ListNode *curr=head;
//         while(curr!=NULL){
//             string temp = to_string(curr->val);
            
//             str+=temp;
            
//             curr =  curr->next;
            
//         }
//         int i =0 ,j =str.size()-1;
//         while(i<=j){
//             if(str[i++]!=str[j--]) return false;
            
//         }
//         return true;
//     }
//Approach -2 TC : O(N) SC : O(1)
// steps : 
//1.Find middle
//2.reverse nodes from middle till end;
//3.check if nodes before middle matches nodes after middle
//  ListNode* middle(ListNode* head){
//         ListNode * slow = head,*fast=head,*prev=slow;
//         while(fast!=NULL && fast->next!=NULL){
//             prev = slow;
//             slow=slow->next;
            
//             fast=  fast->next;
//             if(fast!=NULL)
//                 fast= fast->next;
        
//         }
//         return prev; //returning node before middle node
//     }
//     ListNode * reverse(ListNode * head){
        
//         ListNode *prev = NULL, *curr=head;
//         while(curr!=NULL){
//             ListNode* forward = curr->next;
//             curr->next=prev;
//             prev=curr;
//             curr=forward;
//         }
//         return prev;
        
//     }
//     bool isPalindrome(ListNode* head) {
//         if(head==NULL || head->next==NULL) return true;
//         ListNode* beforemiddle = middle(head); // node before middle
//         ListNode* nextnode =reverse(beforemiddle->next); //reverse node from middle till end
//         beforemiddle->next = nextnode; // middle ke pehle wali jo node thi uske aage reversed ll ka head
//         ListNode*curr1=head,*curr2=nextnode; // check two parts of ll 1 part from head till node before middle and 2 part is the reversed ll
//         while(curr1!=nextnode && curr2!=NULL)
//         {
//             if(curr1->val !=curr2->val) return false;
//             curr1=curr1->next;
//             curr2=curr2->next;
//         }
//         return true;
        
//     }