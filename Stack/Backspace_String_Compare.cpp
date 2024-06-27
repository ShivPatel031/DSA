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

// this is not best way because we are using stack so space is O(n) and using loop four times
// can do using two pointers with single loop

bool backspaceCompare(string s, string t) 
{        
    string s1="",t1="";

    stack<char> temp;

    for(int i = 0 ;i<s.size();i++)
    {
        if(temp.empty() && s[i]!='#')
        {
            temp.push(s[i]);
        }
        else if(s[i]=='#' && !temp.empty())
        {   
            temp.pop();
        }
        else if(s[i]>='a' && s[i] <= 'z')
        {
            temp.push(s[i]);
        }
    }

    while(!temp.empty())
    {
        s1+=temp.top();
        temp.pop();
    }

    for(int i = 0 ;i<t.size();i++)
    {
        if(temp.empty() && t[i]!='#')
        {
            temp.push(t[i]);
        }
        else if(t[i]=='#' && !temp.empty())
        {   
            temp.pop();
        }
        else if(t[i]>='a' && t[i] <= 'z')
        {
            temp.push(t[i]);
        }
    }

    while(!temp.empty())
    {
        t1+=temp.top();
        temp.pop();
    }

    if(s1==t1)
    {
        return true;
    }

    return false;
}
