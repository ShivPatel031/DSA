// Construct Binary Tree from Inorder and Postorder Traversal leetcode 106 GFG

TreeNode* createTree(vector<int> &inorder,vector<int> &postorder,int index,int start,int end)
{
    int pos=-1;
    
    for(int i = start;i<=end;i++)
    {
        if(postorder[index]==inorder[i]) pos=i;
    }
    
    if(pos==-1) return nullptr;
    
    TreeNode *temp=new TreeNode(postorder[index]);
    
    temp->right=createTree(inorder,postorder,index-1,pos+1,end);
    temp->left=createTree(inorder,postorder,index-(end-pos)-1,start,pos-1);
    
    return temp;
    
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
{
    return createTree(inorder,postorder,postorder.size()-1,0,postorder.size()-1);
}

