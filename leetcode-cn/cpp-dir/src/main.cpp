#include <iostream>

#include "../include/Solution.h"

using namespace std;

int main(){
    cout << "hello cpp" << endl;
    cout << "Test remove duplicates" << endl;
    vector<int> arr = {1,2,2,3,4,4,4,5,5};
    Solution *solution = new Solution();

    int n = solution->removeDuplicates(arr);

    for (int i =0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    // prices,
    cout << "Test profits --> " << endl;
    vector<int> prices = {1,2,3,4,5};
    int profit = solution->maxProfit(prices);
    cout << "profit: " << profit << endl;
    
    return 0;
}
