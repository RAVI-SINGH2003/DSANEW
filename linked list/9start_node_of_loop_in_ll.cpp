// APPROACH 1: using maps;
// using maps

// ListNode *detectCycle(ListNode *head)
// {
//     // using maps

//     if (head == NULL)
//         return NULL;
//     map<ListNode *, int> visited;
//     ListNode *temp = head;
//     while (temp != NULL)
//     {
//         if (visited[temp] == 2)
//         {
//             return temp;
//         }
//         visited[temp] += 1;
//         temp = temp->next;
//     }
//     return NULL;
// }

// APPROACH 2: floyd algorithm
// ListNode *floyd(ListNode *head)
// {
//     ListNode *slow = head, *fast = head;
//     while (slow != NULL && fast != NULL && fast->next != NULL)
//     {
//         slow = slow->next;
//         fast = fast->next->next;
//         if (slow == fast)
//             return fast;
//     }
//     return NULL;
// }
// ListNode *detectCycle(ListNode *head)
// {
//     if (head == NULL)
//         return NULL;
//     ListNode *fast = floyd(head), *slow = head;
//     if (fast == NULL) // one node
//         return NULL;
//     while (slow != fast)
//     {
//         slow = slow->next;
//         fast = fast->next;
//     }
//     return fast;
// }

// other way of approach 2 not used function
// ListNode *detectCycle(ListNode *head)
// {
//     ListNode *slow = head, *fast = head;

//     while (slow != NULL && fast != NULL && fast->next != NULL)
//     {

//         slow = slow->next;       // Slow moves by 1 step
//         fast = fast->next->next; // Fast moves by two steps

//         // If they meet then there is a loop
//         if (slow == fast)
//         {
//             // To find the starting element where the loop starts
//             fast = fast;
//             slow = head;
//             while (slow != fast)
//             {
//                 // Both move by 1 step
//                 slow = slow->next;
//                 fast = fast->next;
//             }
//             return slow;
//         }
//     }

//     return NULL; // No loop
// }



