// Is Binary Tree Heap GFG

// Given a binary tree. The task is to check whether the given tree follows the max heap property or not.
// Note: Properties of a tree to be a max heap - Completeness and Value of node greater than or equal to its child.

// Example 1:

// Input:
//       5
//     /  \
//    2    3
// Output: 1
// Explanation: The given tree follows max-heap property since 5,
// is root and it is greater than both its children.

// Example 2:

// Input:
//        10
//      /   \
//     20   30 
//   /   \
//  40   60
// Output: 0

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function isHeap() which takes the root of Binary Tree as parameter returns True if the given binary tree is a heap else returns False.

// Expected Time Complexity: O(N)
// Expected Space Complexity: O(N)

// Constraints:
// 1 ≤ Number of nodes ≤ 100
// 1 ≤ Data of a node ≤ 1000

// using recursion 

void checkHeap(struct Node* tree,int &node,bool &flag)
{
    if(!tree) return;
    
    if(tree->left && (tree->data < tree->left->data))
    {
        flag = 1 ;
        return;
    }
    
    if(tree->right && (tree->data < tree->right->data))
    {
        flag = 1 ;
        return;
    }
    
    node++;
    
    checkHeap(tree->left,node,flag);
    checkHeap(tree->right,node,flag);
}

void checkIndex(struct Node* tree,int index,int &maxIndex)
{
    if(!tree) return;
    
    if(tree->left)
    {
        int leftIndex = 2*index +1;
        
        if(maxIndex<leftIndex) maxIndex=leftIndex;
    }
    
    if(tree->right)
    {
        int rightIndex = 2*index+2;
        
        if(maxIndex < rightIndex) maxIndex =  rightIndex;
    }
    
    checkIndex(tree->left,2*index+1,maxIndex);
    checkIndex(tree->right,2*index+2,maxIndex);
    
}

bool isHeap(struct Node* tree) 
{    
    if(!tree) return 0;
    
    bool flag = 0;
    int node=0;
    
    checkHeap(tree,node,flag);
    
    if(flag) return 0;
    
    int maxIndex = 0;
    
    checkIndex(tree,0,maxIndex);
    
    if(maxIndex!=node-1) return 0;
  
    return 1;   
}


// using level order traversal
bool isHeap(struct Node* tree) 
{ 
    if(!tree) return 0;
    
    bool flag = 0;
    
    queue<Node *> q;
    int count = 0 ;
    
    q.push(tree);
    
    while(!q.empty())
    {
        count=q.size();
        
        while(count--)
        {
            Node *temp = q.front();
            q.pop();
            
            if(flag && (temp->left || temp->right)) return 0;
            
            if(temp->left)
            {
                if(temp->left->data > temp->data)
                {
                    return 0;
                }
                else
                {
                    q.push(temp->left);
                    
                    if(temp->right)
                    {
                        if(temp->right->data < temp->data)
                        {
                            q.push(temp->right);
                        }
                        else
                        {
                            return 0;
                        }
                    }
                    else
                    {
                        flag=1;
                    }
                }
                
            }
            else if(temp->right)
            {
                return 0;
            }
            else
            {
                flag = 1 ;
            }
        }
    }
    
    return 1;
    
}
