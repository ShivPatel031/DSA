// leetCode 409 Longest Palindrome

// Given a string s which consists of lowercase or uppercase letters, return the length of the longest 
// palindrome
//  that can be built with those letters.

// Letters are case sensitive, for example, "Aa" is not considered a palindrome.

// Example 1:

// Input: s = "abccccdd"
// Output: 7
// Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.
  
// Example 2:

// Input: s = "a"
// Output: 1
// Explanation: The longest palindrome that can be built is "a", whose length is 1.
  
int longestPalindrome(string sentence) {
        vector<int> check(26, 0);
        vector<int> check2(26, 0);
        int ans = 0;

        for (int i = 0; i < sentence.size(); i++) 
        {
            if (sentence[i] >= 'a' && sentence[i] <= 'z') 
            {
                check[sentence[i] - 'a']++;
            } 
            else if (sentence[i] >= 'A' && sentence[i] <= 'Z') 
            {
                check2[sentence[i] - 'A']++;
            }
        }

        int odd = 0;

        for (int i = 0; i < check.size(); i++) 
        {
            if (check[i] % 2 == 0) 
            {
                ans += check[i];
            }
            else 
            {
                ans += check[i] - 1;
                if(odd == 0){
                  odd++;
                }
            }

            if (check2[i] % 2 == 0) 
            {
                ans += check2[i];
            } 
            else 
            {
                ans += check2[i] - 1;
                if(odd == 0){
                  odd++;
                }
              
            }
        }

        if (odd != 0) 
        {
            return ans + 1;
        } 
        else 
        {
            return ans;
        }
    }
