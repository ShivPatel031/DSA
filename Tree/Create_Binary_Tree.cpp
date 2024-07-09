#include<iostream>
#include<queue>
using namespace std;

class Node
{
    public:
    int data;
    Node *left;
    Node *right;
    
    Node(int x)
    {
      data=x;
      left=nullptr;
      right=nullptr;
    }
}

// using recursion and by preorder;

Node* binaryTree()
{
    int x;
    cout<<"Enter Node :";
    cin>>x;

    if(x==-1) return nullptr;

    Node *temp = new Node(x);

    cout<<"Enter Left child of "<<x<<" :";
    temp->left=binaryTree();

    cout<<"Enter right child of "<<x<<" :";
    temp->right=binaryTree();

    return temp;
}

int main()
{
  int x;
  cout<<"Enter the root element :";
  cin>>x;

  int first,second;
  queue<Node *> q;
  Node *root=new Node(x);
  q.push(root);

    // this will create level order binary tree
  while(!q.empty())
  {
    Node *temp=q.front();
    q.pop();

    cout<<"Enter left value of "<<temp->data<<" Node : ";
    cin>>first;

    if(first!=-1)
    {
      temp->left=new Node(first);
      q.push(temp->left);
    }
    
    cout<<"Enter right value of "<<temp->data<<" Node : ";
    cin<<second;

    if(second!=-1)
    {
      temp->right=new Node(second);
      q.push(temp->right);
    }
    
  }
}
