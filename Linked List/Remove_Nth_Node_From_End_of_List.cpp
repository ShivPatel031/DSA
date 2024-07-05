// Remove Nth Node From End of List leetcode 19 GFG

// Given the head of a linked list, remove the nth node from the end of the list and return its head.

// Example 1:

// Input: head = [1,2,3,4,5], n = 2
// Output: [1,2,3,5]
  
// Example 2:

// Input: head = [1], n = 1
// Output: []
  
// Example 3:

// Input: head = [1,2], n = 1
// Output: [1]
 
// Constraints:

// The number of nodes in the list is sz.
// 1 <= sz <= 30
// 0 <= Node.val <= 100
// 1 <= n <= sz

ListNode* removeNthFromEnd(ListNode* head, int n) 
{
    int count = 0;
    ListNode *temp = head;
    while(temp)
    {
        count++;
        temp=temp->next;
    }

    count-=n;

    if(!count)
    {
        temp=head;
        head=head->next;
        delete temp;
        return head;
    }  

    ListNode *current=head;
    count--;
    
    while(count--)
    {
        current=current->next;
    }  

    temp=current->next;
    current->next=temp->next;
    delete temp;

    return head;
}
