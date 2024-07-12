// Left View of Binary Tree

// Given a Binary Tree, return Left view of it. Left view of a Binary Tree is set of nodes visible when tree is visited from Left side. The task is to complete the function leftView(), which accepts root of the tree as argument. If no left view is possible, return an empty tree.

// Left view of following tree is 1 2 4 8.

//           1
//        /     \
//      2        3
//    /     \    /    \
//   4     5   6    7
//    \
//      8   

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(N).

// Constraints:
// 0 <= Number of nodes <= 100
// 0 <= Data of a node <= 1000


// optimize logically without flag
vector<int> leftView(Node *root)
{
   vector<int> ans;
   if(!root) return ans;
   queue<Node *> q;
   int count=0;
   
   q.push(root);
   
   while(!q.empty())
   {
        count=q.size();
        ans.push_back(q.front()->data);
        
        while(count--)
        {
            Node * temp=q.front();
            q.pop();
            
            if(temp->left) q.push(temp->left);
            
            if(temp->right) q.push(temp->right);
        }
   }
   
   return ans;
}

// using recursion
void leftViewAns(Node *root,int level,vector<int> &ans)
{
    if(!root) return;
    
    if(level==ans.size()) ans.push_back(root->data);
    
    leftViewAns(root->left,level+1,ans);
    leftViewAns(root->right,level+1,ans);
}
vector<int> leftView(Node *root)
{
   vector<int> ans;
   
   leftViewAns(root,0,ans);
   
   return ans;
}

// optimize with flag
vector<int> leftView(Node *root)
{
   vector<int> ans;
   if(!root) return ans;
   queue<Node *> q;
   bool flag=1;
   int count=0;
   
   q.push(root);
   
   while(!q.empty())
   {
        count=q.size();
        
        while(count--)
        {
            Node * temp=q.front();
            q.pop();
            
            if(flag)
            {
                ans.push_back(temp->data);
                flag=!flag;
            }
            
            if(temp->left) q.push(temp->left);
            
            if(temp->right) q.push(temp->right);
        }
        flag=!flag;
   }
   
   return ans;
}

//  first try bad space complexcity
// vector<int> leftView(Node *root)
// {
//     if(!root){
//         vector<int> a;
//         return  a;
//     }
//    vector<vector<int>> semiresult;
//    queue<Node *> q;
//    q.push(root);
//    while (!q.empty()){
//        int s=q.size();
//        vector<int> temp;
//        while (s--){
           
//            Node *temp1=q.front();
//            q.pop();
//            temp.push_back(temp1->data);
//            if (temp1->left) q.push(temp1->left);
//            if (temp1->right) q.push(temp1->right);
           
//        }
//        semiresult.push_back(temp);
//    }
//    vector<int> result;
//    for (vector<int> it : semiresult){
//        result.push_back(it[0]);
//    }
//    return result;
// }
