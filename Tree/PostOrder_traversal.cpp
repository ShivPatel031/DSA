// using recursion
void postorder(Node *root,vector<int> &ans)
{
    if(!root)  return;
        
    postorder(root->left,ans);
    postorder(root->right,ans);
    ans.push_back(root->data);
}
vector <int> postOrder(Node* root)
{
    vector<int> ans;
    postorder(root,ans);
    return ans;
}
// using iteration
vector<int> postOrder(Node* root) 
{
    vector<int> ans;
    if(!root) return ans;
    
    stack<Node *> s;
    s.push(root);
    
    while(!s.empty())
    {
        Node *temp =s.top();
        s.pop();
        
        ans.push_back(temp->data);
        
        if(temp->left) s.push(temp->left);
        
        if(temp->right) s.push(temp->right);
    }
    
    reverse(ans.begin(),ans.end());
    
    return  ans;
    
}
