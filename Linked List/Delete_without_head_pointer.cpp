// Delete without head pointer

void deleteNode(Node *del_node)
{
   del_node->data = del_node->next->data;
   Node *temp=del_node->next;
   del_node->next=temp->next;
   delete temp;
}
