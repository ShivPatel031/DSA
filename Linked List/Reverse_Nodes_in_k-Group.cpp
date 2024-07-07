// Reverse Nodes in k-Group leetcode 25

// Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

// k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

// You may not alter the values in the list's nodes, only nodes themselves may be changed.

// Example 1:

// Input: head = [1,2,3,4,5], k = 2
// Output: [2,1,4,3,5]
  
// Example 2:

// Input: head = [1,2,3,4,5], k = 3
// Output: [3,2,1,4,5]
 
// Constraints:

// The number of nodes in the list is n.
// 1 <= k <= n <= 5000
// 0 <= Node.val <= 1000

ListNode* reverseKGroup(ListNode* head, int k) 
{
    ListNode *temp=head,*temp2,*temp3,*past1;
    
    while (temp)
    {
        int group=k;
        temp2=temp;

        while (group>1)
        {
            group--;
            temp2=temp2->next;
            if (!temp2)
            {
                return head;
            }
        }

        temp3=temp2->next;
        temp2->next=nullptr;
        ListNode *past=nullptr,*present=temp;

        while (present)
        {
            ListNode *future=present->next;
            present->next=past;
            past=present;
            present=future;
        }

        if (temp== head)
        {
            head=past;  
        }
        else
        {
            past1->next=past;
        }

        if (!temp3)
        {
            return head;
        }

        temp->next=temp3;
        past1=temp;
        temp=temp->next;

    }
    
    return head;
    
}
