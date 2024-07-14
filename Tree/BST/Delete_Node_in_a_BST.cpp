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


// what i thought
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


// optimize way
TreeNode* deleteNode(TreeNode* root, int key) {
    if(root) 
        if(key < root->val) root->left = deleteNode(root->left, key);     //We frecursively call the function until we find the target node
        else if(key > root->val) root->right = deleteNode(root->right, key);       
        else{
            if(!root->left && !root->right) return NULL;          //No child condition
            if (!root->left || !root->right)
                return root->left ? root->left : root->right;    //One child contion -> replace the node with it's child
                                                 //Two child condition   
            TreeNode* temp = root->left;                        //(or) TreeNode *temp = root->right;
            while(temp->right != NULL) temp = temp->right;     //      while(temp->left != NULL) temp = temp->left;
            root->val = temp->val;                            //       root->val = temp->val;
            root->left = deleteNode(root->left, temp->val);  //        root->right = deleteNode(root->right, temp);		
        }
    return root;
}

// using loop
bool isleaf(TreeNode*root){
    if(root==NULL) return false;
    if(root->left==NULL && root->right==NULL){
        return true;
    }
    return false;
}
TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == NULL) return NULL;
    TreeNode* parent = NULL;                 // Find the node to be deleted and its parent
    TreeNode* current = root;
    while (current != NULL && current->val != key) {
        parent = current;
        if (key < current->val) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    if (current == NULL) return root;       // If the key is not found in the tree

    if (isleaf(current)) {        // If the node to be deleted is a leaf node
        if (current == root) {    // If the node to be deleted is the root itself
            return NULL;
        } else {                  // Disconnect the leaf node from its parent
            if (parent->left == current) {
                parent->left = NULL;
            } else {
                parent->right = NULL;
            }
        }
    } else if (current->left == NULL || current->right == NULL) {     // If the node to be deleted has one child
        TreeNode* child = (current->left != NULL) ? current->left : current->right;
        if (current == root) {       // If the node to be deleted is the root
            return child;
        } else {
            if (parent->left == current) {
                parent->left = child;
            } else {
                parent->right = child;
            }
        }
    } else {                                   // If the node to be deleted has two children
        TreeNode* successorParent = current;
        TreeNode* successor = current->right;  // Finding the in-order successor
        while (successor->left != NULL) {
            successorParent = successor;
            successor = successor->left;
        }
        current->val = successor->val;         // Replace current node's value with successor's value

        if (successorParent->left == successor) {   // Delete the in-order successor
            successorParent->left = successor->right;
        } else {
            successorParent->right = successor->right;
        }
    }
    return root;
}
