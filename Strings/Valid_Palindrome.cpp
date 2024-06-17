// Valid Palindrome leetCode 125

// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

// Given a string s, return true if it is a palindrome, or false otherwise.

 

// Example 1:

// Input: s = "A man, a plan, a canal: Panama"
// Output: true
// Explanation: "amanaplanacanalpanama" is a palindrome.
  
// Example 2:

// Input: s = "race a car"
// Output: false
// Explanation: "raceacar" is not a palindrome.
  
// Example 3:

// Input: s = " "
// Output: true
// Explanation: s is an empty string "" after removing non-alphanumeric characters.
// Since an empty string reads the same forward and backward, it is a palindrome.

bool isPalindrome(string s) {
        
       if (s == ""){
            return true;
        }

        string sos="";
        
        for(int i=0;i<s.length();i++){
            if (s[i] >= 'A' and s[i] <= 'Z'){
                s[i]=s[i]+32;
                sos+=s[i];
            }else if (s[i] >= 'a' and s[i] <= 'z' or s[i] >='0' and s[i] <= '9'){
                sos+=s[i];
            }

        }
        int i = 0, n = sos.length();

        if (n > 0){
            while (i<n){
                if (sos[i] != sos[n-1]){
                    return false;
                }
                i++;
                n--;
            }
        }
        return true;
    }
