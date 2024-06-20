// Search Pattern (KMP-Algorithm) GFG

// Given two strings, one is a text string, txt and other is a pattern string, pat. The task is to print the indexes of all the occurences of pattern string in the text string. Use one-based indexing while returning the indices. 
// Note: Return an empty list incase of no occurences of pattern. Driver will print -1 in this case.

// Example 1:

// Input:
// txt = "geeksforgeeks"
// pat = "geek"
// Output: 
// 1 9
// Explanation: 
// The string "geek" occurs twice in txt, one starts are index 1 and the other at index 9. 
  
// Example 2:

// Input: 
// txt = "abesdu"
// pat = "edu"
// Output: 
// -1
// Explanation: 
// There's not substring "edu" present in txt.


vector <int> search(string needle, string haystack)
        {
            int first = 0,second=1;
            
            vector<int> ans;

            vector<int> match(needle.size(),0);
    
            while(second<needle.size())
            {
                if(needle[first]==needle[second])
                {
                    match[second]=first+1;
                    first++;
                    second++;
                    
                }
                else
                {
                    if(first==0)
                    {
                        second++;
                    }
                    else
                    {
                        first=match[first-1];
                    }
                }
                
            }
    
            first=0;
            second=0;
    
            while(first<haystack.size())
            {
                
    
                if(haystack[first]==needle[second])
                {
                    first++;
                    second++;
                }
                else
                {
                    if(second==0)
                    {
                        first++;
                    }
                    else
                    {
                        second=match[second-1];
                    }   
                }
                
                if(second>=needle.size())
                {
                    ans.push_back(first-second+1);
                    second=match[second-1]; //remember why use this
                    
                }
            }
            
            if(ans.size()==0)
            {
                ans.push_back(-1);
            }
            return ans;
    
        }
