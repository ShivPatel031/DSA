// Add Strings leetCode 415

// Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.

// You must solve the problem without using any built-in library for handling large integers (such as BigInteger). You must also not convert the inputs to integers directly.

// Example 1:

// Input: num1 = "11", num2 = "123"
// Output: "134"
  
// Example 2:

// Input: num1 = "456", num2 = "77"
// Output: "533"
  
// Example 3:

// Input: num1 = "0", num2 = "0"
// Output: "0"

string addStrings(string num1, string num2) 
    {

        string ans;

        if (num1.size() < num2.size()) 
        {   
            string temp=num1;
            num1=num2;
            num2=temp;  
        }

        int carry = 0;
        int j=num2.size()-1;

        for (int i = num1.size()-1;i>=0;i--) 
        {
            if (j>=0) 
            {
                int sum = 0;

                if(carry)
                {
                    sum++;
                    carry--;
                }

                sum += (num1[i] - '0') + (num2[j] - '0');

                if (sum > 9)
                {
                    carry++;
                    sum = sum % 10;
                }

                ans += sum + '0';
                j--;
            }
            else
            {
                if(carry)
                {
                    int sum=(num1[i]-'0')+1;;
                    carry--;

                    if (sum > 9)
                    {
                        carry++;
                        sum = sum % 10;
                    }

                    ans += sum + '0';
                }
                else
                {
                    ans+=num1[i];
                }
                
            }

        }

        if(carry)
        {
            ans.push_back('1');
        }

        for (int i = 0; i < ans.size() / 2; i++) 
        {
            swap(ans[i], ans[ans.size() - 1 - i]);
        }

        return ans;
    }
