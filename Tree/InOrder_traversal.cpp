// Using recursion
void inOrder_recursive(Node *r){
        if (r == nullptr){
            return;
        }
        inorder(r->left);
        cout<<r->data<<" ";
        inorder(r->right);
    }

// Using iteration
vector<int> inOrder_iterative(Node* root)
    {
        //code here
        stack<Node *> s1;
        stack<bool> s2;
        
        vector<int> ans;
        
        s1.push(root);
        s2.push(0);
        
        while (!s1.empty()){

            Node *temp=s1.top();
            bool t=s2.top();
            s1.pop();
            s2.pop();
            if (t == 0){
                
                if (temp->right){

                s1.push(temp->right);
                s2.push(0);
                }

                s1.push(temp);

                t=1;
                s2.push(t);

                if (temp->left){

                s1.push(temp->left);
                s2.push(0);
                }    
            }
            else{
                ans.push_back(temp->data);
            }
        }
        
        return ans;
    }
