// by adding at end

class Node
{
    public:
    int data;
    Node *next;
    
    Node(int x)
    {
      data=x;
      next=nullptr;
    }
};

Node* CreateLinkedList(int arr[],int n,int index)
{
  if(index==size)
  {
    return nullptr;
  }

  Node *temp = new Node(arr[index]);
  temp->next = CreateLinkeList(arr,n,index+1);
  return temp;
}
