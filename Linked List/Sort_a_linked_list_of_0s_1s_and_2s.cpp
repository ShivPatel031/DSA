// Sort a linked list of 0s, 1s and 2s GFG

// Given a linked list of N nodes where nodes can contain values 0s, 1s, and 2s only. The task is to segregate 0s, 1s, and 2s linked list such that all zeros segregate to head side, 2s at the end of the linked list, and 1s in the mid of 0s and 2s.

// Example 1:

// Input:
// N = 8
// value[] = {1,2,2,1,2,0,2,2}
// Output: 0 1 1 2 2 2 2 2
// Explanation: All the 0s are segregated
// to the left end of the linked list,
// 2s to the right end of the list, and
// 1s in between.
// Example 2:

// Input:
// N = 4
// value[] = {2,2,0,1}
// Output: 0 1 2 2
// Explanation: After arranging all the
// 0s,1s and 2s in the given format,
// the output will be 0 1 2 2.
// Your Task:
// The task is to complete the function segregate() which segregates the nodes in the linked list as asked in the problem statement and returns the head of the modified linked list. The printing is done automatically by the driver code.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(N).

// Constraints:
// 1 <= N <= 106

Node* segregate(Node *head) 
{ 
    Node *onePointer=nullptr,*twoPointer=nullptr,*zeroPointer=nullptr;
    Node *temp=head,*onehead=nullptr,*twohead=nullptr,*zerohead=nullptr;
    
    while(temp)
    {
        if(temp->data==0)
        {
            if(zeroPointer)
            {
                zeroPointer->next=temp;
                zeroPointer=zeroPointer->next;
            }
            else
            {
                zeroPointer=temp;
                zerohead=temp;
            }
        }
        else if(temp->data==1)
        {
          if(onePointer)
            {
                onePointer->next=temp;
                onePointer=onePointer->next;
            }
            else
            {
                onePointer=temp;
                onehead=temp;
            } 
        }
        else
        {
            if(twoPointer)
            {
                twoPointer->next=temp;
                twoPointer=twoPointer->next;
            }
            else
            {
                twoPointer=temp;
                twohead=temp;
            }
        }
        temp=temp->next;
    }
    
    if(zeroPointer)
    zeroPointer->next=nullptr;
    
    if(onePointer)
    onePointer->next=nullptr;
    
    if(twoPointer)
    twoPointer->next=nullptr;
    
    if(zerohead)
    {
        head=zerohead;
    }
    
    if(onehead)
    {
        if(zerohead)
        {
          zeroPointer->next=onehead; 
        }
        else
        {
            head=onehead;
        }
    }
    
    if(twohead)
    {
        if(zerohead && !onehead)
        {
            zeroPointer->next=twohead;
        }
        else if(onehead)
        {
            onePointer->next=twohead;
        }
        else
        {
            head=twohead;
        }
    }
    
    return head;
    
}
