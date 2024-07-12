// Bottom View of Binary Tree GFG

// using recursion
void width(Node *root,int pos,int &l,int &r)
{
    if(!root) return;
    
    l=min(l,pos);
    r=max(r,pos);
    
    width(root->left,pos-1,l,r);
    width(root->right,pos+1,l,r);
}

void bottomV(Node *root,int pos,vector<int> &ans,vector<int> &check,int level)
{
    if(!root) return;
    
    if(check[pos] <= level)
    {
        check[pos]=level;
        ans[pos]=root->data;
    }
    
    bottomV(root->left,pos-1,ans,check,level+1);
    bottomV(root->right,pos+1,ans,check,level+1);
}

vector <int> bottomView(Node *root) 
{
    int l=0,r=0;
    
    width(root,0,l,r);
    
    vector<int> ans(r-l+1,0);
    vector<int> check(r-l+1,INT_MIN);
    
    bottomV(root,abs(l),ans,check,0);
    
    return ans;
}

// using level order
void width(Node *root,int pos,int &l,int &r)
{
    if(!root) return;
    
    l=min(l,pos);
    r=max(r,pos);
    
    width(root->left,pos-1,l,r);
    width(root->right,pos+1,l,r);
}


vector <int> bottomView(Node *root) 
{
    int l=0,r=0;
    
    width(root,0,l,r);
    
    vector<int> ans(r-l+1,0);
    
    queue<Node*> q;
    queue<int> index;
    
    int count=0;
    q.push(root);
    index.push(abs(l));
    
    while(!q.empty())
    {
        count=q.size();
        
        while(count--)
        {
            Node *temp = q.front();
            int pos=index.front();
            index.pop();
            q.pop();
            
            ans[pos]=temp->data;
            
            if(temp->left)
            {
                q.push(temp->left);
                index.push(pos-1);
            }
            
            if(temp->right)
            {
                q.push(temp->right);
                index.push(pos+1);
            }
        }
    }
    
    return ans;
}
