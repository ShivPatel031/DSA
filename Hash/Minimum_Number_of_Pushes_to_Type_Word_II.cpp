// Minimum Number of Pushes to Type Word II leetcode 3016

// You are given a string word containing lowercase English letters.
// Telephone keypads have keys mapped with distinct collections of lowercase English letters, which can be used to form words by pushing them. For example, the key 2 is mapped with ["a","b","c"], we need to push the key one time to type "a", two times to type "b", and three times to type "c" .
// It is allowed to remap the keys numbered 2 to 9 to distinct collections of letters. The keys can be remapped to any amount of letters, but each letter must be mapped to exactly one key. You need to find the minimum number of times the keys will be pushed to type the string word.
// Return the minimum number of pushes needed to type word after remapping the keys.
// An example mapping of letters to keys on a telephone keypad is given below. Note that 1, *, #, and 0 do not map to any letters.

// Example 1:

// Input: word = "abcde"
// Output: 5
// Explanation: The remapped keypad given in the image provides the minimum cost.
// "a" -> one push on key 2
// "b" -> one push on key 3
// "c" -> one push on key 4
// "d" -> one push on key 5
// "e" -> one push on key 6
// Total cost is 1 + 1 + 1 + 1 + 1 = 5.
// It can be shown that no other mapping can provide a lower cost.

// Example 2:

// Input: word = "xyzxyzxyzxyz"
// Output: 12
// Explanation: The remapped keypad given in the image provides the minimum cost.
// "x" -> one push on key 2
// "y" -> one push on key 3
// "z" -> one push on key 4
// Total cost is 1 * 4 + 1 * 4 + 1 * 4 = 12
// It can be shown that no other mapping can provide a lower cost.
// Note that the key 9 is not mapped to any letter: it is not necessary to map letters to every key, but to map all the letters.

// Example 3:

// Input: word = "aabbccddeeffgghhiiiiii"
// Output: 24
// Explanation: The remapped keypad given in the image provides the minimum cost.
// "a" -> one push on key 2
// "b" -> one push on key 3
// "c" -> one push on key 4
// "d" -> one push on key 5
// "e" -> one push on key 6
// "f" -> one push on key 7
// "g" -> one push on key 8
// "h" -> two pushes on key 9
// "i" -> one push on key 9
// Total cost is 1 * 2 + 1 * 2 + 1 * 2 + 1 * 2 + 1 * 2 + 1 * 2 + 1 * 2 + 2 * 2 + 6 * 1 = 24.
// It can be shown that no other mapping can provide a lower cost.
 
// Constraints:

// 1 <= word.length <= 105
// word consists of lowercase English letters.


// optimize way

// way 1
int minimumPushes(string word) 
{
    vector<int>store(26,0);
    for(auto i : word)store[i-'a']++;
    sort(store.begin(),store.end(),greater<int>());
    int sum1=accumulate(store.begin(),store.begin()+8,0);
    int sum2=accumulate(store.begin()+8,store.begin()+16,0)*2;
    int sum3=accumulate(store.begin()+16,store.begin()+24,0)*3;
    int sum4=accumulate(store.begin()+24,store.end(),0)*4;
    
    return sum1+sum2+sum3+sum4;
}

// way 2
int minimumPushes(string word) 
{
    vector<int> cnt(26);
    for(char &c : word) 
    {
        cnt[c-'a']++;
    }
  
    sort(cnt.begin(), cnt.end(), greater<int>());
    int ans = 0;
  
    for(int i = 0; i < 26; ++i) 
    {
        ans += cnt[i]*(i/8+1);
    }
  
    return ans;
}

// what i first thougt
bool camp(pair<char,int> a,pair<char,int> b)
{
    return a.second > b.second;
}
int minimumPushes(string word) 
{
    unordered_map<char,int> alph;

    for(char i : word)
    {
        alph[i]++;
    }

    vector<pair<char,int>> temp;

    for(auto i : alph)
    {
        temp.push_back({i.first,i.second});
    }

    sort(temp.begin(),temp.end(),camp);

    int loop = temp.size();
    int ans=0,count=0,mul=1;
    int i=0;
    
    while(loop--)
    {
        ans+=(mul*temp[i++].second);
        count++;
        if(count==8)
        {
            mul++;
            count=0;
        }

    }
    return ans;
}
