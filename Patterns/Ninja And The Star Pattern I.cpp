// Ninja And The Star Pattern I
// coding ninja

// Sample Input 1:
// 3
// Sample Output 1:
// ***
// * *
// ***
// Sample Input 2 :
// 5
// Sample Output 2 :
// *****
// *   *
// *   *
// *   *
// *****
// Sample Input 3 :
// 8
// Sample Output 3 :
// ********
// *      *
// *      *
// *      *
// *      *
// *      *
// *      *
// ********

// what i though
void getStarPattern(int n) {
    for(int  i = 0 ; i<n;i++){
        for(int j = 0 ; j<n;j++){
            if(i>0 && j>0 && j<n-1 && i<n-1) cout<<"  ";
            else cout<<"*";
        }
        cout<<endl;
    }
}
