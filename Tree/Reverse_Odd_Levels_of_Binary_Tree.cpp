// Reverse Odd Levels of Binary Tree leetcode 2415

// Given the root of a perfect binary tree, reverse the node values at each odd level of the tree.

// For example, suppose the node values at level 3 are [2,1,3,4,7,11,29,18], then it should become [18,29,11,7,4,3,1,2].
// Return the root of the reversed tree.

// A binary tree is perfect if all parent nodes have two children and all leaves are on the same level.

// The level of a node is the number of edges along the path between it and the root node.

// Example 1:

// Input: root = [2,3,5,8,13,21,34]
// Output: [2,5,3,8,13,21,34]
// Explanation: 
// The tree has only one odd level.
// The nodes at level 1 are 3, 5 respectively, which are reversed and become 5, 3.

// Example 2:

// Input: root = [7,13,11]
// Output: [7,11,13]
// Explanation: 
// The nodes at level 1 are 13, 11, which are reversed and become 11, 13.
  
// Example 3:

// Input: root = [0,1,2,0,0,0,0,1,1,1,1,2,2,2,2]
// Output: [0,2,1,0,0,0,0,2,2,2,2,1,1,1,1]
// Explanation: 
// The odd levels have non-zero values.
// The nodes at level 1 were 1, 2, and are 2, 1 after the reversal.
// The nodes at level 3 were 1, 1, 1, 1, 2, 2, 2, 2, and are 2, 2, 2, 2, 1, 1, 1, 1 after the reversal.

// Constraints:

// The number of nodes in the tree is in the range [1, 214].
// 0 <= Node.val <= 105
// root is a perfect binary tree.

// most optimize way
void helper(TreeNode* rootleft,TreeNode* rootright,int level){
    if(rootleft && rootright){
        if(level%2){
            swap(rootleft->val,rootright->val);
        }
        helper(rootleft->left,rootright->right,level+1);
        helper(rootleft->right,rootright->left,level+1);
    }
}
TreeNode* reverseOddLevels(TreeNode* root) {
    helper(root->left,root->right,1);
    return root;
}

// most optimize other way
void reverse(TreeNode *left, TreeNode *right, bool b) {
    if (!left) return;
    if (b) swap(left->val, right->val);
    b=!b;
    reverse(left->left, right->right, b);
    reverse(left->right, right->left, b);
}
TreeNode *reverseOddLevels(TreeNode *root) {
    return (reverse(root->left, root->right, true), root);
}

// good way
TreeNode* reverseOddLevels(TreeNode* root) 
{
    queue<TreeNode *> q1;
    int count=0;
    bool flag=true;
    q1.push(root);

    while(!q1.empty())
    {   
        count=q1.size();
        vector<TreeNode *> arr;
        while(count--)
        {
            TreeNode *temp=q1.front();
            q1.pop();

            if(temp->left)
            {
                q1.push(temp->left);
                if(flag)
                {
                    arr.push_back(temp->left);
                }
            }

            if(temp->right)
            {
                q1.push(temp->right);
                if(flag)
                {
                    arr.push_back(temp->right);
                }
            }
        }

        if(flag)
        {
            int i = 0,j=arr.size()-1;
            while(i<j)
            {
                int temp=arr[i]->val;
                arr[i]->val=arr[j]->val;
                arr[j]->val=temp;
                i++;
                j--;
            }
        }

        flag=!flag;
    }    
    return root;
}

// first thought
TreeNode* reverseOddLevels(TreeNode* root) 
{
    queue<TreeNode *> q1;
    stack<TreeNode *> s1;
    int count=0;
    bool flag=true;
    q1.push(root);

    while(!q1.empty())
    {   
        count=q1.size();
        vector<int> arr;
        while(count--)
        {
            TreeNode *temp=q1.front();
            q1.pop();

            if(temp->left)
            {
                q1.push(temp->left);
                if(flag)
                {
                    s1.push(temp->left);
                    arr.push_back(temp->left->val);
                }
            }

            if(temp->right)
            {
                q1.push(temp->right);
                if(flag)
                {
                    s1.push(temp->right);
                    arr.push_back(temp->right->val);
                }
            }
        }

        if(flag)
        {
            int i = 0;
            while(!s1.empty())
            {
                s1.top()->val=arr[i];
                s1.pop();
                i++;
            }
        }

        flag=!flag;
    }    
    return root;
}
