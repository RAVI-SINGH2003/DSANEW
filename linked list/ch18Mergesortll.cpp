// Approach TC : O(N *LOGN) SC : O(1)
 // THIS fun will return mid like if ll is 1->2->3 it will return 2 but if 1->2->3->4 return 3 as mid
 //in case if i want to get 2 as middle element here i will use my old wala middle function .
//  node *findMid(node *head) 
// {
//     node *slow = head, *fast = head->next;
//     while (fast != NULL && fast->next != NULL)
//     {
//         slow = slow->next;
//         fast = fast->next->next;
//     }
//     return slow;
// }
// node *merge(node *left, node *right)
// {
//     if (left == NULL)
//         return right;
//     if (right == NULL)
//         return left;

//     node *head = new node(-1);
//     node *tail = head;
//     while (left != NULL && right != NULL)
//     {
//         if (left->data > right->data)
//         {
//             tail->next = right;
//             tail = right;
//             right = right->next;
//         }
//         else
//         {

//             tail->next = left;
//             tail = left;
//             left = left->next;
//         }
//     }
//     while (left != NULL)
//     {

//         tail->next = left;
//         tail = left;
//         left = left->next;
//     }
//     while (right != NULL)
//     {
//         tail->next = right;
//         tail = right;
//         right = right->next;
//     }
//     head = head->next;
//     return head;
// }
// node *mergeSort(node *head)
// {
//     // Write your code here.
//     if (head == NULL || head->next == NULL)
//         return head;
//     // break ll in two halves
//     node *mid = findMid(head);
//     node *left = head;
//     node *right = mid->next;
//     mid->next = NULL;
//     // recursive calls to both halves
//     left = mergeSort(left);
//     right = mergeSort(right);
//     // merge both left and right halves
//     node *result = merge(left, right);
//     return result;
// }
