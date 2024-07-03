// Delete Middle of Linked List

Node* deleteMid(Node* head)
{
    if(!head)
    {
        return head;
    }
    else if(!head->next)
    {
        return nullptr;
    }
    
    Node *fast=head,*slow=head;
    
    while(fast->next->next && fast->next->next->next)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    
    Node *temp=slow->next;
    slow->next=slow->next->next;
    delete temp;
    
    return head;
}
