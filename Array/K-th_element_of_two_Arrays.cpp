// K-th element of two Arrays GFG

// Given two sorted arrays arr1 and arr2 and an element k. The task is to find the element that would be at the kth position of the combined sorted array.

// Examples :

// Input: k = 5, arr1[] = [2, 3, 6, 7, 9], arr2[] = [1, 4, 8, 10]
// Output: 6
// Explanation: The final combined sorted array would be - 1, 2, 3, 4, 6, 7, 8, 9, 10. The 5th element of this array is 6.
// Input: k = 7, arr1[] = [100, 112, 256, 349, 770], arr2[] = [72, 86, 113, 119, 265, 445, 892]
// Output: 256
// Explanation: Combined sorted array is - 72, 86, 100, 112, 113, 119, 256, 265, 349, 445, 770, 892. 7th element of this array is 256.
// Expected Time Complexity: O(log(n) + log(m))
// Expected Auxiliary Space: O(log (n))

// Constraints:
// 1 <= k<= arr1.size()+arr2.size()
// 1 <= arr1.size(), arr2.size() <= 106
// 0 <= arr1[i], arr2[i] < 108

int kthElement(int k, vector<int>& arr1, vector<int>& arr2) 
{
    int length=0,size=arr1.size()+arr2.size();
    int ans=INT_MIN;
    int i=0,j=0;
    
    while(length!=k)
    {
        if (i < arr1.size() && (j >= arr2.size() || arr1[i] <= arr2[j])) 
        {
            ans = max(ans, arr1[i]);
            i++;
        } 
        else 
        {
            ans = max(ans, arr2[j]);
            j++;
        }           
        
        length++;
    }
    
    return ans;
}
