// Reverse Linked List leetcode 206

// Given the head of a singly linked list, reverse the list, and return the reversed list.
  
// Example 1:


// Input: head = [1,2,3,4,5]
// Output: [5,4,3,2,1]
  
// Example 2:

// Input: head = [1,2]
// Output: [2,1]
// Example 3:

// Input: head = []
// Output: []

// Constraints:

// The number of nodes in the list is the range [0, 5000].
// -5000 <= Node.val <= 5000

ListNode* reverseList(ListNode* head) 
{
    if (!head){ return nullptr;}
    else if(!head->next){return head;}

    ListNode *past=nullptr,*present = head,*future = head->next; 
    while(present)
    {
        present->next = past;
        past=present;
        present=future;
        if(future)
        future=future->next;
    }

    return past;  
}


// using rrecursion

ListNode* reverseList(ListNode* head) 
{
    if(!head || !head->next)
    {
        return head;
    }

    ListNode *curr = head->next,*past=head;
    head=reverseList(curr);

    curr->next=past;
    past->next=nullptr;
    
    return head; 
}

// another one
ListNode* reverse(ListNode* curr,ListNode* prev)
{
    if(curr)
    {
      return prev;
    }
  
    ListNode *fu = curr->next;
    curr->next = prev;
    return reverse(fu,curr);
}

ListNode* reverseList(ListNode* head) 
{ 
    return reverse(head,nullptr); 
}
