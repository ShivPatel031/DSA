// Majority Element leetcode 169

// More optimize way
int majorityElement(vector<int>& nums) 
{
    unordered_map<int, int> hash;
    int res = 0;
    int majority = 0;

    for (int n : nums) {
        hash[n] = 1 + hash[n];
        if (hash[n] > majority) {
            res = n;
            majority = hash[n];
        }
    }

    return res;        
}

// what I thought 
int majorityElement(vector<int>& nums) 
{    unordered_map<int,int> m;

    for(int i : nums)
    {
        m[i]++;
    }

    int frequency=0,ans;   

    for(auto i : m)
    {
       if(i.second > frequency)
       {
            frequency=i.second;
            ans=i.first;
       }  
    }

    return ans;
}

