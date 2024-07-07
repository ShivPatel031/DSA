// Intersection Point in Y Shaped Linked Lists GFG

// Given two singly linked lists of size N and M, write a program to get the point where two linked lists intersect each other.

// Example 1:

// Input:
// LinkList1 = 3->6->9->common
// LinkList2 = 10->common
// common = 15->30->NULL
// Output: 15
// Explanation:
// Y ShapedLinked List

// Example 2:

// Input: 
// Linked List 1 = 4->1->common
// Linked List 2 = 5->6->1->common
// common = 8->4->5->NULL
// Output: 8
// Explanation: 
     
// Your Task:
// You don't need to read input or print anything. The task is to complete the function intersetPoint() which takes the pointer to the head of linklist1(head1) and linklist2(head2) as input parameters and returns data value of a node where two linked lists intersect. If linked list do not merge at any point, then it should return -1.
// Challenge : Try to solve the problem without using any extra space.

// Expected Time Complexity: O(N+M)
// Expected Auxiliary Space: O(1)

// Constraints:
// Length of Both linkedList before intersection(if any) is greater than 0.
// 1 ≤ N + M ≤ 2*105
// -1000 ≤ value ≤ 1000

// optimize way with one loop
int intersectPoint(Node* head1, Node* head2)
{
    Node *temp1=head1,*temp2=head2;
    
    while(temp1 && temp2 && temp1->next!=temp2->next)
    {
        temp1=temp1->next;
        temp2=temp2->next;
        
        if(!temp1)
        {
            temp1=head2;
        }
        if(!temp2)
        {
            temp2=head1;
        }
    }
    
    if(temp1->next)return temp1->next->data;
    
    return -1;
}

// but use more then one loop
// int intersectPoint(Node* head1, Node* head2)
// {
//     Node *temp1=head1,*temp2=head2;
//     int length1=0,length2=0;
    
//     while(temp1 || temp2)
//     {
//         if(temp1)
//         {
//             temp1=temp1->next;
//             length1++;
//         }
        
//         if(temp2)
//         {
//             temp2=temp2->next;
//             length2++;
//         }
//     }
    
//     temp1=head1;
//     temp2=head2;
    
//     if(length2>=length1)
//     {
//         int count=length2-length1;
        
//         while(count--)
//         {
//             temp2=temp2->next;
//         }
//     }
//     else
//     {
//         int count=length1-length2;
        
//         while(count--)
//         {
//             temp1=temp1->next;
//         }
//     }
    
//     while(temp2 && temp1)
//     {
//         if(temp2==temp1)
//         {
//             return temp2->data;
//         }
        
//         temp2=temp2->next;
//         temp1=temp1->next;
//     }
//     return -1;
// }
