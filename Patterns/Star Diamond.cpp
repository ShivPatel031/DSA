 // Star Diamond
// coding ninja

// Sample Input 1:
// 3
// Sample Output 1:
//   *
//  ***
// *****
// *****
//  ***
//   *  


void nStarDiamond(int n) {
    for(int i = 0 ; i<n ; i++){
        for(int j = n-i-1 ; j>0;j--){
            cout<<" ";
        }
        for(int k = 0 ; k<2*i+1 ; k++){
            cout<<"*";
        }
        cout<<endl;
    }
    for(int i = 0 ; i<n;i++){
        for(int k = 0;k<i;k++){
            cout<<" ";
        }
        for(int j = 2*i;j<2*n-1;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}
