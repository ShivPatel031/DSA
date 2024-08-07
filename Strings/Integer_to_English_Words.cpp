// Integer to English Words leetcode 273

// Convert a non-negative integer num to its English words representation.

// Example 1:

// Input: num = 123
// Output: "One Hundred Twenty Three"

// Example 2:

// Input: num = 12345
// Output: "Twelve Thousand Three Hundred Forty Five"

// Example 3:

// Input: num = 1234567
// Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
 
// Constraints:

// 0 <= num <= 231 - 1

// other way recursion
vector<string> belowTen = {"","One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
vector<string> belowTwenty = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
vector<string> belowHundred = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
string numberToWords(int num) {
    if(num == 0)
       return "Zero";
    return find(num);
}

string find(int num)
{
    string result = "";
    if(num<10)
        result = belowTen[num];
    else
        if(num<20)
            result = belowTwenty[num-10];
    else
        if(num<100)
            result = belowHundred[num/10] + " " + find(num%10);
    else
        if(num<1000)
            result = find(num/100) + " Hundred " + find(num%100);
    else
        if(num<1000000)
            result = find(num/1000) + " Thousand " + find(num%1000);
    else
        if(num<1000000000)
            result = find(num/1000000) + " Million " + find(num%1000000);
    else
        result = find(num/1000000000) + " Billion " + find(num%1000000000);
    int size = result.length();
    if(size>0 && result[size-1]==' ')
        result = result.substr(0, size-1);
    return result;
}

// what i first thought
string numberToWords(int num) 
{
    if(num==0) return "Zero"; 

    map<int,string> itos;
    itos[1]="One";
    itos[2]="Two";
    itos[3]="Three";
    itos[4]="Four";
    itos[5]="Five";
    itos[6]="Six";
    itos[7]="Seven";
    itos[8]="Eight";
    itos[9]="Nine";
    itos[10]="Ten";
    itos[11]="Eleven";
    itos[12]="Twelve";
    itos[13]="Thirteen";
    itos[15]="Fifteen";
    itos[18]="Eighteen";
    itos[20]="Twenty";
    itos[30]="Thirty";
    itos[40]="Forty";
    itos[50]="Fifty";
    itos[60]="Sixty";
    itos[70]="Seventy";
    itos[80]="Eighty";
    itos[90]="Ninety";

    vector<int> tempans;

    while(num)
    {
        tempans.push_back(num%1000);
        num/=1000;
    }

    string ans="";

    int count=tempans.size();

    for(int i=tempans.size()-1; i>=0; i--)
    {
        bool flag=1;
        int n = tempans[i];

        if(!n) flag=0;

        if(n>=100)
        {
            int temp = n/100;
            n%=100;
            ans+=itos[temp]+" Hundred ";
        }

        if(n>=20)
        {
            int temp = n/10;
            n%=10;
            temp*=10;
            ans+=itos[temp]+' ';
            if(n)   ans+=itos[n]+' ';
        }
        else if(n<=19 && n>=10)
        {
            if(n==19 or n==17 or n==16 or n==14)
            {
                int temp = n%10;
                ans+=itos[temp]+"teen ";
            }
            else
            {
                ans+=itos[n]+' ';
            }
        }
        else if(n)
        {

            ans+=itos[n]+' ';
        }
        if(flag && count==4) ans+="Billion ";
        if(flag && count==2) ans+="Thousand ";
        if(flag && count==3) ans+="Million ";

        count--;
    } 
    ans.pop_back();
    return ans;   
}
