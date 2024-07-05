// Rotate List leetcode 61 GFG

// Given the head of a linked list, rotate the list to the right by k places.

// Example 1:

// Input: head = [1,2,3,4,5], k = 2
// Output: [4,5,1,2,3]
  
// Example 2:

// Input: head = [0,1,2], k = 4
// Output: [2,0,1]
 
// Constraints:

// The number of nodes in the list is in the range [0, 500].
// -100 <= Node.val <= 100
// 0 <= k <= 2 * 109

ListNode* rotateRight(ListNode* head, int k) 
{
    if (!head or !head->next or k==0)
    {
        return head;
    }

    ListNode *temp=head,*prev=nullptr,*tail=nullptr;
    int length=0;
    
    while (temp)
    {
        length+=1;
        tail=temp;
        temp=temp->next;
    }

    if(length<k)
    {
        k=k%length;
        
    }

    if(k==0)return head;

    length-=k;
    temp=head;

    while(length--)
    {
        prev=temp;
        temp=temp->next;
    }

    if(prev)
    {
        prev->next=nullptr;
        tail->next=head;
        head=temp;
    }
   
    return head;
}
