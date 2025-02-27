// Binary Number Triangle
// coding ninja


// Sample Input 1:
// 3
// Sample Output 1:
// 1
// 0 1
// 1 0 1
// Sample Input 2 :
// 4
// Sample Output 2 :
// 1
// 0 1
// 1 0 1
// 0 1 0 1
// Sample Input 3 :
// 6
// Sample Output 3 :
// 1 
// 0 1 
// 1 0 1 
// 0 1 0 1 
// 1 0 1 0 1 
// 0 1 0 1 0 1 


void nBinaryTriangle(int n) {
    char s = '1';
    for(int i = 0 ; i<n;i++){
        s = i%2 == 0 ?'1':'0';
        for(int j = 0 ; j<=i;j++){
            cout<<s<<' ';
            s = s == '1'?'0':'1';
        }
        cout<<endl;
    }
}
