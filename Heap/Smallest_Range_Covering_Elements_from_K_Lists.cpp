// Smallest Range Covering Elements from K Lists leetcode 632 GFG

// You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.

// We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.

// Example 1:

// Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
// Output: [20,24]
// Explanation: 
// List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
// List 2: [0, 9, 12, 20], 20 is in range [20,24].
// List 3: [5, 18, 22, 30], 22 is in range [20,24].
  
// Example 2:

// Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
// Output: [1,1]

// Constraints:

// nums.length == k
// 1 <= k <= 3500
// 1 <= nums[i].length <= 50
// -105 <= nums[i][j] <= 105
// nums[i] is sorted in non-decreasing order.


// leetcode 
vector<int> smallestRange(vector<vector<int>>& nums) 
{ 
    priority_queue< pair< int, pair< int,int > >, vector< pair< int, pair< int,int > > > , greater< pair< int, pair< int,int > > > > q;
    vector<int> ans(2,INT_MIN);
    int min,max=INT_MIN;

    for(int i = 0 ; i  < nums.size();i++)
    {
        q.push(make_pair(nums[i][0],make_pair(i,0)));

        if(nums[i][0]>max)
        {
            max=nums[i][0];
        }
    }

    pair<int,pair<int,int>> element;
    int i,j;
    ans[1]=max;
    ans[0]=q.top().first;

    while(q.size()==nums.size())
    {
        element = q.top();
        q.pop();

        i=element.second.first;
        j=element.second.second;
        min = element.first;

        if(ans[1]-ans[0]>max-min)
        {
            ans[0]=min;
            ans[1]=max;
        }

        if(j+1<nums[i].size())
        {
            int val = nums[i][j+1];

            if(val>max)
            {
                max=val;
            }

            q.push(make_pair(val,make_pair(i,j+1)));
        }    
    }

    return ans;
}


// GFG
pair<int,int> findSmallestRange(int nums[][N], int n, int k)
{
    priority_queue< pair< int, pair< int,int > >, vector< pair< int, pair< int,int > > > , greater< pair< int, pair< int,int >>>> q;
    pair<int,int> ans;
    int min,max=INT_MIN;

    for(int i = 0 ; i  < k ; i++)
    {
        q.push(make_pair(nums[i][0],make_pair(i,0)));
        
        if(nums[i][0]>max)
        {
            max=nums[i][0];
        }
    }

    pair<int,pair<int,int>> element;
    int i,j;
    ans.second=max;
    ans.first=q.top().first;

    while(q.size()==k)
    {
        element = q.top();
        q.pop();

        i=element.second.first;
        j=element.second.second;
        min = element.first;

        if(ans.second-ans.first>max-min)
        {
            ans.first=min;
            ans.second=max;
        }

        if(j+1<n)
        {
            int val = nums[i][j+1];

            if(val>max)
            {
                max=val;
            }

            q.push(make_pair(val,make_pair(i,j+1)));
        }    
    }

    return ans;
}
