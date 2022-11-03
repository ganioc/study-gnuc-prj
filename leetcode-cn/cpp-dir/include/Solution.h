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
    int maxProfit(vector<int>& prices);
};
