// Middle of the Linked List leetcode 876

ListNode* middleNode(ListNode* head) 
{
    if(!head || !head->next)
    {
        return head;
    }

    ListNode *slow=head,*fast=head;
    
    while(fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    }

    return slow;
}
