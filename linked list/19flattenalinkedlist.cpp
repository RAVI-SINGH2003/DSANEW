// //Approach :  TC : O()
// Node* merge(Node*down, Node* right)  
// {
//     if (down == NULL)
//         return right;
//     if (right == NULL)
//         return down;
//     Node *head = new Node(-1);
//     Node *tail = head;
//     while (down != NULL && right != NULL)
//     {
//         if (down->data < right->data)
//         {
           
//             tail->bottom = down;
//             tail = down;
//             down = down->bottom;
//         }
//         else
//         {
//              tail->bottom = right;
//             tail = right;
//             right = right->bottom;
//         }
//     }
//     while (down != NULL)
//     {
//         tail->bottom = down;
//         tail = down;
//         down = down->bottom;
//     }
//     while (right != NULL)
//     {
//         tail->bottom = right;
//         tail = right;
//         right = right->bottom;
//     }
//     head = head->bottom;
//     return head;
// }
// Node *flatten(Node *head)
// {
//     if(head==NULL || head->next==NULL ) return head;
//     Node * down = head;
//     Node * righthead = head ->next;
//     down->next = NULL;
//     Node*right = flatten(righthead);
//     Node * ans =merge(down ,right);
//     return ans;
// }
