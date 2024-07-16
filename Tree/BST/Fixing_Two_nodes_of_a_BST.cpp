// Fixing Two nodes of a BST GFG

// You are given the root of a binary search tree(BST), where exactly two nodes were swapped by mistake. Fix (or correct) the BST by swapping them back. Do not change the structure of the tree.
// Note: It is guaranteed that the given input will form BST, except for 2 nodes that will be wrong. All changes must be reflected in the original linked list.
 
// Examples :
// Input:
//        10
//      /    \
//     5      8
//    / \
//   2   20
// Output: 1
// Explanation:

// Input:
//          11
//        /    \
//       3      17
//        \    /
//         4  10
// Output: 1 
// Explanation: By swapping nodes 11 and 10, the BST can be fixed.

// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ Number of nodes ≤ 103

// can do using storing inorder and finding mismatch and swap them in tree 

// optimize way
void correctBST( struct Node* root )
{
    Node * first=nullptr;
    Node *second=nullptr;
    Node *prev=new Node(INT_MIN);
    
    
    while(root)
    {
        if(root->left)
        {
            Node *temp=root->left;
        
            while(temp->right && temp->right !=root)
            {
                temp=temp->right;
            }
            
            if(temp->right == root)
            {
                temp->right=nullptr;
                if(root->data<prev->data)
                {
                    if(!first)
                    {
                        first=prev;
                    }
                    second=root;
                }
                prev=root;
                root=root->right;
            }
            else
            {
                temp->right=root;
                root=root->left;
            }
        }
        else
        {
            if(root->data<prev->data)
            {
                if(!first)
                {
                    first=prev;
                }
                second=root;
            }
            prev=root;
            root=root->right;
        }
    }
    
    if(first && second)
    {
        int t = first->data;
        first->data=second->data;
        second->data=t;
    }
    
}
