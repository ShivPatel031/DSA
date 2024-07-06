// Remove loop in Linked List

// Given head of a linked list that may contain a loop.  A loops means that the last node of the linked list is connected back to a node in the same list.  So if next of the last node is null. then there is no loop.  Remove loop from the linked list, if it is present (we mainly need to make next of the last node as null). Otherwise keep the linked list as it is.

// The following is internal representation of every test case (three inputs).
// n : Size of the linked list
// value[] :  An array of values that represents values of nodes.
// pos (1 based index) :  Position of the node to which the last node links back if there is a loop. If the linked list does not have any loop, then pos = 0.

// The generated output will be 1 if your submitted code is correct.

// Examples:

// Input: n = 3, value[] = {1,3,4}, pos = 2
// Output: 1
// Explanation: The linked list looks like

// A loop is present. If you remove it successfully, the answer will be 1. 
// Input: n = 4, value[] = {1,8,3,4}, pos = 0
// Output: 1
// Explanation: 

// The Linked list does not contains any loop. 
// Input: n = 4, value[] = {1,2,3,4}, pos = 1
// Output: 1
// Explanation: The linked list looks like 

// A loop is present. If you remove it successfully, the answer will be 1. 
// Expected time complexity: O(n)
// Expected auxiliary space: O(1)

// Constraints:
// 1 ≤ n ≤ 10^4

void removeLoop(Node* head)
{
    Node *fast=head,*slow=head,*past;
    
    while(fast && fast->next)
    {
        past=slow;
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow)
        {
            break;
        }
    }
    
    if(fast && fast->next)
    {
        fast=head;
    
        while(fast != slow)
        {
            fast=fast->next;
            past=slow;
            slow=slow->next;
        }
        
        past->next=nullptr;
    }
}
