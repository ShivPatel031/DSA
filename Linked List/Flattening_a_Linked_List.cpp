// Flattening a Linked List gfg

// Given a Linked List of size n, where every node represents a sub-linked-list and contains two pointers:
// (i) a next pointer to the next node,
// (ii) a bottom pointer to a linked list where this node is head.
// Each of the sub-linked-list is in sorted order.
// Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order. 

// Note: The flattened list will be printed using the bottom pointer instead of the next pointer.
// For more clarity have a look at the printList() function in the driver code.

// Examples:

// Input:
// 5 -> 10 -> 19 -> 28
// |     |     |     | 
// 7     20    22   35
// |           |     | 
// 8          50    40
// |                 | 
// 30               45
// Output:  5-> 7-> 8- > 10 -> 19-> 20-> 22-> 28-> 30-> 35-> 40-> 45-> 50.
// Explanation: The resultant linked lists has every node in a single level.(Note: | represents the bottom pointer.)
  
// Input:
// 5 -> 10 -> 19 -> 28
// |          |                
// 7          22   
// |          |                 
// 8          50 
// |                           
// 30              
// Output: 5-> 7-> 8-> 10-> 19-> 22-> 28-> 30-> 50
// Explanation: The resultant linked lists has every node in a single level.(Note: | represents the bottom pointer.)
// Note : In the output section of the above examples the -> represents the bottom pointer.

// Expected Time Complexity: O(n * n * m)
// Expected Auxiliary Space: O(n)

// Constraints:
// 0 <= n <= 50
// 1 <= mi <= 20
// 1 <= Element of linked list <= 103

Node *mergeTwoList(Node *l1,Node *l2)
{
    Node *head=new Node(-1);
    Node *temp=head;
    
    while(l1 && l2)
    {
        if(l1->data <=l2->data)
        {
            temp->bottom=l1;
            temp=l1;
            l1=l1->bottom;
        }
        else
        {
            temp->bottom=l2;
            temp=l2;
            l2=l2->bottom;
        }
    }
    
    if(l1)
    {
        temp->bottom=l1;
    }
    
    if(l2)
    {
        temp->bottom=l2;
    }
    
    
    
    return head->bottom;
}


Node *flatten(Node *root)
{
    if(!root || !root->next)
    {
        return root;
    }
    
    Node *head =root;
    
    while(root->next)
    {
        root=root->next;
        head->next=nullptr;
        head=mergeTwoList(head,root);
    }
    
    return head;
}
