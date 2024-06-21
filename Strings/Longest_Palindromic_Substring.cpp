// Longest Palindromic Substring leetcode 5

// Given a string s, return the longest palindromic substring in s.

// Example 1:

// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.
  
// Example 2:

// Input: s = "cbbd"
// Output: "bb"

string longestPalindrome(string s) {

        int m=0,l=0,r=0;
        int length=0,index=0;

        while(m<s.size())
        {
            if(l>=0 && r<s.size() && s[l]==s[r])
            {
                if(length<(r-l+1))
                {
                    length=r-l+1;
                    index=l;
                } 
                l--;
                r++; 
            }
            else
            {
                m++;
                l=m;
                r=m;
            }
        }

        m=0;
        l=0;
        r=m+1;

        while(m<s.size())
        {
            if(l>=0 && r<s.size() && s[l]==s[r])
            {
                if(length<(r-l+1))
                {
                    length=r-l+1;
                    index=l;
                } 
                l--;
                r++; 
            }
            else
            {
                m++;
                l=m;
                r=m+1;
            }
        }

        string ans="";

        for(int i = index;i<index+length;i++)
        {
            ans+=s[i];
        }

        return ans;
          
    }


// too bad thought
// string longestPalindrome(string s) {

//         int start = 0 , index = 0 ,length=0;
//         string str1,str2;
//         vector<int> lps;
//         int first,second;

//         while(start<s.size())
//         {

            
//             str1="";
//             str2="";
//             for(int i = start;i<s.size();i++)
//             {
//                 str1+=s[i];
//             }

//             if(str1.size()<length){
//                 break;
//             }
            
//             str2=str1;
//             reverse(str2.begin(),str2.end());

//             str1=str1+'$'+str2;

//             first=0,second=1;

//             lps.resize(str1.size());

//             while(second<str1.size())
//             {
//                 if(str1[second]==str1[first])
//                 {
//                     lps[second]=first+1;
//                     first++;
//                     second++;
//                 }
//                 else
//                 {
//                     if(first==0)
//                     {   
//                         lps[second]=0;
//                         second++;
//                     }
//                     else
//                     {
//                         first=lps[first-1];
//                     }

//                 }
//             }
                

//             if(length<lps[lps.size()-1])
//             {
//                 length=lps[lps.size()-1];
//                 index=start;
//             }

//             start++;


//         }

//         string ans;

//         for(int i=index;i<index+length;i++)
//         {
//             ans+=s[i];
//         }

//         return ans;
        
//     }
