#include <iostream>
using namespace std;
// https://leetcode.com/problems/reverse-linked-list/submissions/
//   ListNode* reverseList(ListNode* head) {
//          if(head==NULL||head->next==NULL)
//             return head;
//          ListNode *forward=NULL,*prev=NULL,*curr=head;

//         while(curr!=NULL)
//         {
//             forward=curr->next;
//             curr->next=prev;
//             prev=curr;
//             curr=forward;
//         }
//         return prev;
//     }
// };

// using recursion
//  ListNode*recusion(ListNode *curr,ListNode *prev)
//      {
//           if(curr==NULL)
//           {
//               return prev;
//           }
//          ListNode *forward=curr->next;
//          curr->next=prev;
//        return  recusion(forward,curr);
//      }
//       ListNode* reverseList(ListNode* head) {

//     return  recusion(head,NULL);

//     }
// };

// recursion method -2
//  void recursion(ListNode*&head,ListNode *curr,ListNode *prev)
//      {
//           if(curr==NULL)
//           {
//              head=prev;
//               return;
//           }
//          ListNode *forward=curr->next;
//          curr->next=prev;
//          recursion(head,forward,curr);
//      }
//       ListNode* reverseList(ListNode* head) {

//       recursion(head,head,NULL);
//          return head;

//     }
// };



//Time Complexity  : O(n);
//space complexity : O(n);
