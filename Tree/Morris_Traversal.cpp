// Morris Traversal make spacecomplexity O(1)

// in inorder
vector<int> inOrder(Node* root)
{
    vector<int> ans;
    
    if(!root) return ans;
    
    while(root)
    {
        if(!root->left)
        {
            ans.push_back(root->data);
            root=root->right;
        }
        else
        {
            Node *curr=root->left;
            
            while(curr->right && curr->right != root)
            {
                curr=curr->right;
            }
            
            if(!curr->right)
            {
                curr->right=root;
                root=root->left;
            }
            else
            {
                curr->right=nullptr;
                ans.push_back(root->data);
                root=root->right;
            }
        }
    }
    
    return ans;
}

// in preorder

vector<int> preOrder(Node* root)
{
   vector<int> ans;
    
    if(!root) return ans;
    
    while(root)
    {
        if(!root->left)
        {
            ans.push_back(root->data);
            root=root->right;
        }
        else
        {
            Node *curr=root->left;
            
            while(curr->right && curr->right != root)
            {
                curr=curr->right;
            }
            
            if(!curr->right)
            {
                curr->right=root;
                ans.push_back(root->data);
                root=root->left;
            }
            else
            {
                curr->right=nullptr;
                root=root->right;
            }
        }
    }
    
    return ans;
}

// in postorder (left right node)
// here we find node right left using morris and then reverse the ans
vector<int> postOrder(Node* root) 
{
    vector<int> ans;
    
    if(!root) return ans;
    
    while(root)
    {
        if(!root->right)
        {
            ans.push_back(root->data);
            root=root->left;
        }
        else
        {
            Node *curr=root->right;
            
            while(curr->left && curr->left != root)
            {
                curr=curr->left;
            }
            
            if(!curr->left)
            {
                curr->left=root;
                ans.push_back(root->data);
                root=root->right;
            }
            else
            {
                curr->left=nullptr;
                root=root->left;
            }
        }
    }
    
    reverse(ans.begin(),ans.end());
    
    return ans;
    
}
