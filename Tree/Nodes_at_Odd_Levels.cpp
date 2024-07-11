// Nodes at Odd Levels GFG

vector<Node *> nodesAtOddLevels(Node *root)
{
    vector<Node *> ans;
    queue<Node *> q;
    int count=0;
    q.push(root);
    bool flag=1;
    
    while(!q.empty())
    {
        count=q.size();
        
        while(count--)
        {
            Node *temp=q.front();
            q.pop();
            
            if(flag) ans.push_back(temp);
            
            if(temp->left) q.push(temp->left);
            
            if(temp->right) q.push(temp->right);
        }
        
        flag=!flag;
    }
    
    return ans;
}
