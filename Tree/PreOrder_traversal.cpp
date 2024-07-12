// using recurtion
void preorder(Node *root,vector<int> &ans)
{
    if (!root) return;

    ans.push_back(root->data);
    preorder(root->left,ans);
    preorder(root->right,ans);
}

vector <int> preorder(Node* root)
{
  vector<int> ans;
  preorder(root,ans);
  return ans;
}
//using iteretion
vector<int> preOrder(Node* root)
{
    vector<int> ans;
    if(!root) return  ans;
    stack<Node *> s1;
    s1.push(root);
    
    while(!s1.empty())
    {
        Node*temp=s1.top();
        s1.pop();
        
        ans.push_back(temp->data);
        
        if(temp->right) s1.push(temp->right);
        
        if(temp->left) s1.push(temp->left);
    }
    
    return ans;
}
