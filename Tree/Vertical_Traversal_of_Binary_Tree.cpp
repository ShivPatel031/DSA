// Vertical Traversal of Binary Tree GFG

// Given a Binary Tree, find the vertical traversal of it starting from the leftmost level to the rightmost level.
// If there are multiple nodes passing through a vertical line, then they should be printed as they appear in level order traversal of the tree.

void width(Node *root,int &l,int &r,int pos)
{
    if(!root) return;
    
    l=min(l,pos);
    r=max(r,pos);
    
    width(root->left,l,r,pos-1);
    width(root->right,l,r,pos+1);
}

vector<int> verticalOrder(Node *root)
{
   vector<int> ans;
   
   if(!root) return ans;
   
   int l=0,r=0;
   
   width(root,l,r,0);
   
   vector<vector<int>> temp(r-l+1);
   queue<Node*> q;
   queue<int> index;
   q.push(root);
   index.push(abs(l));
   int count=0;
   
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
               index.push(pos-1);
           }
           
           if(t->right)
           {
               q.push(t->right);
               index.push(pos+1);
           }
       }
   }
   
   for(vector<int> i : temp)
   {
       for(int j : i)
       {
           ans.push_back(j);
       }
   }
   
   return ans;
}

// Vertical Order Traversal of a Binary Tree leetcode 987
// with little change

// Given the root of a binary tree, calculate the vertical order traversal of the binary tree.
// For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).
// The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.
// Return the vertical order traversal of the binary tree.

// Example 1:

// Input: root = [3,9,20,null,null,15,7]
// Output: [[9],[3,15],[20],[7]]
// Explanation:
// Column -1: Only node 9 is in this column.
// Column 0: Nodes 3 and 15 are in this column in that order from top to bottom.
// Column 1: Only node 20 is in this column.
// Column 2: Only node 7 is in this column.

// Example 2:

// Input: root = [1,2,3,4,5,6,7]
// Output: [[4],[2],[1,5,6],[3],[7]]
// Explanation:
// Column -2: Only node 4 is in this column.
// Column -1: Only node 2 is in this column.
// Column 0: Nodes 1, 5, and 6 are in this column.
//           1 is at the top, so it comes first.
//           5 and 6 are at the same position (2, 0), so we order them by their value, 5 before 6.
// Column 1: Only node 3 is in this column.
// Column 2: Only node 7 is in this column.

//   Example 3:

// Input: root = [1,2,3,4,6,5,7]
// Output: [[4],[2],[1,5,6],[3],[7]]
// Explanation:
// This case is the exact same as example 2, but with nodes 5 and 6 swapped.
// Note that the solution remains the same since 5 and 6 are in the same location and should be ordered by their values.
 

// Constraints:

// The number of nodes in the tree is in the range [1, 1000].
// 0 <= Node.val <= 1000

void width(TreeNode *root,int &l,int &r,int pos)
{
    if(!root) return;
    
    l=min(l,pos);
    r=max(r,pos);
    
    width(root->left,l,r,pos-1);
    width(root->right,l,r,pos+1);
}
vector<vector<int>> verticalTraversal(TreeNode* root) 
{
    int l=0,r=0;
   
   width(root,l,r,0);
   
   vector<vector<int>> ans(r-l+1);
  
   queue<TreeNode*> q;
   queue<int> index;
  
   q.push(root);
   index.push(abs(l));
   int count=0;
   
   while(!q.empty())
   {
       count=q.size();
       vector<vector<int>> temp(r-l+1);
     
       while(count--)
       {
           TreeNode *t=q.front();
           int pos=index.front();
           q.pop();
           index.pop();
         
           temp[pos].push_back(t->val);
           
           if(t->left)
           {
               q.push(t->left);
               index.push(pos-1);
           }
           
           if(t->right)
           {
               q.push(t->right);
               index.push(pos+1);
           }
       }

       for(int i = 0 ; i<r-l+1;i++)
       {
            if(temp[i].size())
            {
                sort(temp[i].begin(),temp[i].end());
                for(int j=0;j<temp[i].size();j++)
                {
                    ans[i].push_back(temp[i][j]);
                }
            }
       }
   }

   return ans;
}
