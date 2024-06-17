// using recursion
void postorder_recursive(Node *r){

        if (r == nullptr){
            return;
        }

        // NLR

        cout<<r->data<<" ";

        postorder(r->left);
        
        postorder(r->right);
    }

// using iteration
void postorder_iteration(Node *r){

        vector<int> ans;
        stack<Node *> s;

        s.push(root);

        while (!s.empty()){

            Node *temp=s.top();
            s.pop();

            ans.push_back(temp->data);

            if (temp->left) s.push(temp->left);
            if (temp->right) s.push(temp->right);  // we add right Node last because then Right Node came on top
        }
        // we got ans but in reverse

        //to reverse ans 
        for (int i=0;i<ans.size()/2;i++){

            int temp=ans[i];
            ans[i]=ans[ans.size()-1-i];
            ans[ans.size()-1-i]=temp;
        }

        //display result
        for (auto it : ans){
            cout<<it<< " ";
        }
    }
