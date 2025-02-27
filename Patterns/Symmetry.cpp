// Symmetry
// coding ninja

// Sample Input 1:
// 3
// Sample Output 1:
// *         *
// * *     * *
// * * * * * *
// * *     * *
// *         *
// Sample Input 2 :
// 1
// Sample Output 2 :
// *


// What i thought
void symmetry(int n) {
    for(int i = 0 ; i< n;i++){
        for(int j = 0 ; j<=i;j++){
            cout<<"* ";
        }
        for(int j=0;j<2*(n-i-1);j++){
            cout<<"  ";
        }

        for(int j = 0 ; j<=i;j++){
            cout<<"* ";
        }
        cout<<endl;
        
    }
    for(int i = 0 ; i< n-1;i++){
        for(int j = n-1 ; j>i;j--){
            cout<<"* ";
        }
        for(int j=0;j<=2*(i+1);j++){
            cout<<"  ";
        }

        for(int j = n-1 ; j>i;j--){
            cout<<"* ";
        }
        cout<<endl;
        
    }
}
