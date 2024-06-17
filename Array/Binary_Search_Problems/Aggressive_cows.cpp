// Aggressive Cows

// You are given an array consisting of n integers which denote the position of a stall. You are also given an integer k which denotes the number of aggressive cows. You are given the task of assigning stalls to k cows such that the minimum distance between any two of them is the maximum possible.
// The first line of input contains two space-separated integers n and k.
// The second line contains n space-separated integers denoting the position of the stalls.

// Example 1:

// Input:
// n=5 
// k=3
// stalls = [1 2 4 8 9]
// Output:
// 3
// Explanation:
// The first cow can be placed at stalls[0], 
// the second cow can be placed at stalls[2] and 
// the third cow can be placed at stalls[3]. 
// The minimum distance between cows, in this case, is 3, 
// which also is the largest among all possible ways.
// Example 2:

// Input:
// n=5 
// k=3
// stalls = [10 1 2 7 5]
// Output:
// 4
// Explanation:
// The first cow can be placed at stalls[0],
// the second cow can be placed at stalls[1] and
// the third cow can be placed at stalls[4].
// The minimum distance between cows, in this case, is 4,
// which also is the largest among all possible ways.

int solve(int n, int k, vector<int> &stalls) {
    
        
        sort(stalls.begin(),stalls.end());
        
        int start = 1 , end=stalls[n-1],ans;
        
        while (start <= end){
            
            int mid = start + (end - start)/2,count=1;
            
            // int i=0,j=1;
            
            // while(j<=n-1){
            //     if(stalls[j]-stalls[i] >= mid){
            //         count++;
            //         i=j;
            //     }
            //     j++;
            // }

            int pos = stalls[0];

            for (int i=1;i<n;i++){
                if(pos + mid <= stalls[i]){
                    count++;
                    pos=stalls[i];
                }
            }
            
            if(count < k){
                end=mid-1;
            }else{
                start=mid+1;
                ans=mid;
            }
        }
        
        return ans;
    }
