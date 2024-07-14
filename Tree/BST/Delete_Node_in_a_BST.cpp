// Delete Node in a BST leetcode 450 GFG

// Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

// Basically, the deletion can be divided into two stages:

// Search for a node to remove.
// If the node is found, delete the node.
 
// Example 1:

// Input: root = [5,3,6,2,4,null,7], key = 3
// Output: [5,4,6,2,null,null,7]
// Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.
// One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
// Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.

// Example 2:

// Input: root = [5,3,6,2,4,null,7], key = 0
// Output: [5,3,6,2,4,null,7]
// Explanation: The tree does not contain a node with value = 0.
// Example 3:

// Input: root = [], key = 0
// Output: []

// Once we find the node to be deleted,

// -> If the root is a leaf node, then return NULL. (Base Case).
// -> Else if the root has only the left child, then we delete the root node and return its left child.
// -> Else if the root has only the right child, then we delete the root node and return its right child.
// -> Else, we find the inorder successor node, set the key of root with the key of the inorder successor, and delete the inorder successor. To find the inorder successor, we need to find the node with the minimum key in the right subtree.

TreeNode* deleteNode(TreeNode* root, int key) 
{
    if(!root) return nullptr;

    if(root->val==key)
    {
        if(root->left && root->right)
        {
            TreeNode *curr=root->right;

            if(!curr->left) 
            {
                curr->left=root->left;
                return curr;
            }

            while(curr->left->left)
            {
                curr=curr->left;
            }

            TreeNode *temp=curr->left;
            if(temp->right)
            {
                curr->left=temp->right;
            }
            else
            {
                curr->left=nullptr;
            }
            temp->left=root->left;
            temp->right=root->right;

            return temp;
        }

        if(root->left) return root->left;

        if(root->right) return root->right;

        return nullptr;
    }
    else
    {
        if(key<root->val)
        {
            root->left=deleteNode(root->left,key);
        }
        else
        {
            root->right=deleteNode(root->right,key);
        }
    }
    return root;
}
