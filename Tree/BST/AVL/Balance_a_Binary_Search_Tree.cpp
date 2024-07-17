// Balance a Binary Search Tree leetcode 1382 GFG

// Given the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return any of them.

// A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1. 

// Example 1:

// Input: root = [1,null,2,null,3,null,4,null,null]
// Output: [2,1,3,null,null,null,4]
// Explanation: This is not the only correct answer, [3,1,4,null,2] is also correct.

// Example 2:

// Input: root = [2,1,3]
// Output: [2,1,3]

// Constraints:

// The number of nodes in the tree is in the range [1, 104].
// 1 <= Node.val <= 105

// this code will create new balance tree form existed tree
void inorderTraversal(TreeNode *root,vector<int> &ans)
{
    if(!root) return;

    inorderTraversal(root->left,ans);
    ans.push_back(root->val);
    inorderTraversal(root->right,ans);
}

TreeNode* buildTree(vector<int> &ans,int low,int high)
{
    if(low>high) return nullptr;

    int mid = (low + high)/2;

    TreeNode *temp = new TreeNode(ans[mid]);

    temp->left=buildTree(ans,low,mid-1);
    temp->right=buildTree(ans,mid+1,high);

    return temp;
}
TreeNode* balanceBST(TreeNode* root) 
{    
    vector<int> ans;

    inorderTraversal(root,ans);

    return buildTree(ans,0,ans.size()-1);
}

// code is working but giving stack overflow in online compiler but this code will make existed tree balance
int height(TreeNode *root)
{
    if(!root) return 0;

    return 1 + max(height(root->left),height(root->right));
}

TreeNode* leftRotate(TreeNode *unbalancedNode,TreeNode *child)
{
    TreeNode *temp=child->left;
    child->left=unbalancedNode;
    unbalancedNode->right = temp;
    return child;
}

TreeNode* rightRotate(TreeNode *unbalancedNode,TreeNode *child)
{
    TreeNode *temp=child->right;
    child->right=unbalancedNode;
    unbalancedNode->left = temp;
    return child;
}

TreeNode* balanceTree(TreeNode *unbalanceNode,bool lr)
{
    if(lr)
    {
        int left = height(unbalanceNode->right->left);
        int right = height(unbalanceNode->right->right);

        if(left<right)
        {
            return leftRotate(unbalanceNode,unbalanceNode->right);
        }
        else
        {
            unbalanceNode->right = rightRotate(unbalanceNode->right,unbalanceNode->right->left);
            return leftRotate(unbalanceNode,unbalanceNode->right);
        }
    }
    else
    {
        int left = height(unbalanceNode->left->left);
        int right = height(unbalanceNode->left->right);

        if(left>right)
        {
            return rightRotate(unbalanceNode,unbalanceNode->left);
        }
        else
        {
            unbalanceNode->left = leftRotate(unbalanceNode->left,unbalanceNode->left->right);
            return rightRotate(unbalanceNode,unbalanceNode->left);
        }
    }
}

int getUnbalanceNode(TreeNode *root,TreeNode* &unbalanceNode,bool &lr)
{
    if(!root) return 0;

    int left = getUnbalanceNode(root->left,unbalanceNode,lr);
    int right =  getUnbalanceNode(root->right,unbalanceNode,lr);

    if(unbalanceNode)
    {
        if(lr)
        { root->right = balanceTree(unbalanceNode,lr); }
        else {root->left = balanceTree(unbalanceNode,lr);}
        unbalanceNode=nullptr;
        lr=0;
    }

    if(left-right > 1 or left-right < -1)
    { 
        if(!unbalanceNode)
        {  
            if(left-right<-1)
            {
                lr=1;
            }
            unbalanceNode = root;
        }
    }

    return 1 + max(left,right);
}


TreeNode* balanceBST(TreeNode* root) 
{
    TreeNode* unbalanceNode = nullptr;
    TreeNode* parentNode = nullptr;
    bool lr = 0;
    getUnbalanceNode(root,unbalanceNode,lr);

    if(unbalanceNode) return balanceTree(unbalanceNode,lr);


    return root;    
}
