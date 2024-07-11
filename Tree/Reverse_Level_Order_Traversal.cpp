// Reverse Level Order Traversal GFG

vector<int> reverseLevelOrder(Node *root)
{
    vector<vector<int>> tempans;
    queue<Node *> q;
    q.push(root);
    int count=0;
    
    while(!q.empty())
    {
        count=q.size();
        vector<int> arr;
        
        while(count--)
        {
            Node *temp =q.front();
            q.pop();
            
            arr.push_back(temp->data);
            
            if(temp->left) q.push(temp->left);
            
            if(temp->right) q.push(temp->right);
        }
        
        tempans.push_back(arr);
    }
    
    vector<int> ans;
    
    for(int i = tempans.size()-1;i>=0;i--)
    {
        for(int j=0;j<tempans[i].size();j++)
        {
            ans.push_back(tempans[i][j]);
        }
    }
    
    
    return ans;
}
