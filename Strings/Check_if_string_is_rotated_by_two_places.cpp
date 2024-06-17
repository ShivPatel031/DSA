// Check if string is rotated by two places GFG

// Given two strings a and b. The task is to find if the string 'b' can be obtained by rotating (in any direction) string 'a' by exactly 2 places.

// Example 1:

// Input:
// a = amazon
// b = azonam
// Output: 
// 1
// Explanation: 
// amazon can be rotated anti-clockwise by two places, which will make it as azonam.
  
// Example 2:

// Input:
// a = geeksforgeeks
// b = geeksgeeksfor
// Output: 
// 0
// Explanation: 
// If we rotate geeksforgeeks by two place in any direction, we won't get geeksgeeksfor.

string rotateCyclically(string str){
        string ans;
        for(int i = 2;i<str.size();i++){
            ans+=str[i];
        }
        ans.push_back(str[0]);
        ans.push_back(str[1]);
        
        return ans;
        
    }
    
    string rotateAntiCyclically(string str){
        string ans;
        ans.push_back(str[str.size()-2]);
        ans.push_back(str[str.size()-1]);
        for(int i = 0;i<str.size()-2;i++){
            ans+=str[i];
        }
        return ans;
        
    }
    
    bool isRotated(string str1, string str2)
    {
        
        if(str1.size()==1){
            if(str1 != str2){
                return false;
            }
        }
        
        string s1=rotateCyclically(str1);
        
        if (s1 == str2){
            return true;
        }
        
        s1 = rotateAntiCyclically(str1);
        
        if(s1 == str2){
            return true;
        }
        
        return false;
        
    }
