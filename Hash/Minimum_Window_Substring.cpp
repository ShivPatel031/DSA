// Minimum Window Substring leetcode 76

// Given two strings s and t of lengths m and n respectively, return the minimum window 
// substring
//  of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

// The testcases will be generated such that the answer is unique.

// Example 1:

// Input: s = "ADOBECODEBANC", t = "ABC"
// Output: "BANC"
// Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

// Example 2:

// Input: s = "a", t = "a"
// Output: "a"
// Explanation: The entire string s is the minimum window.

// Example 3:

// Input: s = "a", t = "aa"
// Output: ""
// Explanation: Both 'a's from t must be included in the window.
// Since the largest window of s only has one 'a', return empty string.
 
// Constraints:

// m == s.length
// n == t.length
// 1 <= m, n <= 105
// s and t consist of uppercase and lowercase English letters.

string minWindow(string s, string t) 
{
    unordered_map<char,int> m;
    string ans="";

    for(int i = 0 ; i < t.size() ; i++)
    {
        m[t[i]]++;
    }

    int st=0,e=0,length=INT_MAX,check=t.size();

    while(e<s.size())
    {
        if(m.count(s[e]))
        {
            m[s[e]]--;

            if(m[s[e]]>=0)    check--;
        }

        while(check==0)
        {
            if(m.count(s[st]))
            {
                m[s[st]]++;
                if(m[s[st]]>0) check++;
            }

            if(check==1)
            {
                if(length>e-st+1)
                {
                    length=e-st+1;
                    string temp ="";

                    for(int i = st;i<=e;i++)
                    {
                        temp +=s[i];
                    }

                    ans=temp;
                }
            }

            st++;
        }

        e++;
    }

    return ans;
}
