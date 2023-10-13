// if ll is 1->2->3 middle : 2 ll :  1 ->2->3->4 middle : 3
//  ListNode* middleNode(ListNode* head) {
        
//         ListNode *fast = head,*slow=head;
//         while(fast!=NULL&&fast->next!= NULL)
//         {
//             slow = slow->next;
//              fast=fast->next;
//              if( fast!=NULL) 
//               fast=fast->next;
//         }
//         return slow;
//     }

// if ll is 1->2->3 middle : 2 ll :  1 ->2->3->4 middle : 2
//  ListNode* middleNode(ListNode* head) {       
//         ListNode *fast = head->next,*slow=head;
//         while(fast!=NULL&&fast->next!= NULL)
//         {
//             slow = slow->next;
//             fast=fast->next->next;
//            
//         }
//         return slow;
//     }