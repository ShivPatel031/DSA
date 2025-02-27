// start triangle
// codeing inja

// Sample Input 1:
// 3
// Sample Output 1:
//   *
//  ***
// *****

// whta i thought

void nStarTriangle(int n) {
    for(int i = 0 ; i<n;i++){
        for(int j = i;j<n-1;j++){
            cout<<" ";
        }
        for(int k=0;k<2*i+1;k++ ){
            cout<<"*";
        }
        cout<<endl;
    }
}
