// Burning Tree GFG

// Given a binary tree and a node data called target. Find the minimum time required to burn the complete binary tree if the target is set on fire. It is known that in 1 second all nodes connected to a given node get burned. That is its left child, right child, and parent.
// Note: The tree contains unique values.


// Examples : 

// Input:      
//           1
//         /   \
//       2      3
//     /  \      \
//    4    5      6
//        / \      \
//       7   8      9
//                    \
//                    10
// Target Node = 8
// Output: 7
// Explanation: If leaf with the value 
// 8 is set on fire. 
// After 1 sec: 5 is set on fire.
// After 2 sec: 2, 7 are set to fire.
// After 3 sec: 4, 1 are set to fire.
// After 4 sec: 3 is set to fire.
// After 5 sec: 6 is set to fire.
// After 6 sec: 9 is set to fire.
// After 7 sec: 10 is set to fire.
// It takes 7s to burn the complete tree.


// Input:      
//           1
//         /   \
//       2      3
//     /  \      \
//    4    5      7
//   /    / 
//  8    10
// Target Node = 10
// Output: 5

// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(height of tree)


// Constraints:
// 1 ≤ n ≤ 104

int burningTree(Node *root,int &timer,int target,Node *&address)
{
    if(!root) return 0;
    
    if(root->data==target)
    {   
        address=root;
        return -1;
    }
    
    int left = burningTree(root->left,timer,target,address);
    int right = burningTree(root->right,timer,target,address);
    
    if(left<0)
    {
        timer = max(timer,abs(left)+right);
        return left-1;
    }
    
    if(right<0)
    {
        timer = max(timer,left+abs(right));
        return right-1;
    }
    
    return 1+max(left,right);
}

int minTime(Node* root, int target) 
{
    int timer = 0 ;
    Node *address=nullptr;
    
    burningTree(root,timer,target,address);

  // to find height of below taget Node
    int height=burningTree(address,timer,-1,address)-1;
    
    return max(timer,height);
}
