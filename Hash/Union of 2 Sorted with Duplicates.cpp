// Union of 2 Sorted with Duplicates
// GFG

// using set/orderd_hash
vector<int> findUnion(vector<int> &a, vector<int> &b) {
        vector<int> ans;
        
        set<int> s; 
        
        for(int i : a){
            s.insert(i);
        }
        
        for(int i : b){
            s.insert(i);
        }
        
        for(auto i : s){
            ans.push_back(i);
        }
        
        return ans;
    }

// without set
vector<int> findUnion(vector<int> &a, vector<int> &b) {
        vector<int> ans;
        
        int i=0,j=0;
        
        while(i<a.size() && j<b.size()){
            if(a[i]==b[j]){
                ans.push_back(a[i]);
                do{
                    i++;
                }
                while(a[i-1]==a[i]);
                do{
                    j++;
                }
                while(b[j-1]==b[j]);
            }
            else if(a[i]>b[j]){
                ans.push_back(b[j]);
                do{
                    j++;
                }
                while(b[j-1]==b[j]);
            }
            else
            {
                ans.push_back(a[i]);
                do{
                    i++;
                }
                while(a[i-1]==a[i]);
            }
        }
        
        while(i<a.size()){
            ans.push_back(a[i]);
             do{
                    i++;
                }
                while(a[i-1]==a[i]);
        }
        
        while(j<b.size()){
            ans.push_back(b[j]);
             do{
                    j++;
                }
                while(b[j-1]==b[j]);
        }
        
        return ans;
    }
