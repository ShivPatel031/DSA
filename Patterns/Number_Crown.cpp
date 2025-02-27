// Number Crown
// coding ninja

// Sample Input 1:
// 3
// Sample Output 1:
// 1         1
// 1 2     2 1
// 1 2 3 3 2 1
// Sample Input 2 :
// 4
// Sample Output 2 :
// 1             1
// 1 2         2 1
// 1 2 3     3 2 1
// 1 2 3 4 4 3 2 1
// Sample Input 3 :
// 7
// Sample Output 3 :
// 1                         1
// 1 2                     2 1
// 1 2 3                 3 2 1
// 1 2 3 4             4 3 2 1
// 1 2 3 4 5         5 4 3 2 1
// 1 2 3 4 5 6     6 5 4 3 2 1
// 1 2 3 4 5 6 7 7 6 5 4 3 2 1 

// what i first thought
void numberCrown(int n) {
  
    for(int i = 0;i<n;i++){
      
        int l = 1 , r=n;
      
        for(int j=0;j<n*2;j++){
          
            if(j>i && j < 2*n-(i+1)){
              
                if(j<n){
                    l++;
                }
                else{
                    r--;
                }
              
                cout<<"  ";}
            else{
                 if(j<n){
                    cout<<l<<" ";
                    l++;
                }else{
                    cout<<r<<" ";
                    r--;
                }
            }

           
        }
        cout<<endl;
    }

}


// othere ways
void numberCrown(int n) {
    
    // Initialise 'num'.
    int num = 1, gap = (n - 1) * 2;
    for (int i = 0; i < n; i++) {
        int currentNumber = 1;
        int cur = 0;
        for (int j = 1; j <= num; j++) {
            cout << (currentNumber);
            cout << " ";
            currentNumber++;
        }
        for (int j = 1; j <= gap; j++) {
            cout << " ";            
            cout << " ";
        }
        currentNumber--;
        for (int j = 1; j <= num; j++) {
            cout << currentNumber;
            cout << " ";
            currentNumber--;
        }
        cout << '\n';
        num++;
        gap -= 2;
    }
}

// best solution
void numberCrown(int n) {
    int space =2* (n-1);
for (int i=1;i<=n;i++) {

  for (int j=1;j<=i;j++) {
    cout<< j<<" ";
  }
for (int j=1;j<=space;j++){
  cout<< " "<<" ";
}
for (int j=i;j>=1;j--) {
  cout<< j<<" ";
}
cout<< endl;
space-=2;
}
}
