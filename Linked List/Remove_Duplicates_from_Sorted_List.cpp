// Remove Duplicates from Sorted List leetcode 83

// Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

// Example 1:

// Input: head = [1,1,2]
// Output: [1,2]
  
// Example 2:

// Input: head = [1,1,2,3,3]
// Output: [1,2,3]

// Constraints:

// The number of nodes in the list is in the range [0, 300].
// -100 <= Node.val <= 100
// The list is guaranteed to be sorted in ascending order.

// using one pointer
ListNode* deleteDuplicates(ListNode* head) 
{
    if (!head or !head->next)
    {
        return head;
    }

    ListNode* temp=head;
    
    while (temp && temp->next)
    {
        if (temp->val == temp->next->val)
        {
            temp->next=temp->next->next;
        }
        else
        {
        temp=temp->next;
        }
    }
    return head;
}


// but use two pointer
// ListNode* deleteDuplicates(ListNode* head) 
// {
//     if (!head or !head->next)
//     {
//         return head;
//     }

//     ListNode* temp=head->next,*unique=head;

//     while (temp)
//     {
//         if(temp->val!=unique->val)
//         {
//             unique->next=temp;
//             unique=temp;
//             temp=temp->next;
//         }
//         else
//         {
//             ListNode *deleteNode = temp;
//             temp=temp->next;
//             delete deleteNode;
//         }
//     }
    
//     unique->next=nullptr;
//     return head;
// }
