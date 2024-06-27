// Valid Parentheses leetCode 20

// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
// An input string is valid if:
// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.
 
// Example 1:

// Input: s = "()"
// Output: true
  
// Example 2:

// Input: s = "()[]{}"
// Output: true
  
// Example 3:

// Input: s = "(]"
// Output: false
 
// Constraints:

// 1 <= s.length <= 104
// s consists of parentheses only '()[]{}'.

bool isValid(string s) 
{
    if(s[0] == ')' || s[0] == '}' || s[0] == ']')
    {
        return false;
    }

    stack<char> brackets;

    for(int i = 0;i<s.size();i++)
    {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            brackets.push(s[i]);
        }
        else if(!brackets.empty())
        {
            if((s[i]==')' && brackets.top()=='(') || (s[i]==']' && brackets.top()=='[') || (s[i]=='}' && brackets.top()=='{'))
            {
                brackets.pop();
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    } 

    if(brackets.empty())
    {
        return true;
    }

    return false;      
}
