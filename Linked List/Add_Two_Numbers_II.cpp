// Add Two Numbers II leetcode 445

// You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

// Example 1:

// Input: l1 = [7,2,4,3], l2 = [5,6,4]
// Output: [7,8,0,7]
  
// Example 2:

// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [8,0,7]
  
// Example 3:

// Input: l1 = [0], l2 = [0]
// Output: [0]
 
// Constraints:

// The number of nodes in each linked list is in the range [1, 100].
// 0 <= Node.val <= 9
// It is guaranteed that the list represents a number that does not have leading zeros.

ListNode* reverseList(ListNode* l1)
{
    if(!l1 || !l1->next)
    {
        return l1;
    }
    ListNode *past=nullptr,*present=l1,*future=l1->next;

    while(present)
    {
        present->next=past;
        past=present;
        present=future;
        if(future)
        future=future->next;
    }

    return past;
}


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
{
    l1=reverseList(l1);
    l2=reverseList(l2);

    ListNode *temp1=l1,*temp2=l2;
    ListNode *head=new ListNode(-1);
    ListNode *temp3=head;
    int carry=0;
    int sum = 0;

    while(temp1 || temp2)
    {
        sum=carry;

        if(temp1) sum+=temp1->val;
        
        if(temp2) sum+=temp2->val;

        ListNode *newNode = new ListNode(sum%10);
        carry=sum/10;

        temp3->next=newNode;
        temp3=newNode;
        
        if(temp1)
        temp1=temp1->next;

        if(temp2)
        temp2=temp2->next;
    }

    if(carry)
    {
        ListNode *newNode = new ListNode(carry);
        temp3->next=newNode;  
    }

    head=reverseList(head->next);

    return head;    
}
