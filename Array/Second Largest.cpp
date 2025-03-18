//GFG

int print2largest(int arr[], int n) {
	    
	    int temp=INT_MIN,ans=INT_MIN;
	    
	    for (int i=0;i<n;i++){
	        if (temp < arr[i]){
	            temp=arr[i];
	        }
	        
	    }
	        
	    for (int i = 0; i<n;i++){
	        if (ans <arr[i] && arr[i] != temp){
	            ans=arr[i];
	        }
	    }
	    
	    if(ans == INT_MIN){
	        return -1;
	    }
	    
	    return ans;
	    
}

// using only one loop
int getSecondLargest(vector<int> &arr) {
        int max=INT_MIN;
        int smax = max+1;
        for(int i : arr){
            if(max<i){
                smax=max;
                max=i;
            }
            
            if(smax<i and max!=i){
                smax=i;
            }
            
        }
        
        return smax==INT_MIN?-1:smax;
    }
