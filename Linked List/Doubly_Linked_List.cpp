// Doubly linked list

class Node
{
    public:
    int data;
    Node *next;
    Node *prev;
    
    Node(int x)
    {
      data=x;
      next=nullptr;
      prev=nullptr;
    }
}

class DoublyLinkedList
{
Node *head;
Node *tail;
public:
DoublyLinkedList()
{
  head=nullptr;
}

void insertAtFront(int x)
{
  if(head==nullptr)
  {
    head=new Node(x);
    tail=head;
  }
  else
  {
    Node *temp = new Node(x);
    temp->next=head;
    temp->prev=nullptr;
    head->prev=temp
    head=temp;
  }
}

void insertAtBack(int x)
{
  if(head==nullptr)
  {
    head=new Node(x);
    tail=head;
  }
  else
  {
    Node *temp = new Node(x);
    temp->next=nullptr;
    temp->prev=tail;
    tail->next=temp;
    tail=temp;
  }
}

void insertAtGivenIndex(int x,int index)
{
  Node *temp = head,*past=nullptr;

  while(temp && index--)
  {
      
  }
}
}
