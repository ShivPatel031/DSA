// Count Leaves in Binary Tree 

// using recursion
int countLeaves(Node* root)
{
  if(!root)
  {
      return 0;
  }
  
  if(!root->left && !root->right)
  {
      return 1;
  }
  
  return countLeaves(root->left) + countLeaves(root->right);
}

// using level order treveser
int countLeaves(Node* root)
{
    int count=0,ans=0;
    
    if(!root) return count;
    
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty())
    {
        count=q.size();
        
        while(count--)
        {
            Node* temp = q.front();
            q.pop();
            
            if(!temp->left && !temp->right) ans++;
            
            if(temp->left) q.push(temp->left);
            
            if(temp->right) q.push(temp->right);
        }
    }
    
    return ans;
}
