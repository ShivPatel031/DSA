// Reverse a Doubly Linked List GFG

Node* reverseDLL(Node * head)
{
    Node *temp=head;
    
    while(temp->next)
    {
        Node *t=temp->prev;
        temp->prev=temp->next;
        temp->next=t;
        temp=temp->prev;
    }
    
    Node *t=temp->prev;
    temp->prev=temp->next;
    temp->next=t;
    
    return temp;
}
