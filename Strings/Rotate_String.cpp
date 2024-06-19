// Rotate String leetCode 796

// Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.

// A shift on s consists of moving the leftmost character of s to the rightmost position.

// For example, if s = "abcde", then it will be "bcdea" after one shift.
 

// Example 1:

// Input: s = "abcde", goal = "cdeab"
// Output: true
  
// Example 2:

// Input: s = "abcde", goal = "abced"
// Output: false
  
bool rotateString(string s, string goal) {

        if (s.size() != goal.size()) { return false; }

        s = s + s;

        int start = 0;

        while (start < s.size() / 2) 
        {
            bool flag = 0;

            for (int i = 0; i < goal.size(); i++) 
            {
                if (goal[i] != s[start + i]) 
                {
                    flag = 1;
                    break;
                }
            }

            start++;

            if (!flag) 
            {
                return true;
            }
        }

        return false;
    }
