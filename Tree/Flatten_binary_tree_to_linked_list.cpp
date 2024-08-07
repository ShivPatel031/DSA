// Flatten binary tree to linked list GFG leetCode 114

// Given the root of a binary tree, flatten the tree into a "lLinked list":

// The "linked list" should use the same Node class where the right child pointer points to the next node in the list and the left child pointer is always null.
// The "linked list" should be in the same order as a pre-order traversal of the binary tree.
// Example 1:

// Input : 
//           1
//         /   \
//        2     5
//       / \     \
//      3   4     6
// Output :
// 1 2 3 4 5 6 
// Explanation: 
// After flattening, the tree looks 
// like this
//     1
//      \
//       2
//        \
//         3
//          \
//           4
//            \
//             5
//              \
//               6 
// Here, left of each node points 
// to NULL and right contains the 
// next node in preorder.The inorder 
// traversal of this flattened tree 
// is 1 2 3 4 5 6.

// Example 2:

// Input :
//         1
//        / \
//       3   4
//          /
//         2
//          \
//           5 
// Output : 
// 1 3 4 2 5  
// Explanation : 
// After flattening, the tree looks 
// like this 
//      1
//       \
//        3
//         \
//          4
//           \
//            2
//             \ 
//              5 
// Here, left of each node points 
// to NULL and right contains the 
// next node in preorder.The inorder 
// traversal of this flattened tree 
// is 1 3 4 2 5.

// Your task:
// You don't have to read input or print anything. Your task is to complete the function flatten() which takes the root of the tree and flattens the tree into a linked list without using any auxiliary space.
// Note: The driver code prints the in-order traversal of the flattened binary tree.
 
// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(1)
 
// Constraints :
// 1<=n<=10^5

// using  loop
void flatten(Node *root)
{
    while(root)
    {
        if(root->left)
        {
            Node *curr=root->left;
            
            while(curr->right)  curr=curr->right;
            
            curr->right=root->right;
            root->right=root->left;
            root->left=nullptr;
        }  
        
        root=root->right;
    }
}

// using recursion
void flatten(TreeNode* root) 
{
      if(!root) return;
  
      flatten(root->left);
      flatten(root->right);
  
      if(root->left)
      {
        TreeNode* curr=root->left;
        
        while(curr->right) curr=curr->right;
        
        curr->right=root->right;
        root->right=root->left;
        root->left=nullptr;
      }
}
