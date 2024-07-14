// create BST using array

class Node{

  public:
  int data;
  Node *left;
  Node *right;

  Node(int val)
  {
    data=val;
    left=nullptr;
    right=nullptr;
  }
};

Node* insertData(Node *root,int target)
{
  if(!root)
  {
    Node *temp = new Node(target);
    return temp;
  }

  if(target<root->data)
  {
    root->left=insertData(root->left,target);
  }
  else
  {
    root->right=insertData(root->right,target);
  }

  return root;
}

int main()
{
  int arr[]={4 ,5,48,32,15,65,7,25,65,49,15,37};
  Node *root=nullptr;

  for(int i=0;i<arr.size();i++)
    {
      root=insert(root,arr[i]);
    }
}
