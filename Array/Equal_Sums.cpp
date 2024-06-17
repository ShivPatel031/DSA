// Equal Sums

// Given an array A of positive integers, find the smallest non-negative integer (i.e. greater than or equal to zero) that can be placed between any two elements of the array such that the sum of elements in the subarray occurring before it,  is equal to the sum of elements occurring in the subarray after it, with the newly placed integer included in either of the two subarrays.

// Example 1:

// Input : Arr[] = {3, 2, 1, 5, 7, 8}
// Output : 4 5 1
// Explanation:
// The smallest possible number that we can 
// insert is 4, at position 5 (i.e. between 
// 5 and 7) as part of first subarray so that 
// the sum of the two subarrays becomes 
// equal as, 3+2+1+5+4=15 and 7+8=15.

// Example 2:

// Input : Arr[] = {9, 5, 1, 2, 0}
// Output : 1 2 2
// Explanation:
// The smallest possible number that we can 
// insert is 1,at position 2 (i.e. between 9 
// and 5) as part of second subarray in 
// order to get an equal sum of 9.

vector<int> EqualSum(int a[], int n)
    {
        vector<int> ans;
        
        int start = 0 , end = n-1,sum1=0,sum2=0;
        int dif,position,sa;
        
        if(n==1){
            
         dif = a[0];
         position=2;
         sa=2;
         
        }
        else
        {
            
        sum1+=a[start];
        sum2+=a[end];
            
        
        while (start < end){
            
            if(sum1<sum2){
                start++;
                if(start != end){
                    sum1+=a[start];
                }
            }else{
                end--;
                if(start != end){
                    sum2+=a[end];
                }
            }
        }
        
        if(sum1<sum2){
            
            dif=sum2-sum1;
            position=start+1;
            sa=1;
        }
        else{
            
            dif=sum1-sum2;
            position=end+2;
            
            if(sum1==sum2){
                sa=1;
            }else{
                sa=2;
            }
        }
        
        }
        
        
        
        ans.push_back(dif);
        ans.push_back(position);
        ans.push_back(sa);
        
        return ans;
    }
