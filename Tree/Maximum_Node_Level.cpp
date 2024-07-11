// Maximum Node Level GFG

// Given a Binary tree. Find the level in binary tree which has the maximum number of nodes.

// Example 1:

// Input:
//       2
//     /    \ 
//    1      3
//  /   \     \
// 4    6      8
//      / 
//     5
// Output: 2
// Explanation: The level 2 with nodes 4,
// 6 and 8 is the level with maximum
// number of nodes. 

int maxNodeLevel(Node *root)
{
   queue<Node *> q;
   int count=0;
   int ans=0,level=0,ansLevel;
   q.push(root);
   
   while(!q.empty())
   {
      count=q.size();
      
      if(count>ans)
      {
          ans=count;
          ansLevel=level;
      }
       
      while(count--)
      {
          Node* temp=q.front();
          q.pop();
          
          if(temp->left) q.push(temp->left);
          
          if(temp->right) q.push(temp->right);
      }
      
      level++;
 }
 
 return ansLevel;
}
