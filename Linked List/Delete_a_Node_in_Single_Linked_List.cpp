// Delete a Node in Single Linked List GFG Leetcode 


Node* deleteNode(Node *head,int x)
{
    //Your code here
    if (!head){
        return nullptr;
    }
    else if (!head->next){
        return head;
    }
    Node *temp=head,*past=nullptr;
    while(x>1 && temp !=nullptr){
        past=temp;
        temp=temp->next;
        x--;
    }
    // std::cout<<past->data;
    if (past != nullptr){
    past->next=temp->next;
    }else{
        head=head->next;
    }
    free(temp);
    
    return head;
}
