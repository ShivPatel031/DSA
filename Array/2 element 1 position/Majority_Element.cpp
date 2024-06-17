// Majority Element GFG

// Given an array A of N elements. Find the majority element in the array. A majority element in an array A of size N is an element that appears strictly more than N/2 times in the array.
 

// Example 1:

// Input:
// N = 3 
// A[] = {1,2,3} 
// Output:
// -1
// Explanation:
// Since, each element in 
// {1,2,3} appears only once so there 
// is no majority element.

// Example 2:

// Input:
// N = 5 
// A[] = {3,1,3,3,2} 
// Output:
// 3
// Explanation:
// Since, 3 is present more
// than N/2 times, so it is 
// the majority element.



int majorityElement(int nums[], int size)
{
        int ans,count=0;

        for(int i = 0; i < size ; i++){

            if(count == 0){
              
                count++;
                ans = nums[i];
            }else{
              
                if(nums[i]==ans)
                {
                    count++;
                }
                else
                {
                    count--;
                }
            }
            
        }
  
        count=0;
  
        for(int i = 0 ;i<size;i++)
        {
            if(ans==nums[i])
            {
                count++;
            }
        }
        
        if(count>size/2)
        {
            return ans;
        }
        else
        {
            return -1;
        }
    }


// leetCode

// Majority Element 169

int majorityElement(vector<int>& nums) {

        int ans,count=0;

        for(int i = 0; i < nums.size() ; i++){

            if(count == 0){
                count++;
                ans = nums[i];
            }else{
                if(nums[i]==ans){
                    count++;
                }
                else{
                    count--;
                }
            }
            
        }

        return ans;
    }
