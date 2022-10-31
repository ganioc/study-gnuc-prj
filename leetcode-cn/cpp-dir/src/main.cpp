#include <iostream>

#include "../include/Solution.h"

using namespace std;

int main(){
    cout << "hello cpp" << endl;
    cout << "Test remove duplicates" <<endl;
    vector<int> arr = {1,2,2,3,4,4,4,5,5};
    Solution *solution = new Solution();

    int n = solution->removeDuplicates(arr);

    for (int i =0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}
