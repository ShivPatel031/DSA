// Case-specific Sorting of Strings GFG

// Given a string S consisting of only uppercase and lowercase characters. The task is to sort uppercase and lowercase letters separately such that if the ith place in the original string had an Uppercase character then it should not have a lowercase character after being sorted and vice versa.

// Example 1:

// Input:
// N = 12
// S = defRTSersUXI
// Output: deeIRSfrsTUX
// Explanation: Sorted form of given string
// with the same case of character as that
// in original string is deeIRSfrsTUX

// Example 2:

// Input:
// N = 6
// S = srbDKi
// Output: birDKs
// Explanation: Sorted form of given string
// with the same case of character will
// result in output as birDKs.

string caseSort(string s, int n)
    {
        vector<int> lowercase(26, 0);
        vector<int> uppercase(26, 0);

        for (int i = 0; i < s.size(); i++) 
        {
            if (s[i] >= 'a' && s[i]<='z') 
            {
                lowercase[s[i] - 'a']++;
                s[i] = '#';
            } 
            else if (s[i] >= 'A' && s[i] <= 'Z') 
            {
                uppercase[s[i] - 'A']++;
                s[i] = '&';
            }
        }

        string ans,ans2;

        for (int i = 0; i < uppercase.size(); i++) 
        {
            while (uppercase[i]) 
            {
                ans += i + 'A';
                uppercase[i]--;
            }
        }
        for (int i = 0; i < lowercase.size(); i++) 
        {
            while (lowercase[i]) 
            {
                ans2 += i + 'a';
                lowercase[i]--;
            }
        }

        int index = 0;
        int index2=0;

        for (int i = 0; i < s.size(); i++) 
        {
            if (s[i] == '&') 
            {
                s[i] = ans[index];
                index++;
            }
            else
            {
               s[i] = ans2[index2];
                index2++; 
            }
        }

        return s;
    }
