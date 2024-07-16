// Largest BST GFG

// Given a binary tree. Find the size of its largest subtree which is a Binary Search Tree.
// Note: Here Size equals the number of nodes in the subtree.

// Examples :

// Input:   1
//         /  \
//         4   4              
//        / \ 
//       6   8
// Output: 1 
// Explanation: There's no sub-tree with size greater than 1 which forms a BST. All the leaf Nodes are the BSTs with size equal to 1.

// Input:    6
//         /   \
//       6      2              
//        \     / \
//         2  1  3
// Output: 3
// Explanation: The following sub-tree is a BST of size 3:  2
//                                                       /   \
//                                                      1     3
// Expected Time Complexity: O(n).
// Expected Auxiliary Space: O(Height of the BST).

// Constraints:
// 1 ≤ Number of nodes ≤ 105
// 1 ≤ Data of a node ≤ 106



class check{
    public:
    bool BST;
    int size;
    int MIN;
    int MAX;
    
    check(int val)
    {
        BST=1;
        size=1;
        MIN=val;
        MAX=val;
    }
};

class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    check* BST(Node *root,int &maxsize)
    {
        if(!root->left && !root->right)
        {
            return new check(root->data);
        }
        
        check *l=NULL,*r=NULL;
        
        if(root->left) l=BST(root->left,maxsize);
        
        if(root->right) r=BST(root->right,maxsize);
        
        if(l && r)
        {
            if(l->BST && r->BST && root->data > l->MAX && root->data < r->MIN)
            {
                l->size=l->size+r->size+1;
                l->MAX=r->MAX;
                
                if(maxsize<l->size) maxsize=l->size;
                
                return l;
            }
            else
            {
                l->BST=0;
                return l;
            }
        }
        else if(l)
        {
            if (l->BST && l->MAX<root->data)
            {
                l->size++;
                l->MAX=root->data;
                
                if(maxsize<l->size) maxsize=l->size;
                
                return l;
                
            }
            else
            {
                l->BST=0;
                return l;
            }
        }
        else{
            if(r->BST && r->MIN>root->data){
                r->size++;
                r->MIN=root->data;
                
                if(maxsize<r->size) maxsize=r->size;
                
                return r;
            }
            else 
            {
                r->BST=0;
                return r;
            }
        }
    }
        
    int largestBst(Node *root)
    {
        int maxsize=1;
        
        BST(root,maxsize);
        
        return maxsize;
    }
};
