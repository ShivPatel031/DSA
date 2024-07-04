class Node
{
    public:
    int data;
    Node *next;
  
    Node()
    {
      next=nullptr;
    }
  
    Node(int x)
    {
      data=x;
      next=nullptr;
    }
};

class LinkeList
{
    Node *head,*tail;
    int size;
    public:


    LinkeList()
    {
      head=nullptr;
      tail=nullptr;
      size=0;
    }


    void addAtFront(int x)
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
        head=temp;
      }
      size++;
    }


    void addAtBack(int x)
    {
      if(head==nullptr)
      {
        head=new Node(x);
        tail=head;
      }
      else
      {
        Node *temp = new Node(x);
        tail->next=temp;
        tail=temp;
      }
      size++;
    }


    void addAfterIndex(int x,int index)
    {
        if(head==nullptr)
        {
          head=new Node(x);
          tail=head;
          cout<<"Given index does not exist";
        }
        else
        {
          index--;
          Node *temp = head;
          while(index--)
          {
            if(!temp->next)
            {
              cout<<"Index does not exist";
              break;
            }
            temp=temp->next;
          }
          Node *newNode = new Node(x);
          newNode->next=temp->next;
          temp->next=newNode;
        }
        size++;
    }

};
