// Reverse Star Triangle
// coding  ninja

// Sample Input 1:
// 3
// Sample Output 1:
// *****
//  ***
//   *

void nStarTriangle(int n) {
    for(int i = n-1;i>=0;i--){
        for(int k = n-1 ; k>i;k--){
            cout<<" ";
        }
        for(int j = 0;j<2*i+1;j++){
            cout<<"*";
        }
        
        cout<<endl;
    }
}
