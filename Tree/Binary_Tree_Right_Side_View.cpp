// Binary Tree Right Side View leetcode 199

// using recursion
void helper(TreeNode *root,int level,vector<int> &ans)
{
    if(!root) return;

    if(level==ans.size()) ans.push_back(root->val);

    helper(root->right,level+1,ans);
    helper(root->left,level+1,ans);
}

vector<int> rightSideView(TreeNode* root) 
{
    vector<int> ans;

    helper(root,0,ans);

    return ans;
}

// using count
vector<int> rightSideView(TreeNode* root) 
{
   vector<int> ans;

   if(!root) return ans;
   
   queue<TreeNode *> q;
   int count=0;
   q.push(root);
   
   while(!q.empty())
   {
       count=q.size();
       
       while(count--)
       {
           TreeNode *temp=q.front();
           q.pop();
           
           if(temp->left) q.push(temp->left);
           
           if(temp->right) q.push(temp->right);
           
           if(!count) ans.push_back(temp->val);
       }
   }
   
   return ans;  
}

// by start traversing from right side first
vector<int> rightSideView(TreeNode* root) 
{
   vector<int> ans;

   if(!root) return ans;

   queue<TreeNode *> q;
   int count=0;
   q.push(root);
   
   while(!q.empty())
   {
       count=q.size();
       ans.push_back(q.front()->val);
       
       while(count--)
       {
           TreeNode *temp=q.front();
           q.pop();
           
           if(temp->right) q.push(temp->right);

           if(temp->left) q.push(temp->left);
       }
   }
   
   return ans;
    
}
