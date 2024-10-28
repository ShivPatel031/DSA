// Best Time to Buy and Sell Stock leetcode 121

// What i thought
int maxProfit(vector<int>& prices) 
{
    int min=INT_MAX,max=INT_MIN,ans;

    for(int i = 0 ; i < prices.size();i++)
    {
        if(min>=prices[i])
        {
            min=prices[i];
            max=min;
        }
        else if(max<prices[i])
        {
            max=prices[i];
        }

        if(ans<max-min) ans=max-min;
    }   

    return ans;
}

// Other solution
int maxProfit(vector<int>& prices) 
{
    int buyPrice = prices[0];
    int profit = 0;

    for (int i = 1; i < prices.size(); i++) 
    {
        if (buyPrice > prices[i]) 
        {
            buyPrice = prices[i];
        }

        profit = max(profit, prices[i] - buyPrice);
    }

    return profit;        
}
