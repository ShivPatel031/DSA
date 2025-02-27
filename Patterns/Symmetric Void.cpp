// Symmetric Void
// coding ninja

// Sample Input 1:
// 3
// Sample Output 1:
// * * * * * * 
// * *     * * 
// *         * 
// *         * 
// * *     * * 
// * * * * * * 
// Sample Input 2 :
// 1
// Sample Output 2 :
// * * 
// * * 

// what i thought

void symmetry(int n) {
    for(int i = 0 ; i<n;i++){
        for(int j =i;j<n;j++){
            cout<<"* ";
        }
        for(int j=0;j<i;j++){
            cout<<"  ";
        }
        for(int j=i;j<n;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
    for(int i = 0 ; i<n;i++){
        for(int j =i;j>=0;j--){
            cout<<"* ";
        }
        for(int j=0;j<n-i-1;j++){
            cout<<"  ";
        }
        for(int j =i;j>=0;j--){
            cout<<"* ";
        }
        cout<<endl;
    }
}


// with two loop
/*
    Time Complexity : O( N*N )
    Space complexity: O( 1 )

    Where N is the given input integer.
*/

void symmetry(int n) {

    // Update n with 2*n

    n = 2*n ;

    // For loop 'row' in range 0 to N-1.
    for(int row = 0; row < n; row++) {

        // For loop 'col' in range 0 to N-1.
        for(int col = 0; col < n; col++) {

            // Condition for first half of the rows.
            if(row < n/2 && (col < (n/2 - row) || col >= (n/2 + row))) {
                cout << '*' ;
            }

            // Condition for the second half of the rows.
            else if(row >= n/2 && (col <= (row-n/2) || col >= (n-row+n/2-1))) {
                cout << '*' ;
            }

            else {
                cout << ' ';
            }

            cout << ' ';
        }

        // End the current row of the pattern.
        cout << '\n';
    }
}
