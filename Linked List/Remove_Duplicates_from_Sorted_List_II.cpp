// Remove Duplicates from Sorted List II leetcode 82

// Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

// Example 1:

// Input: head = [1,2,3,3,4,4,5]
// Output: [1,2,5]

// Example 2:

// Input: head = [1,1,1,2,3]
// Output: [2,3]

// Constraints:

// The number of nodes in the list is in the range [0, 300].
// -100 <= Node.val <= 100
// The list is guaranteed to be sorted in ascending order.

ListNode* deleteDuplicates(ListNode* head) 
    {
        ListNode *temp = head, *past = nullptr;

        while (temp and temp->next) 
        {
            if (temp->val == temp->next->val) 
            {
                ListNode* temp2 = temp->next;
                while (temp2->next and temp2->next->val == temp->val) 
                {
                    temp2 = temp2->next;
                }
                if (!temp2->next)
                {
                    if (past)
                    {
                        past->next=nullptr;
                    }
                    else
                    {
                        head=nullptr;
                    }

                    return head;
                }
                if (past) 
                {
                    past->next = temp2->next;
                    temp=past->next;
                } 
                else 
                {
                    head = temp2->next;
                    temp=head;
                }
            }
            else
            {
                past = temp;
                temp = temp->next;
            }
        }
        return head;
    }
