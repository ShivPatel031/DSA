// Kth Distinct String in an Array leetcode 2053

// A distinct string is a string that is present only once in an array.
// Given an array of strings arr, and an integer k, return the kth distinct string present in arr. If there are fewer than k distinct strings, return an empty string "".
// Note that the strings are considered in the order in which they appear in the array.

// Example 1:

// Input: arr = ["d","b","c","b","c","a"], k = 2
// Output: "a"
// Explanation:
// The only distinct strings in arr are "d" and "a".
// "d" appears 1st, so it is the 1st distinct string.
// "a" appears 2nd, so it is the 2nd distinct string.
// Since k == 2, "a" is returned. 

// Example 2:

// Input: arr = ["aaa","aa","a"], k = 1
// Output: "aaa"
// Explanation:
// All strings in arr are distinct, so the 1st string "aaa" is returned.

// Example 3:

// Input: arr = ["a","b","a"], k = 3
// Output: ""
// Explanation:
// The only distinct string is "b". Since there are fewer than 3 distinct strings, we return an empty string "".
 
// Constraints:

// 1 <= k <= arr.length <= 1000
// 1 <= arr[i].length <= 5
// arr[i] consists of lowercase English letters.


// optimize way
string kthDistinct(vector<string>& arr, int k) 
{
    unordered_map<string, int> mp;
    string ans = "";

    for(string x : arr) {
        mp[x]++;
    }

    for(auto& s : arr) {
        if(mp[s] == 1 && --k == 0)
            return s;
    }

    return "";
}

// what i first thought
bool camp(pair<string,int> a, pair<string,int> b)
{
    return a.second<b.second;
}

string kthDistinct(vector<string>& arr, int k) 
{
    unordered_map<string,pair<int,int>> m;

    for(int i = 0 ; i<arr.size();i++)
    {
        if(m.count(arr[i]))
        {
            m[arr[i]].first=-1;
            m[arr[i]].second=0;
        }
        else
        {
            m[arr[i]].first++;
            m[arr[i]].second=i;
        }
    }

    string ans;
    vector<pair<string,int>> temp;

    for(auto i : m)
    {
        if(i.second.first==1)
        {
            temp.push_back({i.first,i.second.second});
        }
    }
    sort(temp.begin(),temp.end(),camp);

    return temp.size()<k?"":temp[k-1].first;  
}
