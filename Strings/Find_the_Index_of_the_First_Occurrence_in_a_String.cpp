// Find the Index of the First Occurrence in a String leetcode 28

// Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack. 

// Example 1:

// Input: haystack = "sadbutsad", needle = "sad"
// Output: 0
// Explanation: "sad" occurs at index 0 and 6.
// The first occurrence is at index 0, so we return 0.

// Example 2:

// Input: haystack = "leetcode", needle = "leeto"
// Output: -1
// Explanation: "leeto" did not occur in "leetcode", so we return -1.

  
int strStr(string haystack, string needle) 
    {

        int first = 0,second=1;

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

        while(second<needle.size())
        {

            if(first>=haystack.size())
            {
                return -1;
            }

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
        }

        return first-second;
        
    }
