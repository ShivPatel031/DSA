// Minimum characters to be added at front to make string palindrome GFG

// Given string str of length N. The task is to find the minimum characters to be added at the front to make string palindrome.
// Note: A palindrome is a word which reads the same backward as forward. Example: "madam".

// Example 1:

// Input:
// S = "abc"
// Output: 2
// Explanation: 
// Add 'b' and 'c' at front of above string to make it
// palindrome : "cbabc"
  
// Example 2:

// Input:
// S = "aacecaaa"
// Output: 1
// Explanation: Add 'a' at front of above string
// to make it palindrome : "aaacecaaa"

int minChar(string str){
        
        string str2=str;
        
        reverse(str2.begin(),str2.end());
        
        string newstr = str+'$'+str2;
        
        vector<int> lps(newstr.size(),0);
        
        
        int first=0,end=1;
        
        while (end<newstr.size())
        {
            
            if(newstr[first]==newstr[end])
            {
                lps[end]=first+1;
                first++;
                end++;
            }
            else
            {
                if(first==0)
                {
                    end++;
                }
                else
                {
                    first=lps[first-1];
                }
            }
        }
        
        
        
        return str.size()-lps[lps.size()-1];
    }
