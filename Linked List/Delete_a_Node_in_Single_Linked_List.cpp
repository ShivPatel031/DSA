// Delete a Node in Single Linked List GFG Leetcode 


Node* deleteNode(Node *head,int x)
{
    if(!head){
        return nullptr;
    }
    
    Node *temp=head,*past=nullptr;
    while(x>1 && temp != nullptr)
    {
        past=temp;
        temp=temp->next;
        x--;
    }
    
    if(past)
    {
        past->next=temp->next;
    }
    else
    {
        head=head->next;
    }
    
    delete temp;
    
    return head;
}

// with recursion
Node* deleteNode(Node *head,int x)
{
   
   if(x==1)
   {
       Node *temp=head->next;
       delete head;
       return temp;
   }
   
   head->next = deleteNode(head->next,x-1);
   
   return head;
}
