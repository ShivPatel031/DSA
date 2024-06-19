// Longest Substring Without Repeating Characters leetcode 3

// Given a string s, find the length of the longest 
// substring
//  without repeating characters.

 

// Example 1:

// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.
  
// Example 2:

// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
  
// Example 3:

// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

int lengthOfLongestSubstring(string s) {

        if(s.size()==1){return 1;}
        else if(s.size()==0){return 0;}

       int ans=0;

       int start = 0,end=0;

       while (end<s.size()-1)
       {
            end++;
            int i=start;

            while(i<end)
            {
                if(s[i]==s[end])
                {
                    start=i+1;
                    break;
                }
                i++;
            }
            if(end-start+1>ans)
            {
                ans=end-start+1;
            }
       } 

       return ans;
    }
