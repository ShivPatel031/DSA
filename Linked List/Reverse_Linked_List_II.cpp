// Reverse Linked List II leetcode 92

// Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.
  
// Example 1:


// Input: head = [1,2,3,4,5], left = 2, right = 4
// Output: [1,4,3,2,5]
  
// Example 2:

// Input: head = [5], left = 1, right = 1
// Output: [5]
 
// Constraints:

// The number of nodes in the list is n.
// 1 <= n <= 500
// -500 <= Node.val <= 500
// 1 <= left <= right <= n

// most optimize
ListNode* reverseBetween(ListNode* head, int left, int right) 
{
    if (!head || left == right) 
    {
        return head;
    }

    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* prev = dummy;

    for (int i = 0; i < left - 1; i++) 
    {
        prev = prev->next;
    }

    ListNode* cur = prev->next;

    for (int i = 0; i < right - left; i++) 
    {
        ListNode* temp = cur->next;
        cur->next = temp->next;
        temp->next = prev->next;
        prev->next = temp;
    }

    return dummy->next; 
}

// too long but accepted
// ListNode* reverseBetween(ListNode* head, int left, int right) 
// {
//     if(!head || !head->next || left==right)
//     {
//         return  head;
//     } 

//     int length = 0;
//     ListNode *temp=head;

//     while(temp)
//     {
//         length++;
//         temp=temp->next;
//     }   

//     if(left > length || right>length)
//     {
//         return head;
//     }

//     ListNode *leftSide=head,*rightSide=head;
//     int count=right-left+1,l=left,r=right;

//     while(right--)
//     {
//         if(left>2)
//         {
//             left--;
//             leftSide=leftSide->next;
//             rightSide=leftSide;
//         }
//         else
//         {
//             rightSide=rightSide->next;
//         }
//     }
//     cout<<leftSide->val<<' ';
//     if(rightSide) cout<<rightSide->val<<endl;
//     ListNode *past,*present,*future;
//     if(l==1)
//     {
//        past=rightSide;
//        present=leftSide;
//        future=present->next; 
//     }
//     else{
//         past=rightSide;
//         present=leftSide->next;
//         future=present->next;
//     }

//     while(count--)
//     {
//         present->next=past;
//         past=present;
//         present=future;
//         if(future)
//         future=future->next;
//     }

//     if(!(l==1)){
//         leftSide->next=past;
//     }
//     else
//     {
//         head=past;
//     }

//     return head;
// }
