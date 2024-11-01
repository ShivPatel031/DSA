// Length of last word leetcode 58

// what i thougt first
int lengthOfLastWord(string s) 
{
    string ans = "";
    bool check=false;

    for(int i=s.size()-1;i>=0;i--)
    {
        if(s[i]==' ' && !check) continue;
        else if(s[i]!=' ')
        {
            if(!check)
            {
                check=true;
            }
            ans.push_back(s[i]);
        }
        else
        {
            break;
        }
    } 

    return ans.size();   
}

//  othere way
int lengthOfLastWord(string s) 
{
    int end = s.length() - 1;

    while (end >= 0 && s[end] == ' ') {
        end--;
    }

    int start = end;
    while (start >= 0 && s[start] != ' ') {
        start--;
    }

    return end - start;        
}
