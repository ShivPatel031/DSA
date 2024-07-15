// Construct BST from Postorder GFG

// Given postorder traversal of a Binary Search Tree, you need to construct a BST from postorder traversal. The output will be inorder traversal of the constructed BST.

// Example 1:

// Input:
// 6
// 1 7 5 50 40 10

// Output:
// 1 5 7 10 40 50

// Explanation:
// Testcase 1: The BST for the given post order traversal is:

// Thus the inorder traversal of BST is: 1 5 7 10 40 50.
// Your Task:
// The task is to complete the function constructTree() which takes an array post[], size as as the argument and returns the root of BST.

// Expected Time Complexity: O(No. of  nodes in BST)
// Expected Auxiliary Space: O(No. of  nodes in BST)

// Constraints:
// 1 <= T <= 100
// 1 <= N <= 200

// most optimize
Node *createBST(int post[],int &index,int bound,int &size)
{
    if(index<=-1 || post[index]<bound) return nullptr;
    
    Node *temp = new Node(post[index--]);
    
    temp->right=createBST(post,index,temp->data,size);
    temp->left=createBST(post,index,bound,size);
    
    return temp;
}

Node *constructTree (int post[], int size)
{
    int i = size-1;
    
    return createBST(post,i,INT_MIN,size);
}


// simple and understable
Node* createBST(int postorder[],int &index,int left,int right)
{
    if(index<=-1) return nullptr;

    Node* temp = new Node(postorder[index]);

    if(index-1 !=-1)
    {
        index=index-1;
        
        if(postorder[index]>temp->data && postorder[index]<right)
        {
            temp->right=createBST(postorder,index,temp->data,right);
        }

        if(left<postorder[index] && postorder[index]<temp->data)
        {
            temp->left = createBST(postorder,index,left,temp->data);
        }

       
    }
        
    return temp;
}

Node *constructTree (int post[], int size)
{
    int i = size-1;
    
    return createBST(post,i,INT_MIN,INT_MAX);
}
