// Alpha Hill
// coding ninja

// Sample Input 1:
// 3
// Sample Output 1:
//     A
//   A B A
// A B C B A
// Sample Input 2 :
// 1
// Sample Output 2 :
// A

// what i first thought
void alphaHill(int n) {
    for(int i = 0 ; i<n;i++){
        char a='A';
        int track = 0;
        for(int j =i;j<n-1;j++){
            cout<<"  ";
            track++;
        }
        for(int k =0;k<2*i+1;k++){
            cout<<a<<" ";
            track++;
            if(track<n){
                a++;
            }
            else{
                a--;
            }
            

        }
        cout<<endl;
    }
}

// other way
void alphaHill(int n) {
     for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            cout<<" ";
        }
        for(int k=0;k<i;k++)
        {
            cout<<char('A'+k)<<" ";
        }
        for(int l=i;l>=0;l--)
        {
            cout<<char('A'+l)<<" ";
        }
         for(int j=0;j<n-i-1;j++)
        {
            cout<<" ";
        }
        cout<<endl;
    }
}
