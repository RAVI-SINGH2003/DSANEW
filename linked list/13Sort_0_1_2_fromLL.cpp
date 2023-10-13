// Appproach 1 : TC : o(n) sc : o(1)
//   Node *segregate(Node *head)
// {
//     int count0 = 0, count1 = 0, count2 = 0;
//     if (head == NULL)
//         return NULL;
//     Node *temp = head;
//     while (temp != NULL)
//     {
//         if (temp->data == 0)
//             count0++;
//         else if (temp->data == 1)
//             count1++;
//         else
//             count2++;
//         temp = temp->next;
//     }
//     temp = head;
//     int i = 1;
//     while (temp != NULL)
//     {
//         if (i <= count0)
//             temp->data = 0;
//         else if (i > count0 && i <= count1 + count0)
//             temp->data = 1;
//         else
//             temp->data = 2;
//         i++;
//         temp = temp->next;
//     }
//     return head;
// }

//Approach 2 : creation of 3 ll
// Node *segregate(Node *head)
// {

//     // Add code here

//     if (head == NULL)
//         return NULL;
//     // creation of dummy nodes
//     Node *head0 = new Node(-1);
//     Node *head1 = new Node(-1);
//     Node *head2 = new Node(-1);

//     Node *temp = head;
//     /// creation of dummy tails
//     Node *temp0 = head0, *temp1 = head1, *temp2 = head2;
//     while (temp != NULL)
//     {
//         if (temp->data == 0)
//         {
//             Node *newnode = new Node(0);
//             temp0->next = newnode;
//             temp0 = newnode;
//         }
//         else if (temp->data == 1)
//             // {
//             Node *newnode = new Node(1);
//         temp1->next = newnode;
//         temp1 = newnode;
//     }
//     else
//     {
//         Node *newnode = new Node(2);
//         temp2->next = newnode;
//         temp2 = newnode;
//     }
//     temp = temp->next;
// }
// // merge linklists

// temp0->next = head1->next;
// if (head1->next == NULL)
// {
//     temp0->next = head2->next;
// }
// else
// {
//     temp1->next = head2->next;
// }
// head = head0->next;
// // delete dummy nodes
// delete head0;
// delete head1;
// delete head2;
// return head;
// }
// }
// ;
// T.C : O(N);
// S.C : O(N);