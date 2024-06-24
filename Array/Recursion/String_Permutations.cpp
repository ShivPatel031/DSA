// String Permutations GFG

// Given a string S. The task is to find all permutations (need not be different) of a given string.

// Note: return the permutations in lexicographically increasing order.

// Example 1:

// Input:
// S = AAA
// Output: AAA AAA AAA AAA AAA AAA
// Explanation: There are total 6 permutations, as given in the output.

// Example 2:

// Input:
// S = ABSG
// Output: ABGS ABSG AGBS AGSB ASBG ASGB
// BAGS BASG BGAS BGSA BSAG BSGA GABS
// GASB GBAS GBSA GSAB GSBA SABG SAGB
// SBAG SBGA SGAB SGBA
// Explanation: There are total 24 permutations, as given in the output.

void parmutation1(string &S,vector<string> &ans,int index)
{
    if(S.size()==index)
    {
        ans.push_back(S);
        return;
    }

    for(int i = index ;i<S.size();i++)
    {
        swap(S[i],S[index]);
        parmutation1(S,ans,index+1);
        swap(S[i],S[index]);
    }
}
    
vector<string> permutation(string S)
{
    vector<string> ans;

    parmutation1(S,ans,0);
    
    sort(ans.begin(),ans.end());
    
    return ans; 
}
