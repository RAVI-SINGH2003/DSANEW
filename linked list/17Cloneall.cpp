// Approach - 1 TC: O(N) SC : O(N)
//  STEPS :
// 1.Clone ll with next pointers only.
// 2.map the nodes of original ll with nodes in cloned ll
// 3.Clone the random pointers also by mappnig
//
//  void insertAtTail(Node * &head , Node * &tail ,int d){
//          Node * temp = new Node(d)
//          if(head==NULL && tail==NULL){
//            head= tail =temp;
//          }
//          else
//          {
//              tail->next = temp;
//              tail =temp;

//         }
//     }
//  Node *copyList(Node *head)
//     {
//
//        Node * cloneHead  = NULL,*cloneTail = NULL;
//        Node* curr =head;
//        //cloning ll with next pointers
//
//        while(curr!=NULL){
//            insertAtTail(cloneHead,cloneTail,curr->data);
//            curr= curr->next;
//        }
//
//       /*mapping corresponding nodes8 */
//
//         unordered_map<Node *, Node *> mapping;
//         curr = head ; Node * curr1 = cloneHead;
//         while(curr!=NULL &&curr1!=NULL){
//         mapping[curr]  = curr1;
//         curr= curr->next;
//         curr1=curr1->next;
//         }
//         //cloning random pointers also
//         curr1 = cloneHead;
//         curr=  head;
//         while(curr!=NULL &&curr1!=NULL ){

//         curr1->arb = mapping[curr -> arb];
//         curr1=curr1->next;
//         curr=curr->next;

//         }

//         return cloneHead;
//     }

// Approach 2 : TC :O(n) SC:o(n)
// steps :
// eg - > 1->2->3->4->NULL
// arb pointers= 1->3 2->1 3->5 4->3
// 1.clone ll with next pointers only.
// 2.cut nodes from original ll and point to coreesponding nodes in cloned ll. see image
// 3.set random pointers
// 4. revert back the changes in step 2
// void insertAtTail(Node *&head, Node *&tail, int d)
// {
//     Node *temp = new Node(d);
//     if (head == NULL && tail == NULL)
//     {
//         head = tail = temp;
//     }
//     else
//     {
//         tail->next = temp;
//         tail = temp;
//     }
// }
// Node *copyList(Node *head)
// {
//     Node *cloneHead = NULL, *cloneTail = NULL;
//     Node *curr = head;
//     // cloning ll with next pointers
//     while (curr != NULL)
//     {
//         insertAtTail(cloneHead, cloneTail, curr->data);
//         curr = curr->next;
//     }
//     //  cut nodes from original ll and point to coreesponding nodes in cloned ll. see image
//     curr = head;
//     Node *curr1 = cloneHead;
//     while (curr != NULL && curr1 != NULL)
//     {

//         Node *forward = curr->next;
//         curr->next = curr1;
//         curr = forward;
//         forward = curr1->next;
//         curr1->next = curr;
//         curr1 = forward;
//     }

//     // Cloning random pointers
//     curr = head;
//     curr1 = cloneHead;
//     while (curr != NULL && curr1 != NULL)
//     {
//         if (curr->arb != NULL)
//         {
//             curr1->arb = curr->arb->next;
//         }
//         curr1->arb = curr->arb->next;
//         curr = curr1->next;
//         if (curr != NULL)
//             curr1 = curr->next;
//     }

//     // reverting back changes;
//     curr = head;
//     curr1 = cloneHead;
//     while (curr != NULL && curr1 != NULL)
//     {
//         Node *forward = curr->next->next;
//         curr->next = forward;
//         curr = forward;
//         if (forward != NULL)
//         {
//             Node *forward1 = forward->next;
//             curr1->next = forward1;
//             curr1 = forward1;
//         }
//     }
//     return cloneHead;
// }
