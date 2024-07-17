// Insert into a Binary Search Tree leetcode 701 GFG

TreeNode* insertIntoBST(TreeNode* root, int val) 
{
    if(!root) return new TreeNode(val);

    if(val<root->val)
    {
        root->left = insertIntoBST(root->left,val);
    }
    else if(val>root->val)
    {
        root->right = insertIntoBST(root->right,val);
    }  

    return root;
}
