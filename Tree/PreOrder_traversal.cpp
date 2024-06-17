// using recurtion
void preorder_recursive(Node *r){
        if (r == nullptr){
            return;
        }
        cout<<r->data<<" ";


        preorder_recursive(r->left);
        
        preorder_recursive(r->right);

}

//using iteretion
void preorder_iteretive(Node *r){
        stack<Node *> s;
        s.push(root);

        while (!s.empty()){
            Node *temp=s.top();
            s.pop();

            cout<<temp->data<<' ';

            if (temp->right) s.push(temp->right);   //take roo->right on top because in stack r->left will be on top
            if (temp->left) s.push(temp->left);
            

        }
}
