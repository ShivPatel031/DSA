// Find Common Nodes in two BSTs GFG

// Given two Binary Search Trees. Find the nodes that are common in both of them, ie- find the intersection of the two BSTs.

// Note: Return the common nodes in sorted order.

// Example 1:

// Input:
// BST1:
//                   5
//                /     \
//              1        10
//            /   \      /
//           0     4    7
//                       \
//                        9
// BST2:
//                 10 
//               /    \
//              7     20
//            /   \ 
//           4     9
// Output: 4 7 9 10

// Example 2:

// Input:
// BST1:
//      10
//     /  \
//    2   11
//   /  \
//  1   3
// BST2:
//        2
//      /  \
//     1    3
// Output: 1 2 3
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function findCommon() that takes roots of the two BSTs as input parameters and returns a list of integers containing the common nodes in sorted order. 

// Expected Time Complexity: O(N1 + N2) where N1 and N2 are the sizes of the 2 BSTs.
// Expected Auxiliary Space: O(H1 + H2) where H1 and H2 are the heights of the 2 BSTs.

// Constraints:
// 1 <= Number of Nodes <= 105
// 1 <= Node data <= 109


vector <int> findCommon(Node *root1, Node *root2)
{
    vector<int> ans;
    stack<Node *> s1,s2;
    
    s1.push(root1);
    s2.push(root2);
    
    while(s1.top()->left)
    {
        s1.push(s1.top()->left);
    }
    while(s2.top()->left)
    {
        s2.push(s2.top()->left);
    }
    
    while(!s1.empty() && !s2.empty())
    {
        if(s1.top()->data == s2.top()->data)
        {
            ans.push_back(s1.top()->data);
            
            if(s1.top()->right)
            {
                Node *temp=s1.top();
                s1.pop();
                
                s1.push(temp->right);
                
                while(s1.top()->left){
                    s1.push(s1.top()->left);
                }
            }
            else
            {
                s1.pop();
            }
            
            if(s2.top()->right)
            {
                Node *temp=s2.top();
                s2.pop();
                s2.push(temp->right);
                
                while(s2.top()->left){
                    s2.push(s2.top()->left);
                }
            }
            else
            {
                s2.pop();
            }
        }
        else if(s1.top()->data < s2.top()->data)
        {
            if(s1.top()->right)
            {
                Node *temp=s1.top();
                s1.pop();
                s1.push(temp->right);
                
                while(s1.top()->left){
                    s1.push(s1.top()->left);
                }
            }
            else{
                s1.pop();
            }
        }
        else if(s1.top()->data > s2.top()->data)
        {
            if(s2.top()->right)
            {
                Node *temp=s2.top();
                s2.pop();
                s2.push(temp->right);
                
                while(s2.top()->left){
                    s2.push(s2.top()->left);
                }
            }
            else{
                s2.pop();
            }
        }
    }
    
    return ans;
}
