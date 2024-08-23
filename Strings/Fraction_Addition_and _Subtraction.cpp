// Fraction Addition and Subtraction leetcode 592

// Given a string expression representing an expression of fraction addition and subtraction, return the calculation result in string format.
// The final result should be an irreducible fraction. If your final result is an integer, change it to the format of a fraction that has a denominator 1. So in this case, 2 should be converted to 2/1.

// Example 1:

// Input: expression = "-1/2+1/2"
// Output: "0/1"

// Example 2:

// Input: expression = "-1/2+1/2+1/3"
// Output: "1/3"

// Example 3:

// Input: expression = "1/3-1/2"
// Output: "-1/6" 

// Constraints:

// The input string only contains '0' to '9', '/', '+' and '-'. So does the output.
// Each fraction (input and output) has the format ±numerator/denominator. If the first input fraction or the output is positive, then '+' will be omitted.
// The input only contains valid irreducible fractions, where the numerator and denominator of each fraction will always be in the range [1, 10]. If the denominator is 1, it means this fraction is actually an integer in a fraction format defined above.
// The number of given fractions will be in the range [1, 10].
// The numerator and denominator of the final result are guaranteed to be valid and in the range of 32-bit int.

// what i first tought

int LCM(int a, int b)
{
    int greater = max(a, b);
    int smallest = min(a, b);
    for (int i = greater; ; i += greater) {
        if (i % smallest  == 0)
            return i;
    }
}
long long gcd(long long int a, long long int b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

class Solution {
public:
    string fractionAddition(string expression) 
    {
        vector<int> numerator;
        vector<int> denomenator;
        vector<char> sign;
        int i=0;

        if(expression[0]=='-')
        {
            sign.push_back('-');
            i++;
        }
        else
        {
            sign.push_back('+');
        }

        for(i;i<expression.size();i++)
        {
            numerator.push_back(expression[i]-'0');
            
            if(expression[i+1]!='/')
            {
                numerator[numerator.size()-1]=10;
                i++;
            }
            i+=2;
            denomenator.push_back(expression[i]-'0');
            
            if(i+1<expression.size() && expression[i+1]!='+' && expression[i+1]!='-')
            {
                denomenator[denomenator.size()-1]=10;
                i++;
            }
            i++;
            if(i<expression.size()) sign.push_back(expression[i]);
        }

        if(numerator.size()==1) return expression;

        int dmax=denomenator[0];

        for(int j : denomenator)
        {
            dmax=LCM(dmax,j);
        }

        for(int j = 0 ; j < denomenator.size();j++)
        {
            numerator[j]*=dmax/denomenator[j];
        }

        if(sign[0]=='-') numerator[0]*=-1;

        int k = 1;
        int a=0;

        for(int j = 0 ; j < numerator.size()-1 ; j++)
        {
            if(sign[k]=='-')    a=numerator[j]-numerator[j+1];
            else a=numerator[j]+numerator[j+1];
            k++;
            numerator[j+1]=a;
        }


        string result="";

        if(a<0)
        {
            result+='-';
            a*=-1;
        }

        int temp = gcd(a,dmax);
        a=a/temp;
        dmax=dmax/temp;

        string temps="";
        while(a>9)
        {
            int t =a%10;
            temps+=t+'0';
            a/=10;
        }
        if(a!=0) result+=a+'0';
        else result+='0';
        reverse(temps.begin(),temps.end());
        result+=temps;

        result+='/';

        temps="";
        while(dmax>9)
        {
            int t =dmax%10;
            temps+=t+'0';
            dmax/=10;
        }
        result+=dmax+'0';
        reverse(temps.begin(),temps.end());
        result+=temps;

        return result;
    
    }
};

// other way
#include <string>
#include <vector>
class Solution {
public:
    string fractionAddition(string expression) {
        int numerator = 0, denominator = 1;
        int i = 0, n = expression.size();

        while (i < n) {
            int sign = 1;
            if (expression[i] == '+' || expression[i] == '-') {
                if (expression[i] == '-') sign = -1;
                i++;
            }

            int num = 0;
            while (i < n && isdigit(expression[i])) {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            num *= sign;

            i++;

            int den = 0;
            while (i < n && isdigit(expression[i])) {
                den = den * 10 + (expression[i] - '0');
                i++;
            }

            numerator = numerator * den + num * denominator;
            denominator *= den;

            int gcdVal = gcd(abs(numerator), denominator);
            numerator /= gcdVal;
            denominator /= gcdVal;
        }

        return to_string(numerator) + "/" + to_string(denominator);
    }
};
