//  Alpha-Triangle
// coding ninja

// Sample Input 1:
// 3
// Sample Output 1:
// C
// C B 
// C B A
// Sample Input 2 :
// 1
// Sample Output 2 :
// A

// what i though
void alphaTriangle(int n) {
    for(int i = 0; i<n;i++){
        char a = 'A'+(n-1);
        for(int j = 0;j<=i;j++){
            cout<<a<<' ';
            a--;
        }
        cout<<endl;
    }
}
