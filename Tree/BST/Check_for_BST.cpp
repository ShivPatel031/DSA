// Check for BST GFG

// this  optimize way but can solve by geting  inorder or tree in array and check if it is in sorted form or not

bool check(Node *root,int &prev)  //understand why sent prev as refrensh ans how the flow work
{
    if(!root) return true;
    
    bool left = check(root->left,prev);
    
    if(!left) return false;
    
    if(prev>=root->data) return false;
    
    prev=root->data;
    
    return check(root->right,prev);
}

bool isBST(Node* root) 
{   
    int prev = INT_MIN;
  
    return check(root,prev);
}
