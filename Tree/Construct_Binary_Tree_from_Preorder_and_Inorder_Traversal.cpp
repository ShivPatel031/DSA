// Construct Binary Tree from Preorder and Inorder Traversal leetcode 105 GFG

TreeNode* createTree(vector<int> &inorder,vector<int> &preorder,int index,int start,int end)
{
    int pos=-1;
    
    for(int i = start;i<end;i++)
    {
        if(preorder[index]==inorder[i]) pos=i;
    }
    
    if(pos==-1) return nullptr;
     
    TreeNode *temp=new TreeNode(preorder[index]);
    
    temp->left=createTree(inorder,preorder,index+1,start,pos);
    temp->right=createTree(inorder,preorder,index + (pos-start)+1,pos+1,end);
    
    return temp;
    
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
{
    return createTree(inorder,preorder,0,0,inorder.size());
}

// what i first thought
// TreeNode* createTree(vector<int> arr,vector<int> &inorder,int index)
// {
//     if(!arr.size())
//     {
//         return nullptr;
//     }
    
//     int pos=-1;
    
//     for(int i = 0;i<arr.size();i++)
//     {
//         if(inorder[index]==arr[i])
//         {
//             pos=i;
//         }
//     }
    
//     if(pos==-1)
//     {
//         return nullptr;
//     }
    
//     vector<int> arr1;
//     vector<int> arr2;
    
//     for(int i = 0 ; i<arr.size();i++)
//     {
        
//         if(i<pos)
//         {
//             arr1.push_back(arr[i]);
//         }       
//         else if(i>pos)
//         {
//             arr2.push_back(arr[i]);
//         }
//     }
    
//     TreeNode *temp=new TreeNode(inorder[index]);
    
//     temp->left=createTree(arr1,inorder,index+1);
//     temp->right=createTree(arr2,inorder,index + pos+1);
    
//     return temp;
    
// }
// TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//     return createTree(inorder,preorder,0);
// }
