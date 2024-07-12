// Using recursion
void inorder(Node *root,vector<int> &ans)
{
    if(!root) return;
        
    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);
}

vector<int> inOrder(Node* root) 
{
    vector<int> ans;
    inorder(root,ans);
    return ans;
}

// Using iteration
vector<int> inOrder(Node* root)
{
    vector<int> ans;
    
    if(!root) return ans;
    
    stack<Node *> s;
    stack<bool> check;
    
    s.push(root);
    check.push(0);
    
    while(!s.empty())
    {
        Node *temp=s.top();
        bool t=check.top();
        s.pop();
        check.pop();
        
        if(t==0)
        {
            if(temp->right)
            {
                s.push(temp->right);
                check.push(0);
            }
            
            s.push(temp);
            check.push(1);
            
            if(temp->left)
            {
                s.push(temp->left);
                check.push(0);
            }
        }
        else
        {
            ans.push_back(temp->data);
        }
    }
    
    return ans;
}
