//  Merge Two Sorted Lists leetcode 21

// You are given the heads of two sorted linked lists list1 and list2.

// Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

// Return the head of the merged linked list.

// Example 1:

// Input: list1 = [1,2,4], list2 = [1,3,4]
// Output: [1,1,2,3,4,4]
  
// Example 2:

// Input: list1 = [], list2 = []
// Output: []
  
// Example 3:

// Input: list1 = [], list2 = [0]
// Output: [0] 

// Constraints:

// The number of nodes in both lists is in the range [0, 50].
// -100 <= Node.val <= 100
// Both list1 and list2 are sorted in non-decreasing order.

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
{
    ListNode *head=nullptr,*temp=nullptr;

    while(list1 && list2)
    {    
        if(list1->val<=list2->val)
        {
            if(!head)
            {
                head=list1;
                temp=list1;
            }
            else
            {
                temp->next=list1;
                temp=temp->next;
            }
            
            list1=list1->next;
        }
        else
        {
            if(!head)
            {
                head=list2;
                temp=list2;
            }
            else
            {
                temp->next=list2;
                temp=temp->next;
            }
            list2=list2->next;
        }
    }

   if(temp)
   { 
        if(list1)
        {
            temp->next=list1;
        }
        else
        {
            temp->next=list2;
        }

        return head;
    }
    else
    {
        if(list1)
        {
            return list1;
        }
        else
        {
            return list2;
        }
    }
}
