//return size of tree (total number of nodes) 
int  size(Node *root){
        if (!root){
            return 0;
        }
        return 1 + size(root->left) + size(root->right);
  }
