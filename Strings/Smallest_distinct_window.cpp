// Smallest distinct window GFG

// Given a string 's'. The task is to find the smallest window length that contains all the characters of the given string at least one time.
// For eg. A = aabcbcdbca, then the result would be 4 as of the smallest window will be dbca.

// Example 1:

// Input : "AABBBCBBAC"
// Output : 3
// Explanation : Sub-string -> "BAC"
  
// Example 2:
// Input : "aaab"
// Output : 2
// Explanation : Sub-string -> "ab"
 
// Example 3:
// Input : "GEEKSGEEKSFOR"
// Output : 8
// Explanation : Sub-string -> "GEEKSFOR"

int findSubString(string s)
    {
        vector<int> check(256,0);
        int window = 0,ans=s.size();
        
        for(int i = 0;i<s.size();i++)
        {
            if(check[s[i]]==0)
            {
                window++;
            }
            check[s[i]]++;
        }
        
        fill(check.begin(),check.end(),0);
        
        int start=0,end=0;
        
        while(end<s.size())
        {
            while(window && end<s.size())
            {
                if(check[s[end]]==0)
                {
                    window--;
                }
                
                check[s[end]]++;
                end++;
            }
            
            if(ans>end-start)
            {
                ans=end-start;
            }
            
            while(window!=1)
            {
                
                if(ans>end-start)
                {
                    ans=end-start;
                }
                
                check[s[start]]--;
                
                if(check[s[start]]==0)
                {
                    window++;
                }
                
                start++;
            }
                
        }
            
        
        return ans;
        
    }
