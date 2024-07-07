// Add Two Numbers leetcode 2 GFG

// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

// Example 1:

// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [7,0,8]
// Explanation: 342 + 465 = 807.
  
// Example 2:

// Input: l1 = [0], l2 = [0]
// Output: [0]
// Example 3:

// Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
// Output: [8,9,9,9,0,0,0,1]
 
// Constraints:

// The number of nodes in each linked list is in the range [1, 100].
// 0 <= Node.val <= 9
// It is guaranteed that the list represents a number that does not have leading zeros.

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
{
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

    return head->next;
}

// what i first thought
// ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//     ListNode *temp1=l1,*temp2=l2,*head=nullptr,*temp3;
//     int carry=0;

//     while(temp1 || temp2)
//     {
//         int n =0;

//         if(temp1) n+=temp1->val;
        
//         if(temp2) n+=temp2->val;

//         if(carry) n+=carry;

//         if(n<10)
//         {
//             carry=0;
//         }
//         else
//         {
//             carry=1;
//             n=n%10;
//         }

//         if(!head)
//         {
//             head=new ListNode(n);
//             temp3=head;
//         }
//         else
//         {
//             ListNode *newNode = new ListNode(n);
//             temp3->next=newNode;
//             temp3=newNode;
//         }
        
//         if(temp1)
//         temp1=temp1->next;

//         if(temp2)
//         temp2=temp2->next;
//     }

//     if(carry)
//     {
//         ListNode *newNode = new ListNode(carry);
//         temp3->next=newNode;  
//     }

//     return head;
// }
