// Search in a Binary Search Tree leetcode 700

TreeNode* searchBST(TreeNode* root, int val) 
{
    if(!root) return nullptr;

    if(root->val==val) return root;

    if(val<root->val)
    {
        return searchBST(root->left,val);
    }
    else
    {
        return searchBST(root->right,val);
    }
}
