// Factorials of large numbers GFG

// Given an integer N, find its factorial. return a list of integers denoting the digits that make up the factorial of N.

// Example 1:

// Input: N = 5
// Output: [1,2,0]
// Explanation : 5! = 1*2*3*4*5 = 120

// Example 2:

// Input: N = 10
// Output: [3,6,2,8,8,0,0]
// Explanation :
// 10! = 1*2*3*4*5*6*7*8*9*10 = 3628800

vector<int> factorial(int N){
        vector<int> ans;
        
        ans.push_back(N);
        N--;
        while(N>1){
            int carry = 0;
            for(int i = 0;i<ans.size();i++){
                    int mul = ans[i]*N+carry;
                    ans[i]=mul%10;
                    carry=mul/10;
            }
            
            while(carry){
                ans.push_back(carry%10);
                carry/=10;
            }

            N--;
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
