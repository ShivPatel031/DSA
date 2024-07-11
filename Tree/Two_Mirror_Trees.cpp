// Two Mirror Trees GFG

// Given a Two Binary Trees, write a function that returns true if one is mirror of other, else returns false.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(Height of the Tree).

bool areMirror(Node* a, Node* b) 
{     
      if(!a && !b)  return 1;
  
      if((!a && b) || (a && !b))  return 0;
  
      if(a->data != b->data)  return 0;
      
      return areMirror(a->left,b->right) && areMirror(a->right,b->left);
}
