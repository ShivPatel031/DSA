// Maximum Sum BST in Binary Tree leetcode 1373

// Given a binary tree root, return the maximum sum of all keys of any sub-tree which is also a Binary Search Tree (BST).

// Assume a BST is defined as follows:

// The left subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.
 
// Example 1:

// Input: root = [1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]
// Output: 20
// Explanation: Maximum sum in a valid Binary search tree is obtained in root node with key equal to 3.

// Example 2:

// Input: root = [4,3,null,1,2]
// Output: 2
// Explanation: Maximum sum in a valid Binary search tree is obtained in a single root node with key equal to 2.

// Example 3:

// Input: root = [-4,-2,-5]
// Output: 0
// Explanation: All values are negatives. Return an empty BST. 

// Constraints:

// The number of nodes in the tree is in the range [1, 4 * 104].
// -4 * 104 <= Node.val <= 4 * 104

class check{
    public:
    bool BST;
    int SUM;
    int MIN;
    int MAX;

    check(int val)
    {
        BST=1;
        SUM=val;
        MIN=val;
        MAX=val;
    }
};
class Solution {
public:
    check* helper(TreeNode* root,int &maxSum)
    {
        if(!root->left && !root->right)
        { 
            if(maxSum<root->val) maxSum=root->val;
            return new check(root->val); 
        }

        check *l=nullptr;
        check *r=nullptr;

        if(root->left) l=helper(root->left,maxSum);
        if(root->right) r=helper(root->right,maxSum);

        if(l && r)
        {
            if(l->BST && r->BST && root->val > l->MAX && root->val < r->MIN)
            {
                l->SUM+=r->SUM+root->val;
                l->MAX=r->MAX;

                if(l->SUM > maxSum) maxSum=l->SUM;

                return l;
            }
            else
            {
                l->BST=0;
                return l;
            }
        }
        else if(l)
        {
            if(l->BST && root->val > l->MAX)
            {
                l->SUM+=root->val;
                l->MAX=root->val;
                if(l->SUM > maxSum) maxSum=l->SUM;
                return l;
            }
            else
            {
                l->BST=0;
                return l;
            }
        }
        else
        {
            if(r->BST && root->val < r->MIN)
            {
                r->SUM+=root->val;
                r->MIN=root->val;
                if(r->SUM > maxSum) maxSum=r->SUM;
                return r;
            }
            else
            {
                r->BST=0;
                return r;
            }
        }
    }
    int maxSumBST(TreeNode* root) 
    {
        int maxSum=0;

        helper(root,maxSum);

        return maxSum;    
    }
};
