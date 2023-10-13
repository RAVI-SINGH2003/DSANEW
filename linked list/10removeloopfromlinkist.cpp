// Node *floydDetectLoop(Node *head)
// {
//     Node *slow = head, *fast = head;
//     while (slow != NULL && fast != NULL && fast->next != NULL)
//     {
//         slow = slow->next;
//         fast = fast->next->next;
//         if (slow == fast)
//             return fast;
//     }
//     return NULL;
// }

// Node *getStartingNode(Node *head)
// {

//     if (head == NULL)
//         return NULL;
//     Node *fast = floydDetectLoop(head), *slow = head;
//     if (fast == NULL)
//         return NULL;
//     while (slow != fast)
//     {
//         slow = slow->next;
//         fast = fast->next;
//     }
//     return fast;
// }

// Node *removeLoop(Node *head)
// {
//     if (head == NULL)
//         return NULL;

//     Node *startOfLoop = getStartingNode(head);

//     if (startOfLoop == NULL)
//         return head;

//     Node *temp = startOfLoop;

//     while (temp->next != startOfLoop)
//     {
//         temp = temp->next;
//     }

//     temp->next = NULL;
//     return head;
// }


//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


// other implementation of above approach
//     Node *
//     getStartingNode(Node *head)
// {
//     Node *slow = head, *fast = head;

//     while (slow != NULL && fast != NULL && fast->next != NULL)
//     {

//         slow = slow->next;       // Slow moves by 1 step
//         fast = fast->next->next; // Fast moves by two steps

//         // If they meet then there is a loop
//         if (slow == fast)
//         {
//             // To find the starting element where the loop starts

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
// Node *removeLoop(Node *head)
// {
//     if (head == NULL)
//         return NULL;
//     Node *starting = getStartingNode(head);
//     if (starting == NULL)
//         return head;
//     Node *temp = starting;
//     while (temp->next != starting)
//     {
//         temp = temp->next;
//     }
//     temp->next = NULL;
//     return head;
// }
