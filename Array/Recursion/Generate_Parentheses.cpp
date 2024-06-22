// Generate Parentheses leetcode 22 GFG

// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

// Example 1:

// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]
// Example 2:

// Input: n = 1
// Output: ["()"]

void subset(vector<string> &ans,int n,string temp,int oc,int cc){

        if(oc+cc==2*n)
        {
            ans.push_back(temp);
            return;
        }


        if(oc<n)
        {
            temp.push_back('(');
            subset(ans,n,temp,oc+1,cc);
            temp.pop_back();
        }        
        if(cc<oc)
        {
            temp.push_back(')');
            subset(ans,n,temp,oc,cc+1);
            temp.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) 
    {

        vector<string> ans;
        string temp="";
        subset(ans,n,temp,0,0);

        return ans;
    }
