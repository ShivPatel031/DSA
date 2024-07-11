// Cousins of a given node GFG

// Given a binary tree and a node, print all cousins of given node in order of their appearance. Note that siblings should not be printed.

// Example 1:

// Input : 
//              1
//            /   \
//           2     3
//         /   \  /  \
//        4    5  6   7

// Given node : 5
// Output : 6 7
// Explanation :
// Nodes 6 and 7 are on the same level 
// as 5 and have different parents.

// Example 2 :

// Input :
//          9
//         /
//        5
// Given node : 5
// Output : -1
// Explanation :
// There no other nodes than 5 in the same level.
// Your task :
// You don't have to read input or print anything. Your task is to complete the function printCousins() which takes the root node of the tree and the node whose cousins need to be found, as input and returns a list containing the cousins of the given node in order of their appearance in the tree. If there is no cousin of the given node, return -1 as the first element of the list.
 
// Expected Time Complexity : O(n)
// Expected Auxiliary Space : O(n)
 
// Constraints :
// 1 <= n <=10^5

vector<int> printCousins(Node* root, Node* node_to_find)
{
    vector<int> ans;
    if(!root) return ans;
    
    queue<Node *> q;
    q.push(root);
    int count=0;
    bool flag=0;
    
    while(!q.empty())
    {
        count=q.size();
        vector<Node *> arr;
        
        while(count--)
        {
            Node *temp = q.front();
            q.pop();
            arr.push_back(temp);
            
            if(temp->left) q.push(temp->left);
            
            if(temp->right) q.push(temp->right);
            
            if(temp->left==node_to_find || temp->right == node_to_find)
            {
              flag=1;   
            }
            
            
            
        }
        
        if(flag)
        {
            for(int i = 0;i<arr.size();i++)
            {
                if(arr[i]->left != node_to_find && arr[i]->right != node_to_find)
                {
                    if(arr[i]->left)    ans.push_back(arr[i]->left->data);
                    if(arr[i]->right)   ans.push_back(arr[i]->right->data);
                }
            }
            
            break;
        }
    }
    
    if(ans.size()==0) ans.push_back(-1);
    
    return ans;
    
}
