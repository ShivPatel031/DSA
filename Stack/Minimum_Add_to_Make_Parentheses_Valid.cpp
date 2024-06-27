// Minimum Add to Make Parentheses Valid leetcode 921

// A parentheses string is valid if and only if:
// It is the empty string,
// It can be written as AB (A concatenated with B), where A and B are valid strings, or
// It can be written as (A), where A is a valid string.
// You are given a parentheses string s. In one move, you can insert a parenthesis at any position of the string.

// For example, if s = "()))", you can insert an opening parenthesis to be "(()))" or a closing parenthesis to be "())))".
// Return the minimum number of moves required to make s valid.

// Example 1:

// Input: s = "())"
// Output: 1
// Example 2:

// Input: s = "((("
// Output: 3
 

// Constraints:

// 1 <= s.length <= 1000
// s[i] is either '(' or ')'.

// can do with stack but this one's O(1) space complexcity

int minAddToMakeValid(string s) 
{
    int ocount=0,ccount=0;
  
    for(int i = 0;i<s.size();i++)
    {
        if(s[i]=='(')
        {
            ocount++;
        }
        else if(s[i]==')' && ocount>0)
        {
            ocount--;
        }
        else
        {
            ccount++;
        }
    }
  
    return ocount+ccount;
}
