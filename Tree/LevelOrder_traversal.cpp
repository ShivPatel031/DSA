vector<int> levelOrder(Node *r){

    vector<int> ans;
    queue<Node *> q;
    q.push(root);
    int count=0;
    
    while(!q.empty())
    {
        count=q.size();
            
        while(count--)
        {
            Node *temp =q.front();
            q.pop();
            
            ans.push_back(temp->data);
            
            if(temp->left) q.push(temp->left);
            
            if(temp->right) q.push(temp->right);
        }
    }

 return ans;
}
