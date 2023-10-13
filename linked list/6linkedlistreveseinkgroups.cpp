//https://leetcode.com/problems/reverse-nodes-in-k-group/
// int counts(ListNode *head)
// {
//     int c = 0;
//     while (head != NULL)

//     {
//         head = head->next;
//         c++;
//     }
//     return c;
// }
// ListNode *reverseKGroup(ListNode *head, int k)
// {
//     if (head == NULL)
//     {
//         return NULL;
//     }
//     ListNode *next = NULL, *curr = head, *prev = NULL;
//     if (counts(head) < k)
//         return curr;

//     int count = 0;
//     while (curr != NULL && count < k)
//     {
//         next = curr->next;
//         curr->next = prev;
//         prev = curr;
//         curr = next;
//         count++;
//     }
//     head->next = reverseKGroup(next, k);
//     return prev;
// }