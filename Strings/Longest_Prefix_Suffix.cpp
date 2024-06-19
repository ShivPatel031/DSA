// Longest Prefix Suffix GFG

// Given a string of characters, find the length of the longest proper prefix which is also a proper suffix.

// NOTE: Prefix and suffix can be overlapping but they should not be equal to the entire string.

// Example 1:

// Input: s = "abab"
// Output: 2
// Explanation: "ab" is the longest proper 
// prefix and suffix. 

// Example 2:

// Input: s = "aaaa"
// Output: 3
// Explanation: "aaa" is the longest proper 
// prefix and suffix. 


int lps(string s) {
	 
	    vector<int> ans(s.size(),0);
	    
	    int pre = 0,sub=1;
	    
	    while(sub<s.size()){
	        if(s[pre]==s[sub]){
	            ans[sub]=pre+1;
	            pre++;
	            sub++;
	        }
	        else{
	            if(pre==0){
	                ans[sub]=0;
	                sub++;
	            }
	            else{
	                 pre=ans[pre-1];
	            }
	                
	            
	        }
	    }
	    
	    return ans[s.size()-1];
	    
	}
