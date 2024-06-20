// Repeated String Match leetcode 686

// Given two strings a and b, return the minimum number of times you should repeat string a so that string b is a substring of it. If it is impossible for b​​​​​​ to be a substring of a after repeating it, return -1.

// Notice: string "abc" repeated 0 times is "", repeated 1 time is "abc" and repeated 2 times is "abcabc".

// Example 1:

// Input: a = "abcd", b = "cdabcdab"
// Output: 3
// Explanation: We return 3 because by repeating a three times "abcdabcdabcd", b is a substring of it.
  
// Example 2:

// Input: a = "a", b = "aa"
// Output: 2

int repeatedStringMatch(string a, string b) {

        string str = a;
        int count = 1;

        while (str.size() < b.size()) 
        {
            count++;
            str += a;
        }

        vector<int> match(b.size(), 0);

        int first = 0, end = 1;

        while (end < b.size()) 
        {
            if (b[first] == b[end]) 
            {
                match[end] = first + 1;
                first++;
                end++;
            } 
            else 
            {
                if (first == 0) 
                {
                    end++;
                } 
                else 
                {
                    first = match[first - 1];
                }
            }
        }

        int temp = 0;
        while (temp < 2) 
        {
            first = 0, end = 0;

            while (end < b.size()) 
            {
                if (first >= str.size()) 
                {
                    break;
                }

                if (str[first] == b[end]) 
                {
                    first++;
                    end++;
                } 
                else 
                {
                    if (end == 0) 
                    {
                        first++;
                    } 
                    else 
                    {
                        end = match[end - 1];
                    }
                }
            }

            if (end == b.size()) 
            {
                return count;
            }
            
            str = str + a;
            count++;
            temp++;
        }

        return -1;
    }
