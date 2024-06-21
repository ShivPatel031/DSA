// Longest Palindromic Substring leetcode 5

// Given a string s, return the longest palindromic substring in s.

// Example 1:

// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.
  
// Example 2:

// Input: s = "cbbd"
// Output: "bb"

string longestPalindrome(string s) {

        int start = 0 , index = 0 ,length=0;

        while(start<s.size())
        {

            string str1,str2;

            for(int i = start;i<s.size();i++)
            {
                str1+=s[i];
            }

            if(str1.size()<length){
                break;
            }

            str2=str1;
            reverse(str2.begin(),str2.end());

            str1=str1+'$'+str2;

            int first=0,second=1;

            vector<int> lps(str1.size(),0);

            while(second<str1.size())
            {
                if(str1[second]==str1[first])
                {
                    lps[second]=first+1;
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
                        first=lps[first-1];
                    }

                }
            }
                
            cout<<lps[lps.size()-1];

            if(length<lps[lps.size()-1])
            {
                length=lps[lps.size()-1];
                index=start;
            }

            start++;


        }

        string ans;

        for(int i=index;i<index+length;i++)
        {
            ans+=s[i];
        }

        return ans;
        
    }
