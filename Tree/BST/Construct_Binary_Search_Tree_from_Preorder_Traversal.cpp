// Construct Binary Search Tree from Preorder Traversal leetcode 1008 GFG

// Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), construct the tree and return its root.
// It is guaranteed that there is always possible to find a binary search tree with the given requirements for the given test cases.
// A binary search tree is a binary tree where for every node, any descendant of Node.left has a value strictly less than Node.val, and any descendant of Node.right has a value strictly greater than Node.val.
// A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, then traverses Node.right.

// Example 1:

// Input: preorder = [8,5,1,7,10,12]
// Output: [8,5,10,1,7,null,12]

// Example 2:

// Input: preorder = [1,3]
// Output: [1,null,3] 

// Constraints:

// 1 <= preorder.length <= 100
// 1 <= preorder[i] <= 1000
// All the values of preorder are unique.

// most optimize way

TreeNode* build(vector<int> &A, int &i, int bound)
{
    if(i==A.size()||A[i]>bound) return NULL;
    TreeNode* root=new TreeNode(A[i++]);
    root->left=build(A,i,root->val);
    root->right=build(A,i,bound);
    return root;
}

TreeNode* bstFromPreorder(vector<int>& A) 
{
 int i=0;
 return build(A,i,INT_MAX);
}

// optimize O(N) 
 TreeNode* createBST(vector<int>& preorder,int &index,int left,int right)
{
    if(index>=preorder.size()) return nullptr;

    TreeNode* temp = new TreeNode(preorder[index]);

    if(index+1 < preorder.size())
    {
        index=index+1;

        if(left<preorder[index] && preorder[index]<temp->val)
        {
            temp->left = createBST(preorder,index,left,temp->val);
        }

        if(preorder[index]>temp->val && preorder[index]<right)
        {
            temp->right=createBST(preorder,index,temp->val,right);
        }
    }
        
    return temp;
}

TreeNode* bstFromPreorder(vector<int>& preorder) 
{
    int index = 0;
    return createBST(preorder,index,INT_MIN,INT_MAX);
}


// what is first thought but O(n^2) methods
TreeNode* createBST(vector<int>& preorder,int index,int start,int end)
{
    if(index>=preorder.size() && index>=start && index<=end) return nullptr;

    TreeNode* temp = new TreeNode(preorder[index]);

    int pos=-1;

    for(int i = start;i<=end;i++)
    {
        if(preorder[index]<preorder[i])
        {
            pos=i;
            break;
        }
    }

    if(index+1!=preorder.size() && preorder[index+1]<preorder[index])
    {
        if(pos != -1)
        {
            temp->left=createBST(preorder,index+1,index+1,pos-1);
        }
        else
        {
            temp->left=createBST(preorder,index+1,index+1,end);
        }
    }    
    else{
        temp->left=nullptr;
    }
    if(pos>-1)
    {
        temp->right=createBST(preorder,pos,pos,end);
    }
    else
    {
        temp->right=nullptr;
    }
        
    return temp;
}


TreeNode* bstFromPreorder(vector<int>& preorder) 
{
    return createBST(preorder,0,0,preorder.size()-1);
}
