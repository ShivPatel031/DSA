//  Ninja And The Number Pattern
// coding ninja

// Sample Input 1:
// 3
// Sample Output 1:
// 33333
// 32223
// 32123
// 32223
// 33333
// Sample Input 2 :
// 5
// Sample Output 2 :
// 555555555
// 544444445
// 543333345
// 543222325
// 543212345
// 543222325
// 543333345
// 544444445
// 555555555
// Sample Input 3 :
// 4
// Sample Output 3 :
// 4444444
// 4333334
// 4322234
// 4321234
// 4322234
// 4333334
// 4444444

// solution
void getNumberPattern(int n) {

    // Write your code here.

    for(int i=n;i>0;i--)

    {

        for(int j=n;j>0;j--)

        {

            int val=max(i,j);

            cout<<val;

        }

        for(int k=2;k<=n;k++)

        {

            int val=max(k,i);

            cout<<val;

        }

        cout<<"\n";

    }

    for(int i=2;i<=n;i++)

    {

        for(int j=n;j>0;j--)

        {

            int val=max(i,j);

            cout<<val;

        }

        for(int k=2;k<=n;k++)

        {

            int val=max(k,i);

            cout<<val;

        }

        cout<<"\n";

    }

}
