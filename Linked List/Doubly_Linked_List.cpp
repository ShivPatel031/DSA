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
                temp->prev=tail;
                tail->next=temp;
                tail=temp;
              }
        }


        void insertAtGivenIndex(int x,int index)
        {
              if(head == nullptr)
              {
                  cout<<"Linked list is empty";
                  return;
              }
                
              Node *temp = head,*past=nullptr;
            
              while(temp && index--)
              {
                  temp=temp->next;
              }
            
              if(temp==nullptr && index>0)
              {
                  cout<<"Index is out of range";
                  return;
              }
              else if(temp==nullptr && index==0)
              {
                  Node *newNode = new Node(x);
                  newNode->next=temp;
                  newNode->prev=tail;
                  tail->next=newNode;
                  tail=newNode;
              }
              else
              {
                  Node *newNode = new Node(x);
                  newNode->next=temp;
                  newNode->prev=temp->prev;
                  temp->prev->next=newNode;
                  temp->prev=newNode;
              }
        }


        void deleteFromFront()
        {
            if(head==nullptr)
            {
                cout<<"Linked list underflow";
                return;
            }
        
            Node *temp=head;
            head=head->next;
            delete temp;
        }


        void deleteFromBack()
        {
            if(head==nullptr)
            {
                cout<<"Linked list underflow";
                return;
            }
        
            Node *temp=tail;
            tail=tail->prev;
            delete temp;
        }

       void deleteFromGivenIndex(int index)
        {
              if(head == nullptr)
              {
                  cout<<"Linked list is empty";
                  return;
              }
              else if(index==0)
              {
                  deleteFromFront();
              }
                
              while(temp && index--)
              {
                  temp=temp->next;
              }
            
              if(temp==nullptr && index>=0)
              {
                  cout<<"Index is out of range";
                  return;
              }
              else if(temp && index=0)
              {
                  deleteFromBack();
              }
              else
              {
                  temp->prev->next=temp->next;
                  temp->next->prev=temp->prev;
                  delete temp;
              }
        }


}
        
// creatring linked list using recuresion from array
        
Node* createLinkedList(vector<int> &arr,int index,Node *pastNode)
{
        if(index==arr.size())
        {
            return nullptr;
        }
        
        Node* temp = new Node(arr[index]);
        temp->prev=pastNode;
        temp->next = createLinkedList(arr,index+1,temp);
        return temp;
}
