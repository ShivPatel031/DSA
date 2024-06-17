//height of tree means total level of any tree
int heightOfbinaryTreeRecursive(Node *root){
        if (!root){
            return 0;
        }
        return 1 + max(heightOfbinaryTreerecursive(root->left),heightOfbinaryTreerecursive(root->right));
    }
