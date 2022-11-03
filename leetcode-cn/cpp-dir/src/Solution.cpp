#include <iostream>

#include "Solution.h"

using namespace std;

int Solution::maxProfit(vector<int> &prices)
{
    int total_profits = 0;
    int n = prices.size();
    int start_index = 0, end_index = 0;
    for (int i = 1; i < n-1; i++)
    {
        if (prices[i] > prices[start_index] && prices[i] >= prices[i + 1])
        {
            total_profits += prices[i] - prices[start_index];
            start_index = i;
        }
        else if (prices[i] <= prices[start_index])
        {
            start_index = i;
        }
    }
    if(prices[n-1]> prices[start_index]){
        total_profits += prices[n-1] - prices[start_index];
    }
    return total_profits;
}