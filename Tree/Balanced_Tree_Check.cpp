// Balanced Tree Check GFG leetcode 110

// Given a binary tree, find if it is height balanced or not.  A tree is height balanced if difference between heights of left and right subtrees is not more than one for all nodes of tree. 

int checkBalance(Node *root,bool &check)
{
    if(!root) return 0 ;
    
    if(check){
    
        int l = checkBalance(root->left,check);
        int r = checkBalance(root->right,check);
        
        if(abs(l-r)>1) check=false;
        
        return 1 + max(l,r);
    
    }
    
    return -1;
}

bool isBalanced(Node *root)
{
    bool check = true;
    
    checkBalance(root,check);
    
    return check;
}


// other way

bool isBalanced(TreeNode* root) 
{
    if(root==NULL)
        return true;
    if(abs(maxDepth(root->left)-maxDepth(root->right))>1)
        return false;
    if(isBalanced(root->left) && isBalanced(root->right))
        return true;
    return false;
}

int maxDepth(TreeNode* root) 
{
    if(root==NULL)
        return 0;
    return max(maxDepth(root->left),maxDepth(root->right))+1;
}
