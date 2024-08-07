// Sorted Link List to BST GFG leetcode 109

// Given a Singly Linked List which has data members sorted in ascending order. Construct a Balanced Binary Search Tree which has same data members as the given Linked List.
// Note: There might be nodes with the same value.

// Example 1:

// Input:
// Linked List: 1->2->3->4->5->6->7
// Output:
// 4 2 1 3 6 5 7
// Explanation :
// The BST formed using elements of the 
// linked list is,
//         4
//       /   \
//      2     6
//    /  \   / \
//   1   3  5   7  
// Hence, preorder traversal of this 
// tree is 4 2 1 3 6 5 7
// Example 2:

// Input:
// Linked List : 1->2->3->4
// Ouput:
// 3 2 1 4
// Explanation:
// The BST formed using elements of the 
// linked list is,
//       3   
//     /  \  
//    2    4 
//  / 
// 1
// Hence, the preorder traversal of this 
// tree is 3 2 1 4
// Your task :
// You don't have to read input or print anything. Your task is to complete the function sortedListToBST(), which takes head of the linked list as an input parameter and returns the root of the BST created.
 
// Expected Time Complexity: O(N), N = number of Nodes
// Expected Auxiliary Space: O(N), N = number of Nodes
 
// Constraints:
// 1 ≤ Number of Nodes ≤ 106
// 1 ≤ Value of each node ≤ 106


TNode* createBST(vector<int> &ans,int low,int high)
{
    if(low>high) return nullptr;
    
    int mid = (high+low+1)/2;
    
    TNode *temp=new TNode(ans[mid]);
    
    temp->left = createBST(ans,low,mid-1);
    temp->right = createBST(ans,mid+1,high);
    
    return temp;
}

TNode* sortedListToBST(LNode *head) 
{
    vector<int> t;
    LNode *temp=head;
    
    while(temp)
    {
        t.push_back(temp->data);
        temp=temp->next;
    }
    
    return createBST(t,0,t.size()-1);
}
