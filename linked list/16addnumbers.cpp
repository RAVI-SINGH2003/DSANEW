// Approach -1 TC :O(N) +O(M) +O(MAX(N,M))= O(M+N) SC : O(MAX(M,N))
// steps :
//  1. Reverse linklists;
//  2.Add node by node ans store result in a new ll also manage carry;
//  3.reverse ll again to get final answer;
// Node *reverse(Node *head)
// {

//     Node *prev = NULL, *curr = head;
//     while (curr != NULL)
//     {
//         Node *forward = curr->next;
//         curr->next = prev;
//         prev = curr;
//         curr = forward;
//     }
//     return prev;
// }
// struct Node *addTwoLists(struct Node *first, struct Node *second)
// {
//     Node *curr1 = reverse(first), *curr2 = reverse(second);
//     Node *head = new Node(-1), *tail = head;
//     int carry = 0;
//     while (curr1 != NULL && curr2 != NULL)
//     {
//         int val = curr1->data + curr2->data + carry;
//         if (val >= 10)
//             carry = 1;
//         else
//             carry = 0;
//         Node *temp = new Node(val % 10);
//         tail->next = temp;
//         tail = temp;
//         curr1 = curr1->next;
//         curr2 = curr2->next;
//     }
//     while (curr1 != NULL)
//     {
//         int val = curr1->data + carry;
//         if (val >= 10)
//             carry = 1;
//         else
//             carry = 0;
//         Node *temp = new Node(val % 10);
//         tail->next = temp;
//         tail = temp;
//         curr1 = curr1->next;
//     }
//     while (curr2 != NULL)
//     {
//         int val = curr2->data + carry;
//         if (val >= 10)
//             carry = 1;
//         else
//             carry = 0;
//         Node *temp = new Node(val % 10);
//         tail->next = temp;
//         tail = temp;
//         curr2 = curr2->next;
//     }
//     if (carry == 1)
//     {
//         Node *temp = new Node(carry);
//         tail->next = temp;
//         tail = temp;
//     }
//     head = reverse(head->next);
//     return head;
// }