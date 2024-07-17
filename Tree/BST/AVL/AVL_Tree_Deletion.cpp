// AVL Tree Deletion GFG

// Given an AVL tree and N values to be deleted from the tree. Write a function to delete a given value from the tree. All the N values which needs to be deleted are passed one by one as input data by driver code itself, you are asked to return the root of modified tree after deleting the value.
// Example 1:

// Tree = 
//         4
//       /   \
//      2     6
//     / \   / \  
//    1   3 5   7

// N = 4
// Values to be deleted = {4,1,3,6}

// Input: Value to be deleted = 4
// Output:
//         5    
//       /   \
//      2     6
//     / \     \  
//    1   3     7

// Input: Value to be deleted = 1
// Output:
//         5    
//       /   \
//      2     6
//       \     \  
//        3     7

// Input: Value to be deleted = 3
// Output:
//         5    
//       /   \
//      2     6
//             \  
//              7

// Input: Value to be deleted = 6
// Output:
//         5    
//       /   \
//      2     7

// Your Task:  
// You dont need to read input or print anything. Complete the function delelteNode() which takes the root of the tree and the value of the node to be deleted as input parameters and returns the root of the modified tree.

// Note: The tree will be checked after each deletion. 
// If it violates the properties of balanced BST, an error message will be printed followed by the inorder traversal of the tree at that moment.
// If instead all deletion are successful, inorder traversal of tree will be printed.
// If every single node is deleted from tree, 'null' will be printed.

// Expected Time Complexity: O(height of tree)
// Expected Auxiliary Space: O(height of tree)

// Constraints:
// 1 ≤ N ≤ 500


struct Node
{
	int data, height;
	Node *left, *right;
	Node(int x)
	{
		data = x;
		height = 1;
		left = right = NULL;
	}
};

int getHeight(Node* root)
{
    if(!root) return 0;
    
    return root->height;
}

int getDifference(Node* root)
{
    if(!root) return 0;
    
    return getHeight(root->left)-getHeight(root->right);
}

Node* rightRotation(Node* root)
{
    Node *child = root->left;
    Node *childRight =  child->right;
    child->right=root;
    root->left=childRight;
    
    root->height=1+max(getHeight(root->left),getHeight(root->right));
    child->height=1+max(getHeight(child->left),getHeight(child->right));
    
    return child;
}

Node* leftRotation(Node* root)
{
    Node *child=root->right;
    Node *childLeft=child->left;
    child->left=root;
    root->right=childLeft;
    
    root->height=1+max(getHeight(root->left),getHeight(root->right));
    child->height=1+max(getHeight(child->left),getHeight(child->right));
    
    return child;
}

Node* deleteNode(Node* root, int data)
{
    if(!root) return nullptr;
    
    if(data < root->data)
    {
        root->left=deleteNode(root->left,data);
    }
    else if(data > root->data)
    {
        root->right = deleteNode(root->right,data);
    }
    else
    {
        
        if(!root->left && !root->right)
        {
            return nullptr;
        }
        else if(root->left && !root->right)
        {
            return root->left;
        }
        else if(root->right && !root->left)
        {
            return root->right;
        }
        else
        {
            Node *temp=root->right;
            
            while(temp->left)
            {
                temp=temp->left;
            }
            
            root->data=temp->data;
            
            root->right = deleteNode(root->right,temp->data);
        }
    }
    
    root->height = 1 + max(getHeight(root->left),getHeight(root->right));
    
    int difference = getDifference(root);
    
    if(difference>1)
    {
        int leftNodeDifference = getDifference(root->left);
        
        if(leftNodeDifference>=0)
        {
            return rightRotation(root); 
        }
        else
        {
            root->left=leftRotation(root->left);
            return rightRotation(root);
        }
    }
    else if(difference<-1)
    {
        int rightNodeDifference =  getDifference(root->right);
        
        if(rightNodeDifference<=0)
        {
            return leftRotation(root);
        }
        else 
        {
            root->right = rightRotation(root->right);
            return leftRotation(root);
        }
    }
    else
    {
        return root;
    }
    
}
