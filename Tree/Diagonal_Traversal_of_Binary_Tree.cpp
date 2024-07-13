// Diagonal Traversal of Binary Tree GFG

// Given a Binary Tree, print the diagonal traversal of the binary tree.

// Consider lines of slope -1 passing between nodes. Given a Binary Tree, print all diagonal elements in a binary tree belonging to same line.
// If the diagonal element are present in two different subtress then left subtree diagonal element should be taken first and then right subtree. 

// Example 1:

// Input :
//             8
//          /     \
//         3      10
//       /   \      \
//      1     6     14
//          /   \   /
//         4     7 13
// Output : 8 10 14 3 6 7 13 1 4
// Explanation:
// unnamed
// Diagonal Traversal of binary tree : 
//  8 10 14 3 6 7 13 1 4
// Your Task:
// You don't need to read input or print anything. The task is to complete the function diagonal() that takes the root node as input argumets and returns the diagonal traversal of the given tree.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(N).
// Here N is number of nodes.

// Constraints:
// 1 <= Number of nodes<= 105
// 1 <= Data of a node<= 105

void width(Node *root,int &l,int pos)
{
    if(!root) return;
    
    l=max(l,pos);
    
    width(root->left,l,pos+1);
    width(root->right,l,pos);
}

void diagonalData(Node *root,int index,vector<vector<int>> &ans)
{
    if(!root) return;
    
    ans[index].push_back(root->data);
    
    diagonalData(root->left,index+1,ans);
    diagonalData(root->right,index,ans);
}

vector<int> diagonal(Node *root)
{
   vector<int> ans;
   if(!root) return ans;
   
   int l=0;
   
  width(root,l,0);
   
   vector<vector<int>> temp(l+1);
   
  diagonalData(root,0,temp);
   
   for(vector<int> i : temp)
   {
       for (int j : i)
       {
           ans.push_back(j);
       }
   }
   
   return ans;
}



// not for above question but if want ans level vise
void width(Node *root,int &l,int pos)
{
    if(!root) return;
    
    l=min(l,pos);
    
    width(root->left,l,pos-1);
    width(root->right,l,pos+1);
}

vector<int> diagonal(Node *root)
{
   vector<int> ans;
   if(!root) return ans;
   
   int l=0;
   
   width(root,l,0);
   
   vector<vector<int>> temp(abs(l)+1);
   
   queue<Node*> q;
   queue<int> index;
   q.push(root);
   index.push(0);
   
   int count;
   
   while(!q.empty())
   {
       count=q.size();
       
       while(count--)
       {
           Node *t=q.front();
           int pos=index.front();
           q.pop();
           index.pop();
           
           temp[pos].push_back(t->data);
           
           if(t->left)
           {
               q.push(t->left);
               index.push(pos+1);
           }
           
           if(t->right)
           {
               q.push(t->right);
               index.push(pos);
           }
       }
   }
   
   for(vector<int> i : temp)
   {
       
       for (int j : i)
       {
           ans.push_back(j);
       }
   }
   
   return ans;
}
