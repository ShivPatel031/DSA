// Range Sum of BST leetcode 938

// Given the root node of a binary search tree and two integers low and high, return the sum of values of all nodes with a value in the inclusive range [low, high].

// Example 1:

// Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
// Output: 32
// Explanation: Nodes 7, 10, and 15 are in the range [7, 15]. 7 + 10 + 15 = 32.

// Example 2:

// Input: root = [10,5,15,3,7,13,18,1,null,6], low = 6, high = 10
// Output: 23
// Explanation: Nodes 6, 7, and 10 are in the range [6, 10]. 6 + 7 + 10 = 23.
 
// Constraints:

// The number of nodes in the tree is in the range [1, 2 * 104].
// 1 <= Node.val <= 105
// 1 <= low <= high <= 105
// All Node.val are unique.

// what i thought
void helper(TreeNode *root,int &low,int &high,int &sum)
{
    if(!root) return;

    if(root->val>=low && root->val <=high)  sum+=root->val;
    helper(root->left,low,high,sum);
    helper(root->right,low,high,sum);
}
int rangeSumBST(TreeNode* root, int low, int high) 
{
    int sum=0;

    helper(root,low,high,sum);

    return sum;    
}


// using one function and recursion
int rangeSumBST(TreeNode* root, int low, int high) 
{
    if(root==NULL) return 0;

  // check the current node
    if(root->val >=low && root->val <= high){
        return root->val + rangeSumBST(root->left,low,high)
                       + rangeSumBST(root->right,low,high)  ;
    } 
     // if current value is less than the low range then dont go left only go right..
    if(root->val < low) return rangeSumBST(root->right,low,high);

    // the cuurent value is more than the high value then dont go right only go left 
    return rangeSumBST(root->left,low,high) ;  
}

// usnig stack and loop
int rangeSumBST(TreeNode* root, int low, int high) 
{
    stack<TreeNode*> stk;
    stk.push(root);
    int s = 0;
    while (!stk.empty()) {
        TreeNode* node = stk.top();
        stk.pop();
        if (node->val >= low && node->val <= high) s += node->val;
        
        if (node->val > low && node->left != NULL) {
            stk.push(node->left);
        }
        if (node->val < high && node->right != NULL) {
            stk.push(node->right);
        }
    }

    return s;  
}
