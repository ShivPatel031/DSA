// Backspace String Compare leetcode 844

// Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.

// Note that after backspacing an empty text, the text will continue empty.

// Example 1:

// Input: s = "ab#c", t = "ad#c"
// Output: true
// Explanation: Both s and t become "ac".
  
// Example 2:

// Input: s = "ab##", t = "c#d#"
// Output: true
// Explanation: Both s and t become "".
  
// Example 3:

// Input: s = "a#c", t = "b"
// Output: false
// Explanation: s becomes "c" while t becomes "b".
 

// Constraints:

// 1 <= s.length, t.length <= 200
// s and t only contain lowercase letters and '#' characters.


bool backspaceCompare(string s, string t) {
    
    string s1="",t1="";

    int n =  max(s.size(),t.size());

   for(int i = 0;i<n;i++)
   {
        if(i<s.size() && s[i]>='a' && s[i]<='z')
        {
            s1.push_back(s[i]);
        }
        else if(i<s.size() && s[i]=='#' and s1.size()>0)
        {
            s1.pop_back();
        }
        
        if(i<t.size() && t[i]>='a' && t[i]<='z')
        {
            t1.push_back(t[i]);
        }
        else if(i<t.size() && t[i]=='#' and t1.size()>0){
            t1.pop_back();
        }
   }
    
    if(s1==t1)
    {
        return true;
    }

    return false;
}
