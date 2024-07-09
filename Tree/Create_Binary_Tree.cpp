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

int main()
{
  int x;
  cout<<"Enter the root element :";
  cin>>x;

  int first,second;
  queue<Node *> q;
  Node *root=new Node(x);
  q.push(root);

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
