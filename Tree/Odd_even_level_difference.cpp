// Odd even level difference

// Given a Binary Tree. Find the difference between the sum of node values at even levels and the sum of node values at the odd levels.

// Example 1:

// Input:
//             1
//           /   \
//          2     3

// Output: -4

// Explanation:
// sum at odd levels - sum at even levels
// = (1)-(2+3) = 1-5 = -4

int getLevelDiff(Node *root)
{
     queue<Node *> q;
     int sumOfOdd = 0;
     int sumOfEven = 0;
     int flag=1;
     int count = 0;
      q.push(root);

      while (!q.empty()){
        count=q.size();
        
        while(count--)
        {
            Node *temp=q.front();
            q.pop();

            if(flag)
            {
                sumOfOdd+=temp->data;
            }
            else
            {
                sumOfEven+=temp->data;
            }

            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
        
        flag=!flag;
    }
    
    return sumOfOdd - sumOfEven;
}
