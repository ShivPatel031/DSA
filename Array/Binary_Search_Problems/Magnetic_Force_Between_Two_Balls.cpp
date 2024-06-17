// Magnetic Force Between Two Balls

// In the universe Earth C-137, Rick discovered a special form of magnetic force between two balls if they are put in his new invented basket. Rick has n empty baskets, the ith basket is at position[i], Morty has m balls and needs to distribute the balls into the baskets such that the minimum magnetic force between any two balls is maximum.
// Rick stated that magnetic force between two different balls at positions x and y is |x - y|.
// Given the integer array position and the integer m. Return the required force.

// Example 1:
// Input: position = [1,2,3,4,7], m = 3
// Output: 3
// Explanation: Distributing the 3 balls into baskets 1, 4 and 7 will make the magnetic force between ball pairs [3, 3, 6]. The minimum magnetic force is 3. We cannot achieve a larger minimum magnetic force than 3.

  
// Example 2:

// Input: position = [5,4,3,2,1,1000000000], m = 2
// Output: 999999999
// Explanation: We can use baskets 1 and 1000000000.

  
int maxDistance(vector<int>& stalls, int k) {
        sort(stalls.begin(),stalls.end());

        int n = stalls.size();
        
        int start = 1 , end=stalls[n-1],ans;
        
        while (start <= end){
            
            int mid = start + (end - start)/2,count=1;
            
          // int i=0,j=1;
            
          //   while(j<=n-1){
          //       if(stalls[j]-stalls[i] >= mid){
          //           count++;
          //           i=j;
          //       }
          //       j++;
          //   }

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
