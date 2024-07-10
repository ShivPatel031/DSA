// Sum of Binary Tree

long int sumBT(Node* root)
{
    if(!root) return 0;
    
    return root->key + sumBT(root->left) + sumBT(root->right);
}
