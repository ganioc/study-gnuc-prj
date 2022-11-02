#pragma once
#include <vector>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        cout << "removeDuplicates -->" << endl;
        int n = nums.size();

        if(n == 0 || n == 1){
            return n;
        }
        // To store index of next unique element
        int j = 0;

        // Just maintaining another updated index i.e. j
        for (int i=0; i< n-1; i++){
            if(nums[i] != nums[i+1]){
                nums[j++] = nums[i];
            }
        }
        nums[j++] = nums[n - 1];

        return j;
    }
    // return total profits
    int maxProfit(vector<int>& prices){
        int total_profits = 0;
        int n = prices.size();
        int start_index = 0, end_index = 0;
        for(int i=1; i< n-1; i++){
            if(prices[i]>prices[start_index] && prices[i] >= prices[i+1]){
                total_profits += prices[i] - prices[start_index];
                start_index = i;
            }else if(prices[i] <= prices[start_index]){
                start_index = i;
            }
        }
        return total_profits;

    }
};
