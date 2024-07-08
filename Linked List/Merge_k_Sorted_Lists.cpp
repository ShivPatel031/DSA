// Merge k Sorted Lists leetcode 23

// You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

// Merge all the linked-lists into one sorted linked-list and return it.

// Example 1:

// Input: lists = [[1,4,5],[1,3,4],[2,6]]
// Output: [1,1,2,3,4,4,5,6]
// Explanation: The linked-lists are:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// merging them into one sorted list:
// 1->1->2->3->4->4->5->6
  
// Example 2:

// Input: lists = []
// Output: []
  
// Example 3:

// Input: lists = [[]]
// Output: []
 
// Constraints:

// k == lists.length
// 0 <= k <= 104
// 0 <= lists[i].length <= 500
// -104 <= lists[i][j] <= 104
// lists[i] is sorted in ascending order.
// The sum of lists[i].length will not exceed 104.

// optimize way using merge sort
ListNode* twoSortedList(ListNode* list1,ListNode* list2)
{
    if(!list1)
    {
        return list2;
    }
    else if(!list2)
    {
        return list1;
    }
    
    ListNode *head=new ListNode(-1),*temp=head; 

    while(list1 && list2)
    {
        if(list1->val <= list2->val)
        {
            
            temp->next=list1;
            temp=list1;
            list1=list1->next;
        }
        else
        {
            temp->next=list2;
            temp=list2;
            list2=list2->next;
        }
    }

    if(list1)
    {
        temp->next=list1;
    }
    
    if(list2)
    {
        temp->next=list2;
    }

    return head->next;
}

void mergeSort(vector<ListNode*>& lists,int start,int end)
{
    if(start>=end)
    {
        return;
    }

    int mid=start + (end-start)/2;

    mergeSort(lists,start,mid);
    mergeSort(lists,mid+1,end);

    lists[start]=twoSortedList(lists[start],lists[mid+1]);

}

ListNode* mergeKLists(vector<ListNode*>& lists) 
{
    if(lists.size()==0) return nullptr;
    
    mergeSort(lists,0,lists.size()-1);
    ListNode *head=lists[0];

    return head;
}

// accepted but timecomplexsity is highe
// ListNode* twoSortedList(ListNode* list1,ListNode* list2)
// {
//     if(!list1)
        // {
        //     return list2;
        // }
        // else if(!list2)
        // {
        //     return list1;
        // }
        
        // ListNode *head=new ListNode(-1),*temp=head; 
    
        // while(list1 && list2)
        // {
        //     if(list1->val <= list2->val)
        //     {
                
        //         temp->next=list1;
        //         temp=list1;
        //         list1=list1->next;
        //     }
        //     else
        //     {
        //         temp->next=list2;
        //         temp=list2;
        //         list2=list2->next;
        //     }
        // }
    
        // if(list1)
        // {
        //     temp->next=list1;
        // }
        
        // if(list2)
        // {
        //     temp->next=list2;
        // }
    
        // return head->next;
//     }

//     return head;
// }
// ListNode* mergeKLists(vector<ListNode*>& lists) 
// {
//     if(lists.size()==0) return nullptr;
    
//     ListNode *head=lists[0];

//     for(int i = 1 ;i<lists.size();i++)
//     {
//         head=twoSortedList(head,lists[i]);
//     }

//     return head;
// }
