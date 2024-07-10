// Count Non-Leaf Nodes in Tree

int countNonLeafNodes(Node* root) 
{
    if(!root) return 0;
    
    if(!root->left && !root->right) return 0;
    
    return 1+countNonLeafNodes(root->left)+countNonLeafNodes(root->right);
}
