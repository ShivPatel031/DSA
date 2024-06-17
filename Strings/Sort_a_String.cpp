// Sort a String

// Given a string consisting of lowercase letters, arrange all its letters in ascending order. 

// Example 1:

// Input:
// S = "edcab"
// Output: "abcde"
// Explanation: characters are in ascending
// order in "abcde".
  
// Example 2:

// Input:
// S = "xzy"
// Output: "xyz"
// Explanation: characters are in ascending
// order in "xyz".

string sort(string sentence){
    vector<int> check(26, 0);

    for (int i = 0; i < sentence.size(); i++) 
    {
        check[sentence[i] - 97]++;
    }
    
    sentence="";
    
    for(int i = 0 ; i < check.size() ; i++){
        
        while(check[i]){
            sentence+=i+97;
            check[i]--;
        }
        
    }
    
    return sentence;
}
