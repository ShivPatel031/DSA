// Pangram Strings GFG

// Check if the given string S is a Panagram or not. A pangram is a sentence containing every letter in the English Alphabet.

// Example 1:

// Input: S = "Pack mY box witH fIve dozen 
//             liquor jugs"
// Output: 1
// Explanation: Given string contains all 
// English Alphabets. 
  
// Example 2:

// Input: S = "geeksFORgeeks"
// Output: 0
// Explanation: Given string does not contain 
// all English Alphabets. 

int isPanagram(string sentence)
	{
	    vector<bool> check(26,0);

        for(int i = 0;i<sentence.size();i++){
            
            if(sentence[i]>=97 && sentence[i]<=97+25)
            {
                check[sentence[i]-97]=1;
            }
            else if(sentence[i]>=65 && sentence[i]<=65+25)
            {
                check[sentence[i]-65]=1;
            }
        }

        for(int i = 0 ; i < check.size();i++)
        {
            if (check[i] == 0)
            {
                return 0;
            }
        }
	    
	    return 1;
	}


// Check if the Sentence Is Pangram leetCode 1832

// A pangram is a sentence where every letter of the English alphabet appears at least once.

// Given a string sentence containing only lowercase English letters, return true if sentence is a pangram, or false otherwise.

 

// Example 1:

// Input: sentence = "thequickbrownfoxjumpsoverthelazydog"
// Output: true
// Explanation: sentence contains at least one of every letter of the English alphabet.
  
// Example 2:

// Input: sentence = "leetcode"
// Output: false

bool checkIfPangram(string sentence) {
        vector<bool> check(26, 0);

        for (int i = 0; i < sentence.size(); i++) 
        {
            check[sentence[i] - 97] = 1;
        }

        for (int i = 0; i < check.size(); i++) 
        {
            if (check[i] == 0) 
            {
                return 0;
            }
        }

        return 1;
    }
