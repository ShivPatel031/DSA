// Check if two Nodes are Cousins GFG leetcode 993

// Given the root of a binary tree with unique values and the values of two different nodes of the tree x and y, return true if the nodes corresponding to the values x and y in the tree are cousins, or false otherwise.

// Two nodes of a binary tree are cousins if they have the same depth with different parents.

// Note that in a binary tree, the root node is at the depth 0, and children of each depth k node are at the depth k + 1.
  
// Example 1:

// Input: root = [1,2,3,4], x = 4, y = 3
// Output: false
  
// Example 2:

// Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
// Output: true
  
// Example 3:

// Input: root = [1,2,3,null,4], x = 2, y = 3
// Output: false
 
// Constraints:

// The number of nodes in the tree is in the range [2, 100].
// 1 <= Node.val <= 100
// Each node has a unique value.
// x != y
// x and y are exist in the tree.

// otimize one
void depth(TreeNode* root, int x, int y, int dep, int par_val){
    if(root==NULL) return;  
    if(root->val==x){       
        xdepth=dep;         
        xparent=par_val;    
        return;             
    }
    if(root->val==y){       
        ydepth=dep;        
        yparent=par_val;
        return;
    }
    depth(root->left, x, y, dep+1, root->val);  
    depth(root->right, x, y, dep+1, root->val); 
}

bool isCousins(TreeNode* root, int x, int y) 
{
    int xdepth, ydepth, xparent, yparent;
    if(root->val==x || root->val==y) return false;
    depth(root, x, y, 0, 0);
    
    if(xdepth==ydepth && xparent!=yparent) return true;
    return false;
}

// using two function
bool parent(Node *root,int a,int b)
{
    if(!root) return true;
    
    if(root->left && root->right)
    {
        if(root->left->data==a && root->right->data==b) return false;
    
        if(root->right->data==a && root->left->data==b) return false;
    }
    
    return parent(root->left,a,b) && parent(root->right,a,b);
}

bool isCousins(Node *root, int a, int b)
{
   if(!root) return 0;
   
   queue<Node *> q;
   q.push(root);
   int l1=-1,l2=-1,count=0,level=0;
   
   while(!q.empty())
   {
       count=q.size();
       
       while(count--)
       {
            Node *temp=q.front();
            q.pop();
            
            if(temp->data==a) l1=level;
            
            if(temp->data==b) l2=level;
            
            if(temp->left) q.push(temp->left);
            
            if(temp->right) q.push(temp->right);
       }
       
       if(l1 != l2) return false;
       
       if(l1 != -1 || l2 != -1) break;
       
       level++;
   }
   
  if(l1==-1 || l2==-1)
  {
      return false;
  }
   
  return parent(root,a,b);
}

// using one function
bool isCousins(TreeNode* root, int x, int y) 
{
    queue<TreeNode *> q;
    q.push(root);
    int flag=0;

    while (!q.empty())
    {
        int s=q.size();
        while (s--)
        {
            TreeNode *temp=q.front();
            q.pop();

            if (temp->left and temp->right){
                if((temp->left->val == x and temp->right->val == y) or (temp->left->val == y and temp->right->val == x)){
                    return 0;
                }
            }

            if (temp->val == x or temp->val == y){
                flag++;
            }

            if(temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }

        if (flag==1) return 0;
    }
    return 1;    
}
