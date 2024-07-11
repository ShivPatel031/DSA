// Binary Tree Zigzag Level Order Traversal leetcode 103 GFG

// Given a binary tree with n nodes. Find the zig-zag level order traversal of the binary tree.
// In zig zag traversal starting from the first level go from left to right for odd-numbered levels and right to left for even-numbered levels.

// Example 1:

// Input:
//         1
//       /   \
//      2    3
//     / \    /   \
//    4   5 6   7
// Output:
// 1 3 2 4 5 6 7
// Explanation:
// For level 1 going left to right, we get traversal as {1}.
// For level 2 going right to left, we get traversal as {3,2}.
// For level 3 going left to right, we get traversal as {4,5,6,7}.
// Merging all this traversals in single array we get {1,3,2,4,5,6,7}

// Example 2:

// Input:
//            7
//         /     \
//        9      7
//      /  \      /   
//     8   8   6     
//    /  \
//   10  9 
// Output:
// 7 7 9 8 8 6 9 10 
// Explanation:
// For level 1 going left to right, we get traversal as {7}.
// For level 2 going right to left, we get traversal as {7,9}.
// For level 3 going left to right, we get traversal as {8,8,6}.
// For level 4 going right to left, we get traversal as {9,10}.
// Merging all this traversals in single array we get {7,7,9,8,8,6,9,10}.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function zigZagTraversal() which takes the root node of the Binary Tree as its input and returns a list containing the node values as they appear in the zig-zag level-order traversal of the tree.

// Expected Time Complexity: O(n).
// Expected Auxiliary Space: O(n).

// Constraints:
// 1 <= n <= 105

// leetcode 
vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
{
    vector<vector<int> > ans;

    if(!root) return ans;

    stack<TreeNode *> s1,s2;

    s2.push(root);

    while(!s1.empty() || !s2.empty())
    {
        vector<int> ans1;
        while(!s1.empty())
        {
            TreeNode *temp=s1.top();
            s1.pop();
            
            ans1.push_back(temp->val);
            
            if(temp->right) s2.push(temp->right);
            
            if(temp->left) s2.push(temp->left);
        }
        
        vector<int> ans2;
        while(!s2.empty())
        {
            TreeNode *temp=s2.top();
            s2.pop();
            
            ans2.push_back(temp->val);
            
            if(temp->left) s1.push(temp->left);
            
            if(temp->right) s1.push(temp->right);
        }

        if(ans1.size()>0) ans.push_back(ans1);

        if(ans2.size()>0) ans.push_back(ans2);
        
    }

    return ans; 
}

// GFG
vector <int> zigZagTraversal(Node* root)
{
  vector<int> ans;

    if(!root) return ans;
    
    stack<Node *> s1,s2;
    
    s2.push(root);
    
    while(!s1.empty() || !s2.empty())
    {
       
       while(!s1.empty())
       {
            Node *temp=s1.top();
            s1.pop();
            
            ans.push_back(temp->data);
            
            if(temp->right) s2.push(temp->right);
            
            if(temp->left) s2.push(temp->left);
       }
       
       while(!s2.empty())
       {
            Node *temp=s2.top();
            s2.pop();
            
            ans.push_back(temp->data);
            
            if(temp->left) s1.push(temp->left);
            
            if(temp->right) s1.push(temp->right);
       }
     
    }
    
    return ans;
}


// Level order traversal in spiral form GFG
vector<int> findSpiral(Node *root)
{
    vector<int> ans;
    
    if(!root) return ans;
    
    stack<Node *> s1,s2;
    
    s1.push(root);
    
    while(!s1.empty() || !s2.empty())
    {
       
       while(!s1.empty())
       {
            Node *temp=s1.top();
            s1.pop();
            
            ans.push_back(temp->data);
            
            if(temp->right) s2.push(temp->right);
            
            if(temp->left) s2.push(temp->left);
       }
       
       while(!s2.empty())
       {
            Node *temp=s2.top();
            s2.pop();
            
            ans.push_back(temp->data);
            
            if(temp->left) s1.push(temp->left);
            
            if(temp->right) s1.push(temp->right);
       }
     
    }
    
    
    return ans;
}
