// Job Sequencing Problem GFG

// Given a set of N jobs where each jobi has a deadline and profit associated with it.
// Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit associated with job if and only if the job is completed by its deadline.
// Find the number of jobs done and the maximum profit.
// Note: Jobs will be given in the form (Jobid, Deadline, Profit) associated with that Job. Deadline of the job is the time before which job needs to be completed to earn the profit.

// Example 1:

// Input:
// N = 4
// Jobs = {(1,4,20),(2,1,10),(3,1,40),(4,1,30)}
// Output:
// 2 60
// Explanation:
// Job1 and Job3 can be done with
// maximum profit of 60 (20+40).

// Example 2:

// Input:
// N = 5
// Jobs = {(1,2,100),(2,1,19),(3,2,27),
//         (4,1,25),(5,1,15)}
// Output:
// 2 127
// Explanation:
// 2 jobs can be done with
// maximum profit of 127 (100+27).

// Your Task :
// You don't need to read input or print anything. Your task is to complete the function JobScheduling() which takes an integer N and an array of Jobs(Job id, Deadline, Profit) as input and returns the count of jobs and maximum profit as a list or vector of 2 elements.

// Expected Time Complexity: O(NlogN)
// Expected Auxilliary Space: O(N)

// Constraints:
// 1 <= N <= 105
// 1 <= Deadline <= N
// 1 <= Profit <= 500


// optimize way
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

bool camp(Job a,Job b)
{
    return a.profit>b.profit;
}

int findSlot(int num,vector<int> &parent)
{
    if(num==parent[num]) return num;
    
    return parent[num] = findSlot(parent[num],parent);
}

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr,arr+n,camp);
        
        vector<int> ans(2,0);
        int maxdeadline = 0;
        for(int i=0;i<n;i++) maxdeadline=max(maxdeadline,arr[i].dead);
        
        vector<bool> timer(maxdeadline+1,0);
        vector<int> parent(maxdeadline+1,0);
        
        for(int i = 0 ; i<maxdeadline+1;i++)
        {
            parent[i]=i;
        }
        
        for(int i = 0 ; i < n ; i++)
        {
            int slot = findSlot(arr[i].dead,parent);
            
            if(slot)
            {
                ans[0]++;
                ans[1]+=arr[i].profit;
                parent[slot]=parent[slot-1];
            }
        }
        
        return ans;
    } 
};


// other but n^2 time complexity
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

bool camp(Job a,Job b)
{
    return a.profit>b.profit;
}

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr,arr+n,camp);
        
        vector<int> ans(2,0);
        int maxdeadline = 0;
        for(int i=0;i<n;i++) maxdeadline=max(maxdeadline,arr[i].dead);
        
        vector<bool> timer(maxdeadline+1,0);
        
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = arr[i].dead ;j>0;j--)
            {
                if(!timer[j])
                {
                    timer[j]=1;
                    ans[0]++;
                    ans[1]+=arr[i].profit;
                    break;
                }
            }
        }
        
        return ans;
    } 
};
