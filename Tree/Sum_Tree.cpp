// Sum Tree GFG

// Given a Binary Tree. Check for the Sum Tree for every node except the leaf node. Return true if it is a Sum Tree otherwise, return false.
// A SumTree is a Binary Tree where the value of a node is equal to the sum of the nodes present in its left subtree and right subtree. An empty tree is also a Sum Tree as the sum of an empty tree can be considered to be 0. A leaf node is also considered a Sum Tree.

// Examples :

// Input:
//     3
//   /   \    
//  1     2
// Output: true
// Explanation: The sum of left subtree and right subtree is 1 + 2 = 3, which is the value of the root node. Therefore,the given binary tree is a sum tree.
// Input:
//           10
//         /    \
//       20      30
//     /   \ 
//    10    10
// Output: false
// Explanation: The given tree is not a sum tree. For the root node, sum of elements in left subtree is 40 and sum of elements in right subtree is 30. Root element = 10 which is not equal to 30+40.
// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(Height of the Tree)

// Constraints:
// 1 ≤ number of nodes ≤ 105
// 1 ≤ node value ≤ 105

int SumTree(Node* root,bool &flag)
{
    if(!root) return 0;
    
    int sum1=INT_MIN,sum2=INT_MIN;
    
    
    if(flag)
    {
        if(root->right) sum1=SumTree(root->right,flag);
        if(root->left) sum2=SumTree(root->left,flag);
    }
    else
    {
        return 0;
    }
    
    if(sum1==INT_MIN && sum2==INT_MIN) return root->data;
    
    else if(sum1==INT_MIN && sum2==root->data) return sum2+root->data;
    
    else if(sum2==INT_MIN && sum1==root->data) return sum1+root->data;
    
    else if(sum2+sum1==root->data) return sum1+sum2+root->data;
    
    else 
    {
        flag=0;
        return 0;
    }
}

bool isSumTree(Node* root) 
{    
    if(!root) return 1;
    
    bool flag=1;
    
    SumTree(root,flag);
    
    return flag;
}