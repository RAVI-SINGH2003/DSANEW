// approach 1

//     class Solution
// {
// public:
//     // Function to check if the linked list has a loop.
//     bool detectLoop(Node *head)
//     {  if(head==NULL)
//         return false;
//         unordered_map<Node *, bool> visited;
//         Node *temp = head;
//         int check = 0;
//         while (check != 1 && temp != NULL)
//         {
//             if (visited[temp] == 1)
//             {
//                 check = 1;
//             }

//             visited[temp] = 1;
//             temp = temp->next;
//         }
//         if (check == 1)
//         {
//             return true;
//         }
//         else
//             return false;
//     }
// };
// TC :O(N)
// SC: O(N)

// Approach 2:floyds cycle detection algorithm

//  ListNode *floyd(ListNode *head)
// {
//     ListNode *slow = head, *fast = head;
//     while (fast!=NULL && fast->next!=NULL)
//     {
//         slow = slow->next;
//         fast = fast->next;
//          if(fast!=NULL)
//           fast=fast->next;
//         if (slow == fast)
//          return true;
//     }
//     return false;
// }
// TC :O(N)
// SC :O(1)
