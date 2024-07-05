// Palindrome Linked List leetcode 234 GFG

// Given the head of a singly linked list, return true if it is a 
// palindrome
//  or false otherwise.
  
// Example 1:

// Input: head = [1,2,2,1]
// Output: true
  
// Example 2:

// Input: head = [1,2]
// Output: false 

// Constraints:

// The number of nodes in the list is in the range [1, 105].
// 0 <= Node.val <= 9

ListNode* reverseList(ListNode *head)
{   
    if(!head or !head->next)
    {
        return head;
    }

    ListNode *past=nullptr,*present=head,*future=head->next;

    while(present)
    {
        present->next=past;
        past=present;
        present=future;
        if(future)future=future->next;
    }

    return past;
}

bool isPalindrome(ListNode* head) 
{
    ListNode *fast=head,*slow=head;

    while(fast->next && fast->next->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    }

    ListNode *temp = reverseList(slow->next);
    fast=head;

    while(temp)
    {
        if(temp->val!=fast->val)
        {
            return false;
        }
        temp=temp->next;
        fast=fast->next;
    }

    return true;
}

// without reverse function 
// bool isPalindrome(ListNode* head) 
// {
//     ListNode *fast=head,*slow=head;

//     while(fast->next && fast->next->next)
//     {
//         slow=slow->next;
//         fast=fast->next->next;
//     }

//     if(!slow->next) return true;
//     ListNode *past=nullptr,*present=slow->next,*future=slow->next->next;

//     while(present)
//     {
//         present->next=past;
//         past=present;
//         present=future;
//         if(future)future=future->next;
//     }
    
//     ListNode *temp=past;
//     fast=head;

//     while(temp)
//     {
//         if(temp->val!=fast->val)
//         {
//             return false;
//         }
//         temp=temp->next;
//         fast=fast->next;
//     }

//     return true;
// }

// but space complexty is one
// bool isPalindrome(ListNode* head) {

//     string s;
//     ListNode *temp=head;
//     while (temp){
//         s+=to_string(temp->val);
//         temp=temp->next;
//     }
//     int n=s.length();
//     int i=0;
//     while ( i < n){
//        if ( s[i] != s[n-1]){
//            return false;
//        }
//        n--;
//        i++;
//     }
    
//     return true;
// }
