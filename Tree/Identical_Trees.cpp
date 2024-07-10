// Identical Trees GFG

// optimize way
bool isIdentical(Node *r1, Node *r2)
{
    //Your Code here
    if (!r1 and !r2){
        return 1;
    }
    else if ((r1 and !r2) or (!r1 and r2)){
        return 0;
    }
    if (r1->data != r2->data){
        return 0;
    }
    
    return isIdentical(r1->left,r2->left) and isIdentical(r1->right,r2->right);
}

// what i first do
// void tree(Node *r1,Node *r2,bool &ans)
// {
    
//     if(!ans){
//         return;
//     }
    
//     if((!r1 && r2) || (!r1 && r2))
//     {
//         ans=false;
//         return;
//     }
//     else if(!r1 && !r2) return;
    
//     if(r1->data != r2->data)
    
//     {ans=false;return;}
    
    
        
//     if(r1->left && r2->left)
//     {
//         tree(r1->left,r2->left,ans);
        
//     }
//     else{
//         if((!r1->left && r2->left)||(r1->left && !r2->left)){
//             ans=false;
//             return;
//         }
//     }
    
    
//     if(r1->right && r2->right)
//     {
//         tree(r1->right,r2->right,ans);
//     }
//     else{
//         if((!r1->right && r2->right)||(r1->right && !r2->right)){
//             ans=false;
//             return;
//         }
//     }
    
// }
// bool isIdentical(Node *r1, Node *r2)
// {
//     bool ans=true;
    
//     tree(r1,r2,ans);
    
//     return ans;
// }
